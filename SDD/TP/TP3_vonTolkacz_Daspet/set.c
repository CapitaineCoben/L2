#include "set.h"

SET setVide()
{
  SET set;
  set = malloc(sizeof(struct Set));
  if(set== NULL)
  {
    fprintf(stderr,"Allocation impossible \n");
    exit(EXIT_FAILURE);
  }else
  	{
  		set->longeur = 0;
  			for(i=0;  i<=MaxSize-1;  i++)   p-> sonCoefficient[i] = 0;
  	}
  return p;
}

SET ajouterSet(int Elem,SET s)
{
  nouv=malloc(sizeof(SET));
  nouv->elt=e;
  nouv->suiv=x;
  return;
}

SET enleverSet(int e, SET s)
{
	if (s->elt==e)
		return s->suiv;
	set ptr=s;
	while (ptr->suiv!=NULL){
		if(ptr->suiv->elt==e)
		{
			ptr->suiv = ptr-> suiv->suiv;
		}else
			ptr=ptr->suiv;
	return s;
	}

int appartient(SET)
{

}

int estVide(SET)
{
  return ()(SET->longueur)==0);
}

int main()
{

}
