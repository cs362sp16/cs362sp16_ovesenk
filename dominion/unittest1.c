#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helpers.h"

int main() {
  printf("Running unit test for function \"getCost()\"...\n");

  int cost_list[] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4, -1};
  int bad_list[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  assertTrue(getCost(0) == cost_list[0], "getCost(0) == cost_list[0]");
  assertTrue(getCost(1) == cost_list[1], "getCost(0) == cost_list[1]");
  assertTrue(getCost(2) == cost_list[2], "getCost(0) == cost_list[2]");
  assertTrue(getCost(3) == cost_list[3], "getCost(0) == cost_list[3]");
  assertTrue(getCost(4) == cost_list[4], "getCost(0) == cost_list[4]");
  assertTrue(getCost(5) == cost_list[5], "getCost(0) == cost_list[5]");
  assertTrue(getCost(6) == cost_list[6], "getCost(0) == cost_list[6]");
  assertTrue(getCost(7) == cost_list[7], "getCost(0) == cost_list[7]");
  assertTrue(getCost(8) == cost_list[8], "getCost(0) == cost_list[8]");
  assertTrue(getCost(9) == cost_list[9], "getCost(0) == cost_list[9]");
  assertTrue(getCost(10) == cost_list[10], "getCost(0) == cost_list[10]");
  assertTrue(getCost(11) == cost_list[11], "getCost(0) == cost_list[11]");
  assertTrue(getCost(12) == cost_list[12], "getCost(0) == cost_list[12]");
  assertTrue(getCost(13) == cost_list[13], "getCost(0) == cost_list[13]");
  assertTrue(getCost(14) == cost_list[14], "getCost(0) == cost_list[14]");
  assertTrue(getCost(15) == cost_list[15], "getCost(0) == cost_list[15]");
  assertTrue(getCost(16) == cost_list[16], "getCost(0) == cost_list[16]");
  assertTrue(getCost(17) == cost_list[17], "getCost(0) == cost_list[17]");
  assertTrue(getCost(18) == cost_list[18], "getCost(0) == cost_list[18");
  assertTrue(getCost(19) == cost_list[19], "getCost(0) == cost_list[19]");
  assertTrue(getCost(20) == cost_list[20], "getCost(0) == cost_list[20]");
  assertTrue(getCost(21) == cost_list[21], "getCost(0) == cost_list[21]");
  assertTrue(getCost(22) == cost_list[22], "getCost(0) == cost_list[22]");
  assertTrue(getCost(23) == cost_list[23], "getCost(0) == cost_list[23]");
  assertTrue(getCost(24) == cost_list[24], "getCost(0) == cost_list[24]");
  assertTrue(getCost(25) == cost_list[25], "getCost(0) == cost_list[25]");
  assertTrue(getCost(26) == cost_list[26], "getCost(0) == cost_list[26]");

  assertTrue(getCost(0) != bad_list[0], "getCost(0) == bad_list[0]");
  assertTrue(getCost(1) != bad_list[1], "getCost(0) == bad_list[1]");
  assertTrue(getCost(2) != bad_list[2], "getCost(0) == bad_list[2]");
  assertTrue(getCost(3) != bad_list[3], "getCost(0) == bad_list[3]");
  assertTrue(getCost(4) != bad_list[4], "getCost(0) == bad_list[4]");
  assertTrue(getCost(5) != bad_list[5], "getCost(0) == bad_list[5]");
  assertTrue(getCost(6) != bad_list[6], "getCost(0) == bad_list[6]");
  assertTrue(getCost(7) != bad_list[7], "getCost(0) == bad_list[7]");
  assertTrue(getCost(8) != bad_list[8], "getCost(0) == bad_list[8]");
  assertTrue(getCost(9) != bad_list[9], "getCost(0) == bad_list[9]");
  assertTrue(getCost(10) != bad_list[10], "getCost(0) == bad_list[10]");
  assertTrue(getCost(11) != bad_list[11], "getCost(0) == bad_list[11]");
  assertTrue(getCost(12) != bad_list[12], "getCost(0) == bad_list[12]");
  assertTrue(getCost(13) != bad_list[13], "getCost(0) == bad_list[13]");
  assertTrue(getCost(14) != bad_list[14], "getCost(0) == bad_list[14]");
  assertTrue(getCost(15) != bad_list[15], "getCost(0) == bad_list[15]");
  assertTrue(getCost(16) != bad_list[16], "getCost(0) == bad_list[16]");
  assertTrue(getCost(17) != bad_list[17], "getCost(0) == bad_list[17]");
  assertTrue(getCost(18) != bad_list[18], "getCost(0) == bad_list[18]");
  assertTrue(getCost(19) != bad_list[19], "getCost(0) == bad_list[19]");
  assertTrue(getCost(20) != bad_list[20], "getCost(0) == bad_list[20]");
  assertTrue(getCost(21) != bad_list[21], "getCost(0) == bad_list[21]");
  assertTrue(getCost(22) != bad_list[22], "getCost(0) == bad_list[22]");
  assertTrue(getCost(23) != bad_list[23], "getCost(0) == bad_list[23]");
  assertTrue(getCost(24) != bad_list[24], "getCost(0) == bad_list[24]");
  assertTrue(getCost(25) != bad_list[25], "getCost(0) == bad_list[25]");
  assertTrue(getCost(26) != bad_list[26], "getCost(0) == bad_list[26]");

  return 0;
}
