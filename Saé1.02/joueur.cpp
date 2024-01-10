/**
 * @file joueur.cpp
 * @author Ethan LEGRAND 104
 * @version 1 01/01/2024
 * @brief Projet S1.02 - Lexicon
 */
#include "Joueur.h"

#include <iostream>

using namespace std;

void distribuer(Joueur* tj, int nbj, Pile& p) {
	for (int i = 0; i < nbj; i++) {
		for (int j = 0; j < nbcartes; j++) {
			tj[i].main[j] = sommet(p);
			cout << tj[i].main[j];
			depiler(p);
		}
		cout << endl;
	}
	cout << endl;
	
}

void affichermain(const Joueur tj[], int i) {
	int max = nbcartesmain(tj, i);
	int j = 0;
	
	while(max>0) {
		char lettre = tj[i].main[j];
		if (lettre != 0) {
			cout << lettre;
			
			max--;
		}
		j++;
	}
	cout << endl;
}

int nbcartesmain(const Joueur tj[], int i) {
	int nb = 0;
	for (int j = 0; j < nbcartes; j++) {
		if (tj[i].main[j] != 0) nb++;
	}
	return nb;
}

bool iswinner(const Joueur tj[], int i) {
	if (nbcartesmain(tj, i) == 0) return true;
	else return false;
}
int iscarte(Joueur tj[], int i, char lettre) {
	int max = nbcartesmain(tj, i);
	int j = 0;

	while (max > 0) {
		char a = tj[i].main[j];
		if (a != 0) {
			if (a == lettre) {
				return j;
			}
			max--;

		}
		j++;
	}
	return -1;
}

void enlevercarte(Joueur tj[], int i, char lettre,int placement) {
	tj[i].main[placement] = 0;

}

void ajoutercarte(Joueur tj[], int i, char carte) {
	int j = 0;
	while (j<nbcartes) {
		char emplacement = tj[i].main[j];
		if (emplacement == 0) {
			tj[i].main[j] = carte;
			return;
		}
		j++;
	}
}

