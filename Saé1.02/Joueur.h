#ifndef _JOUEUR_
#define _JOUEUR_


/**
 * @file Joueur.h
 * @author Ethan LEGRAND 104
 * @version 1 01/01/2024
 * @brief Projet S1.02 - Lexicon
 */

#include "Pile.h"
const char nbcartes = 10;

struct Joueur {
	char main[nbcartes];
	unsigned int points;
};

void distribuer(Joueur* tj, int nbj, Pile& p);

void affichermain(const Joueur tj[], int i);

int nbcartesmain(const Joueur tj[], int i);

bool iswinner(const Joueur tj[], int i);

int iscarte(Joueur tj[], int i, char lettre);

void enlevercarte(Joueur tj[], int i, char lettre,int placement);

void ajoutercarte(Joueur tj[], int i, char carte);

#endif