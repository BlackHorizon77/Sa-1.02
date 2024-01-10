/**
 * @file Lexicon.cpp
 * @author Ethan LEGRAND 104
 * @version 1 18/12/2023
 * @brief Projet S1.02 - Lexicon
 */

#include <iostream> 
#include <ctime>

#include "Jeu.h"
#include "Mot.h"
#include "Joueur.h"
#include "Dico.h"
#include "Pile.h"
#include "Pioche.h"
using namespace std;


int main() {
	/*
	* while (true) {
		bool ui = verification();
		if (ui)cout << "ui" << endl;
	}
	*/
	int nbjoueurs = 2;
	ConteneurTDE conteneur;
	Pile p;
	Pile exp;
	Mot mot;
	initialiser(conteneur, 2, 2);
	initialiser(exp,nbcartesdeck);
	creer(p);
	Joueur* tJoueurs = new Joueur[nbjoueurs];
	for (int i = 0; i < nbjoueurs; i++) {
		tJoueurs[i].points = 0;
	}
	distribuer(tJoueurs, nbjoueurs, p);
	affichermain(tJoueurs, 0);
	affichermain(tJoueurs, 1);
	int actJoueur = 0;
	empiler(exp, sommet(p));
	depiler(p);
	while (!iswinner(tJoueurs, actJoueur)) {
		int nbmots = 0;
		if (tJoueurs[actJoueur].points < 100) {
			cout << "* Joueur " << actJoueur + 1 << " (" << sommet(exp) << ") ";
			affichermain(tJoueurs, actJoueur);
			char commande;
			cin >> commande;
			bool reussitecommande;
			switch (commande) {
			case 'T' : 
				reussitecommande = cTalon(tJoueurs, actJoueur, p, exp);
				break;
			case 'E':
				reussitecommande = cExpose(tJoueurs, actJoueur, exp);
				break;
			case 'P':
				reussitecommande = cPoser(tJoueurs, actJoueur, conteneur, nbmots, s());
				break;
			}
			
			if (reussitecommande) actJoueur++;
			if (actJoueur >= nbjoueurs) actJoueur = 0;
		}
		
	}


	
	delete[] tJoueurs;
	detruire(conteneur);
	detruire(p);
	detruire(exp);
}
