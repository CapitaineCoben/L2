#include "liste.h"

LISTE listeVide(){
	int i;
	LISTE l=malloc(sizeof(struct liste));
	if(l== NULL)
	{
		fprintf(stderr,"Allocation impossible \n");
		exit(EXIT_FAILURE);
	}
	else
	{
		l->longueur = 0;
			for(i=0;  i<MaxSize;  i++)   l-> tab[i] = 0;
	}
	return l;
	}

int EstVide(LISTE l)
	{
	return ((l->longueur)==0);
	}


LISTE consListe(int Elem,LISTE l){
	l->tab[l->longueur]=Elem;
	l->longueur = l->longueur+1;
	return l;
	}

LISTE finListe(LISTE l)
{
	for (int i=0;i<l->longueur-1;i++){
		l->tab[i]=l->tab[i+1];
	}
	l->longueur =l->longueur-1;
	return l;
}
float tete(LISTE l)
{
	return ((l->tab[0]));
}

int taille(LISTE l)
{
	return (l->longueur);
}
/*
int main(){
	LISTE liste=listeVide();
consListe(7,liste);

	printf("%lf\n",tete(liste) );
	printf("%d\n", liste->longueur);
	liste = finListe(liste);
		printf("%d\n", liste->longueur);
	for (int i=0; i<liste->longueur;i++) {
		printf("%lf\n",liste->tab[i] );
	}
	printf("%d\n",taille(liste) );
	return 0;
}*/
//par rapport au tp3: set (ensemble) un ele appartient ou pas a l'ensemble et si il apparait c'est que une fois au max mais si l'ele qui fait partie de l'ensemble apparait plus de une fois on obtient un bag
