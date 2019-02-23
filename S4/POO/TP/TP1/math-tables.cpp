#include <cstdio>

int carMax(int tab[100][100],int colones, int lignes){
  int val=0,counter=0;
  for (int i = 0; i <= colones; i++) {
    for (int j = 0; j <= lignes; j++) {
      if (tab[i][j] > val) {
        val = tab[i][j];
      }
    }
  }
  while (val != 0) {
    counter += 1;
    val = val/10;
  }
  printf("%d\n",counter);
  return val;
}
int main(int argc, char const *argv[]) {
  char op;
  int lignes,colones,nbCar;
  int tab[100][100];
  do
  {	printf("entrez un opérateur\n");
    scanf("%c",&op);
  }while(op != '+' and op != '-' and op != '*' and op != '/' and op != '%');
  do
  {	printf("entrez un nombre de lignes\n");
    scanf("%d",&lignes);
  }while(lignes <= 0);
  do
  {	printf("entrez un nombre de colones\n");
    scanf("%d",&colones);
  }while(colones <= 0);
  for (int i = 0; i < colones+1; i++) {
    tab[0][i+1] = i;
  }
  for (int i = 0; i < lignes+1; i++) {
    tab[i+1][0] = i;
  }
  for (int i = 1; i < colones+1; i++) {
    for (int j = 1; j < lignes+1; j++) {
      switch (op) {
        case '*': tab[i][j] = (i-1)*(j-1); break;
        case '+': tab[i][j] = (i-1)+(j-1); break;
        case '-': tab[i][j] = (i-1)-(j-1); break;
        case '/': tab[i][j] = (i-1)/(j-1); break;
        case '%': tab[i][j] = (i-1)/(j-1); break;
        default : break;
      }
    }
  }
  nbCar=carMax(tab,colones,lignes);
  printf("nbCar%d\n",nbCar);
  printf("%c |", op);
  for (int i = 1; i < colones+1; i++) {
    printf("%d",tab[i][0]);
  }
  printf("\n");
  for (int i = 1; i < colones+1; i++) {
    printf("%d |",tab[0][i]);
  }
  printf("\n");
  for (int i = 1; i < colones+1; i++) {
    for (int j = 1; j < lignes+1; j++) {
      printf("%d", tab[i][j]);
    }
    printf("\n");
  }

  return 0;
}
