/**
 * @file jeu.cpp
 * @author Ethan LEGRAND 104
 * @version 1 07/01/2024
 * @brief Projet S1.02 - Lexicon
 */

#include "Jeu.h"
#include "Mot.h"
#include "Dico.h"
#include <iostream>

using namespace std;

bool cTalon(Joueur tj[], int i,Pile& p, Pile& exp) {
	char lettre;
	cin >> lettre;
	int placement = iscarte(tj, i, lettre);
	if (placement == -1) {
		cout << "Coup invalide, recommencez" << endl;
		return false;
	}
	empiler(exp, lettre);
	enlevercarte(tj, i, lettre,placement);
	ajoutercarte(tj, i, sommet(p));
	depiler(p);


	
	return true;
}
bool cExpose(Joueur tj[], int i, Pile& exp) {
	char lettre;
	cin >> lettre;
	int placement = iscarte(tj, i, lettre);
	if (placement == -1) {
		cout << "Coup invalide, recommencez" << endl;
		return false;
	}
	enlevercarte(tj, i, lettre, placement);
	ajoutercarte(tj, i, sommet(exp));
	empiler(exp, lettre);
	



	return true;
}

bool cPoser(Joueur tj[], int i,ConteneurTDE& c, int nbmots,const Mot& m) {
	
	for (int g = 0; g < m.taille; g++) {
		if (iscarte(tj, i, m.mot[g]) == -1) {
			cout << "Coup invalide, recommencez" << endl;
			return false;
		}
	}
	if (verification(m.mot)) {
		ecrire(c, nbmots, m);
		return true;
	}
	else {
		cout << "Mot invalide, vous passez votre tour" << endl;
		tj[i].points = +3;
		return true;
	}
	
}
