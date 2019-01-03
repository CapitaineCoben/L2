#include <stdio.h>
#include <stdlib.h>
#include "liste.c"

int main(int argc, char *argv[])
{
	LISTE   l;
	int i, succes, elem;

/* Allocation mémoire et vérification  */
l  = malloc( sizeof( struct liste) );
if( l == NULL)
{
	printf("Allocation imlossible \n");
	exit(EXIT_FAILURE);
};

/* Initialiser l'indice succes*/
succes= 1;

/* Vérifier l’Implémentation du constructeur listeVide()*/
l = listeVide() ;

if(l->longueur != 0) succes = 0;
for(i=0;  i<MaxSize;  i++)   if(l->tab[i] != 0) succes = 0;

/* Bilan de la vérification */
if (succes!=1)
{
	printf ("\n Implémentation incorrecte du constructeur listeVide()\n");
	printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
	exit(EXIT_FAILURE);
};

/* réinitialiser l'indice succes*/
succes= 1;

/* Vérification du constructeur EstVide*/
if (!EstVide(l))    succes = 0;

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

/* Vérification avec l’accesseur consListe*/
l = consListe(elem,l);

if (EstVide(l))		succes = 0;
if(l->tab[l->longueur-1] != elem) 	succes = 0;

/* Bilan de la vérification */
	if (succes!=1)
	{
		printf ("\n Implémentation incorrecte de l'accesseur consListe()\n");
		printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
		exit(EXIT_FAILURE);
	};

/* réinitialiser l'indice succes*/
succes = 1;

/* Vérification avec l’accesseur tete*/
if (tete(l) != elem) succes = 0;

/* Bilan de la vérification */
if (succes!=1)
{
	printf ("\n Implémentation incorrecte de l'accesseur tete()\n");
	printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
	exit(EXIT_FAILURE);
};

/* réinitialiser l'indice succes*/
succes = 1;

/* Vérification avec l’accesseur taille*/
if (taille(l) != l->longueur) succes = 0;

/* Bilan de la vérification */
if (succes!=1)
{
	printf ("\n Implémentation incorrecte de l'accesseur taille()\n");
	printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
	exit(EXIT_FAILURE);
};

/* réinitialiser l'indice succes*/
succes = 1;

/* Vérification avec l’accesseur finListe*/
l = finListe(l);
if (!EstVide(l)) succes = 0;

/* Bilan de la vérification */
if (succes!=1)
{
	printf ("\n Imppémentation incorrecte de l'accesseur finListe()\n");
	printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
	exit(EXIT_FAILURE);
};

printf("L'implementation du type abstrait est vérifiée\n");
printf("Fin normale de la vérification de l'implémentation du type abstrait\n");
return EXIT_SUCCESS;
}
