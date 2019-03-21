#include <cstdio>

struct maison{
  int surface;
  maison(){
    
  }
  maison(int a){
    this->surface = a;
  }
};

int main(int argc, char const *argv[]) {
  maison a(5);
  maison tab[10];
  tab[5] = a;
  return 0;
}
