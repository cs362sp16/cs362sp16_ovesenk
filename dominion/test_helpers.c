#include <stdio.h>
#include "test_helpers.h"

int assertTrue(int value, char* string) {
  if(1 == value) {
    printf("TEST SUCCESSFULLY COMPLETED: %s\n", string);
    return 1;
  }
  printf("TEST FAILED:                 %s\n", string);
  return 0;
}
