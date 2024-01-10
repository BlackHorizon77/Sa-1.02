#ifndef _PIOCHE_
#define _PIOCHE_

/**
 * @file Pioche.h
 * @author Ethan LEGRAND 104
 * @version 1 18/12/2023
 * @brief Projet S1.02 - Lexicon
 */

#include <ctime>

#include "Joueur.h"
#include "Pile.h"

enum { nbcartesdeck = 51};
 /**
 * @brief M�langer un tableau
 * @param[in,out] tab[] : le tableau � m�langer
 */
void melanger(char tab[]);

/**
 * @brief Remplit une pile avec un tableau
 * @param[in,out] p : la pile � remplir
 * @param[in] tab[] : le tableau qui rempli la pile
 */
void remplir(Pile& p, char tab[]);

/**
 * @brief Cr�� une pioche m�lang�e
 * @param[in,out] p : la pile
 */
void creer(Pile& p);

#endif