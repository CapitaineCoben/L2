#include <cstdio>
int main(int argc, char const *argv[]) {
  char op;
  int lignes,colones;
  do
  {	printf("entrez un opérateur\n");
    scanf("%c",&op);
  }while(op != '+' and op != '-' and op != '*' and op != '/' and op != '%');
  do
  {	printf("entrez un nombre de lignes\n");
    scanf("%d",&lignes);
  }while(lignes < 0);
  do
  {	printf("entrez un nombre de colones\n");
    scanf("%d",&colones);
  }while(colones < 0);
  printf("%c |", op);
  for (int i = 0; i < colones; i++) {
    printf("%d  ", i);
  }
  return 0;
}
