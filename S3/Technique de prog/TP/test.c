#include <stdio.h>
#include "stdlib.h"

int main(int argc, char const *argv[]) {
  char * var[10];
  var[0] = "a";
  var[1] = "b";
  printf("%s\n",var[1]);
  return 0;
}
