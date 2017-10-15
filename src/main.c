#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "triParMinSuccessif.h"
#include "triParInsertion.h"
#include "triRapide.h"
#include "triFusion.h"

#define MAX 2147483647

int saisieNbEntiers(long int max) {
	long int resultat;
	do {
		printf("Nb d'entiers : ");
		scanf("%ld", &resultat);
	} while (( resultat<=0 ) || (resultat>MAX));
	return resultat;
}

void remplirAuHasard(long int tab[], long int nbElements) {
	long int i;
	for( i = 0 ; i < nbElements ; i++ ) {
		tab[i] = random()%nbElements;
		/* Pire Situation :
		tab[i]=i;
		*/
	}
}

double benchmarkerUnTri(long int tab[], long int nbElements, void (*trier)(long int*, long int)) {
	/* A completer */
	return 0; /* Devra retourner le temps mis pour trier le tableau */
}

int main(int nbParams, char** params) {
	long int nbEntiers;
	long int *entiers;
	nbEntiers = saisieNbEntiers(MAX);
	entiers = (long int*)malloc(nbEntiers*sizeof(long int));
	printf("Tri Par Minimum Successif : %fs (temps CPU) \n", benchmarkerUnTri(entiers, nbEntiers, trierEntiersParMinSuccessif));
	printf("Tri Par Insertion : %fs (temps CPU) \n", benchmarkerUnTri(entiers, nbEntiers, trierEntiersParInsertion));
	printf("Tri Rapide : %fs (temps CPU) \n", benchmarkerUnTri(entiers, nbEntiers, trierEntiersRapide));
	printf("Tri Par Fusion : %fs (temps CPU) \n", benchmarkerUnTri(entiers, nbEntiers, trierEntiersParFusion));
	free(entiers);
	return EXIT_SUCCES;
}
