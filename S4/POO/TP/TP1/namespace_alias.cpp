#include <cstdio>
namespace poo{
  int var = 1;
  int fct(){return var;}
}
namespace tp1{
  int var2 = 2;
  int fct2(){return var2;}
}
namespace alias = ::poo;
namespace alias2 = ::tp1;
int main(int argc, char const *argv[]) {
  printf("poo::var: %d\n",alias::var);
  printf("poo::fct(): %d\n",alias::fct());
  printf("poo::var: %d\n",alias2::var2);
  printf("poo::fct(): %d\n",alias2::fct2());
  return 0;
}
