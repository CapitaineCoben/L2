#include "set.h"

Set setVide()
{
    Set set = NULL;

    return set;
}

int estVide(Set set)
{
    return (set == NULL);
}

int appartient(Set set, float x)
{
    Element* aux;
    aux = set;
    while ((aux != NULL) && (aux->value != x)) {
        aux = aux->next;
    }
    return (aux != NULL);
}

void ajouter(Set* set, float x)
{
    Element* aux;
    aux = malloc(sizeof(Element));
    aux->value = x;
    aux->next = *set;

    *set = aux;
}

void enlever(Set* set, float x)
{
    Element* aux;

    if ((*set)->value == x) {
        aux = (*set)->next;

        free(*set);
        *set = aux;
    }

    else {
        while (((*set)->next)->value != x) {
            *set = (*set)->next;
        }

        aux = (*set)->next;
        (*set)->next = aux->next;
        free(aux);
    }
}
