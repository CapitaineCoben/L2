#include <stdio.h>
#include <stdlib.h>
#include "set.c"

int main(int argc, char *argv[])
{
	Set   set;
	int i, succes;
  float elem;

/* Allocation mémoire et vérification  */
set = setVide();

succes= 1;

/* Vérification du constructeur EstVide*/
if (!estVide(set))    succes = 0;

/* Bilan de la vérification */
if (succes!=1)
{
	printf ("\n Implémentation incorrecte de l'accesseur EstVide()\n");
	printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
	exit(EXIT_FAILURE);
};

/* réinitialiser l'indice succes*/
succes = 1;

/* Initialiser la variable elem*/
elem = 1;
if (appartient(set,elem)) {
  succes = 0;
}

if (succes!=1)
{
  printf ("\n Implémentation incorrecte de l'accesseur appartient()\n");
  printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
  exit(EXIT_FAILURE);
};

/* réinitialiser l'indice succes*/
succes = 1;

/* Vérification avec l’accesseur ajouter*/
if(!appartient(set, elem)) {
    ajouter(&set, elem);
}
if(!appartient(set, elem)) {
  succes = 0;
}
/* Bilan de la vérification */
	if (succes!=1)
	{
		printf ("\n Implémentation incorrecte de l'accesseur ajouter()\n");
		printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
		exit(EXIT_FAILURE);
	};

/* réinitialiser l'indice succes*/
succes = 1;

/* Vérification avec l’accesseur tete*/
if(appartient(set, elem)) {
    enlever(&set, elem);
}
if(appartient(set, elem)) {
  succes = 0;
}
/* Bilan de la vérification */
if (succes!=1)
{
	printf ("\n Implémentation incorrecte de l'accesseur enlever()\n");
	printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
	exit(EXIT_FAILURE);
};


printf("L'implementation du type abstrait est vérifiée\n");
printf("Fin normale de la vérification de l'implémentation du type abstrait\n");
return EXIT_SUCCESS;
}
