#include <stdlib.h>
#include <stdio.h>
#include "pile.h"

Pile* fcnt_initialiser()
{
	Pile *pile = malloc(sizeof(pile));
	Matricule *matricule = malloc(sizeof(matricule));
	if (pile == NULL || matricule == NULL)
		exit(EXIT_FAILURE);
	matricule->membre = 0;
	matricule->suivant = NULL;
	pile->premier = matricule;

	return pile;
}

void fcnt_ajouter(Pile *pile, long nouveauMatricule)
{
	Matricule *nouveau = malloc(sizeof(nouveau));
	if (pile == NULL || nouveau == NULL)
		exit(EXIT_FAILURE);
	nouveau->membre = nouveauMatricule;
	nouveau->suivant = pile->premier;
	pile->premier = nouveau;
}

long fcnt_supprimer(Pile *pile)
{
	if (pile == NULL)
		exit(EXIT_FAILURE);
	long membreActuel = 0;
	Matricule *pileMembre = pile->premier;
	if (pile != NULL && pile->premier != NULL)
	{
		membreActuel = pileMembre->membre;
		pile->premier = pileMembre->suivant;
		free(pileMembre);
	}
	return membreActuel;
}

void fcnt_afficher(Pile *pile)
{
	if (pile == NULL)
		exit(EXIT_FAILURE);
	Matricule *actuel = pile->premier;
	while(actuel != NULL){
		printf("%ld\n", actuel->membre);
		actuel = actuel->suivant;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	Pile *nouveauPile = fcnt_initialiser();
	while(1){
		printf("\n\n***********GESTION DE PILE************\n");
		printf("Appuyez:\n 1 pour ajouter\n 2 pour supprimer\n 3 pour afficher\n\n");
	int choix;
	long matricule;
	scanf("%d",&choix);
		switch(choix){
		case 1:
			printf("Entrer le numero matricule\n");
			scanf("%ld",&matricule);
			fcnt_ajouter(nouveauPile,matricule);
			break;
		case 2:
			fcnt_supprimer(nouveauPile);
			break;
		case 3:
			fcnt_afficher(nouveauPile);
			break;
		default:
			printf("Appuyez 1 pour ajouter, 2 pour supprimer, 3 pour afficher\n");
			exit(EXIT_FAILURE);
	}
	}
	exit(EXIT_SUCCESS);
}