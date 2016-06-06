#!/usr/bin/env python
#
# Tarantula Fault Localization Tool
# Based on https://github.com/spideruci/Tarantula/blob/master/src/main/java/org/spideruci/tarantula
#

import os
import subprocess as sp
import sys
import re
import pdb

TEST_NUM = 500
lines = []
num_lines = -1
testdom_ret = False
line_num_exp = '\s+[#\-\d]+:\s+(\d+)'
executed_line_exp = '\s+([#\-\d]+)'

def generate_coverage(seed):
  global lines
  global testdom_ret
  # Run tester
  p_test = sp.Popen(['testdominion %d' % (seed + 1)], shell=True, stdout=sp.PIPE, stderr=sp.PIPE)
  p_test.wait()
  # Run gcov
  p_gcov = sp.Popen(['gcov dominion.c'], shell=True, stdout=sp.PIPE, stderr=sp.PIPE)
  p_gcov.wait()
  # Remove gcda file to reset gcov
  p_rm = sp.Popen(['rm dominion.gcda'], shell=True, stdout=sp.PIPE, stderr=sp.PIPE)
  p_rm.wait()

  # Store if test failed
  testdom_ret = p_test.returncode
  # Store gcov lines
  f = open('dominion.c.gcov')
  lines = f.readlines()[5:] # Ignore first four lines because the are info lines
  f.close()

def main():
  # Initialize veriables
  num_lines = sum(1 for line in open('dominion.c'))
  total_num_fail = 0
  total_num_pass = 0
  fail_on_statment = [0] * num_lines
  pass_on_statment = [0] * num_lines
  fail_ratio = [0] * num_lines
  pass_ratio = [0] * num_lines
  suspiciousness = []
  for i in range(num_lines):
    suspiciousness.append(["", 0.0]) #[line number, suspicousness]

  for i in range(TEST_NUM):
    generate_coverage(i)

    # Detemine if test run failed
    if (testdom_ret == 0):
      total_num_pass += 1
    else:
      total_num_fail += 1

    for j in range(num_lines):
      # Detemine if line has been executed
      line_str = str(re.findall(executed_line_exp, lines[j])[0])
      if '-' not in line_str and '#' not in line_str:
        if (testdom_ret == 0):
          pass_on_statment[j] += 1
        else:
          fail_on_statment[j] += 1

      # Calculate pass and fail ratio
      if total_num_pass == 0:
        pass_ratio[j] = 0
      else:
        pass_ratio[j] = pass_on_statment[j]/(total_num_pass * 1.0)

      if total_num_fail == 0:
        fail_ratio[j] = 0
      else:
        fail_ratio[j] = fail_on_statment[j]/(total_num_fail * 1.0)

      # Calculate suspiciousness
      suspiciousness[j][0] = str(re.findall(line_num_exp, lines[j])[0])
      if pass_ratio[j] + fail_ratio[j] != 0:
        suspiciousness[j][1] = fail_ratio[j]/(pass_ratio[j] + fail_ratio[j])

  # Sort the suspiciousness list so the most suspicous is on top
  suspiciousness.sort(key=lambda x: x[1], reverse=True)

  # Print out suspiciousness list
  print 'Line #\t\tSuspiciousness'
  for i in range(len(suspiciousness)):
    print '%s\t\t%s' % (suspiciousness[i][0], suspiciousness[i][1])

if __name__=='__main__':
  main()
