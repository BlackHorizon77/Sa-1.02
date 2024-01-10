/**
 * @file pioche.cpp
 * @author Ethan LEGRAND 104
 * @version 1 18/12/2023
 * @brief Projet S1.02 - Lexicon
 */

#include <ctime>
#include <iostream> 

#include "Pioche.h"




void melanger(char tab[]) {
	srand((unsigned int)time(NULL));
	for (int i = 51; i >= 2; i--) {
		int z = rand() % i;
		int temp = tab[i - 1];
		tab[i - 1] = tab[z];
		tab[z] = temp;
	}
}

void remplir(Pile& p, char tab[]) {
	for (int i = 0; i < strlen(tab); i++) {
		empiler(p, tab[i]);
	}
}
void creer(Pile& p) {
	char deck[] = "AABBCCDDEEEEEFGGHHIIIIJKLLMNNNOOPQRRRSSSTTTUUUVWXYZ";
	melanger(deck);
	initialiser(p, nbcartesdeck);
	remplir(p, deck);
}
