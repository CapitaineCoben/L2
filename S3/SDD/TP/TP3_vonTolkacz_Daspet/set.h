#include <stdio.h>
#include <stdlib.h>

/* Type Concret correspondant à l'implémentation du TAD de Set */
typedef struct elt {
    float value;
    struct elt* next;
} Element;

typedef Element* Set;

/* Créer un Set vide */
Set setVide();
/* Tester si un Set est vide */
int estVide(Set set);
/* Tester si un élément appartient à un Set */
int appartient(Set set, float v);
/* Ajouter un élément */
void ajouter(Set* set, float v);
/* Retirer un élément */
void enlever(Set* set, float v);
