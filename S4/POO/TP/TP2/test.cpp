#include <cstdio>
int main(int argc, char const *argv[]) {
  int a = 10;
  int b = 5;
  printf("!= %d\n",(a|=b));
  printf("^=%d\n",(a^=b));
  return 0;
}
