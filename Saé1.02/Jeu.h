#ifndef _JEU_
#define _JEU_


/**
 * @file Jeu.h
 * @author Ethan LEGRAND 104
 * @version 1 07/01/2024
 * @brief Projet S1.02 - Lexicon
 */

#include "Joueur.h"
#include "Mot.h"

bool cTalon(Joueur tj[], int i, Pile& p,Pile& exp);

bool cExpose(Joueur tj[], int i, Pile& exp);

bool cPoser(Joueur tj[], int i, ConteneurTDE& c, int nbmots, const Mot& m);

#endif