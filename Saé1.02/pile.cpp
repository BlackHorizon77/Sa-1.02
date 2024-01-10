
/**
 * @file pile.cpp
 * @author Ethan LEGRAND 104
 * @version 1 18/12/2023
 * @brief Projet S1.02 - Lexicon
 */

#include <iostream>
#include <cassert>
#include "Pile.h"

using namespace std;

/**
* @brief Initialiser une pile vide
* la pile est allouée en mémoire dynamique
* @see detruire, pour une désallocation en fin d’utilisation
* @param[out] p : la pile à initialiser
* @param[in] c : capacité de la pile (nb maximum d‘items stockés)
* @pre c>0
*/
void initialiser(Pile& p, unsigned int c) {
	assert(c > 0);
	p.capacite = c;
	p.tab = new Item[c];
	p.sommet = -1;
	
}

/**
 * @brief Désallouer une pile
 * @see initialiser, la pile a déjà été initialisée
 * @param[in,out] p : la pile à désallouer
 */
void detruire(Pile& p) {
	delete[] p.tab;
	p.tab = NULL;
}

/**
 * @brief Test de pile pleine
 * @param[in] p : la pile testée
 * @return true si p est pleine, false sinon
 */
bool estPleine(const Pile& p) {
	return (p.sommet == (p.capacite - 1));
}

/**
 * @brief Test de pile vide
 * @param[in] p : la pile testée
 * @return true si p est vide, false sinon
 */
bool estVide(const Pile& p) {
	return (p.sommet == -1);
}

/**
 * @brief Lire l'item au sommet de pile
 * @param[in] p : la pile
 * @return la valeur de l'item au sommet de pile
 * @pre la pile n’est pas vide
 */
Item sommet(const Pile& p) {
	assert(!estVide(p));
	return p.tab[p.sommet];
}

/**
 * @brief Empiler un item sur une pile
 * @param[in,out] p : la pile
 * @param[in] it : l'item à empiler
 * @pre la pile n’est pas pleine
 */
void empiler(Pile& p, const Item& it) {
	if (estPleine(p)) {
		/* Stratégie de réallocation proportionnelle au pas d'extension :
		 * initialisez la nouvelle taille du conteneur (newTaille)
		 * à i * c.pasExtension */
		unsigned int newTaille = p.capacite * p.pas;
		/* Allouez en mémoire dynamique un nouveau tableau (newT)
		 * à cette nouvelle taille*/
		Item* newT = new Item[newTaille];
		/* Recopiez les items déjà stockés dans le conteneur */
		for (unsigned int i = 0; i < p.capacite; ++i)
			newT[i] = p.tab[i];
		/* Désallouez l'ancien tableau support du conteneur */
		delete[] p.tab;
		/* Actualiser la mise à jour du conteneur en mémoire dynamique
		 * Faites pointer le tableau support du conteneur
		 * sur le nouveau tableau en mémoire dynamique */
		p.tab = newT;
		/* Actualisez la taille du conteneur */
		p.capacite = newTaille;
		/* Affichage pour une trace de l'allocation en TP
	* En TP, pour tracer l'extension de l'allocation en mémoire,
	* affichez les informations qui suivent.
	* Cet affichage sera supprimé après le test du conteneur */
		cout << "Extension - Allocaton/Réallocation de " << newTaille * sizeof(Item)
			<< " octets (" << newTaille << " items)." << endl;
	}
	p.sommet++;
	p.tab[p.sommet] = it;
}

/**
 * @brief Dépiler l’item au sommet de pile
 * @param[in,out] p : la pile
 * @pre la pile n’est pas vide
 */
void depiler(Pile& p) {
	assert(!estVide(p));
	p.sommet--;
}
