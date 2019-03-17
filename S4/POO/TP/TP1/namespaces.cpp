#include <cstdio>
namespace poo{
  int var = 1;
  int fct(){return var;}
}
namespace tp1{
  int var2 = 2;
  int fct2(){return var2;}
}
using namespace poo;
using namespace tp1;
int main(int argc, char const *argv[]) {
  printf("poo::var: %d\n",var);
  printf("poo::fct(): %d\n",fct());
  printf("poo::var: %d\n",var2);
  printf("poo::fct(): %d\n",fct2());
  return 0;
}
