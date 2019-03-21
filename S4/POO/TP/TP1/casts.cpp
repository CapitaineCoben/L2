#include <cstdio>
int main(int argc, char const *argv[]) {
  printf("cast: %d\n",(int) 42l);
  printf("cast (functional notation): %d\n",int(42l) );
  printf("static cast: %d\n",static_cast <int> (42l));
  return 0;
}
