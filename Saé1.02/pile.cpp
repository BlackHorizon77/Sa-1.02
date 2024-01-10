
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
* la pile est allou�e en m�moire dynamique
* @see detruire, pour une d�sallocation en fin d�utilisation
* @param[out] p : la pile � initialiser
* @param[in] c : capacit� de la pile (nb maximum d�items stock�s)
* @pre c>0
*/
void initialiser(Pile& p, unsigned int c) {
	assert(c > 0);
	p.capacite = c;
	p.tab = new Item[c];
	p.sommet = -1;
	
}

/**
 * @brief D�sallouer une pile
 * @see initialiser, la pile a d�j� �t� initialis�e
 * @param[in,out] p : la pile � d�sallouer
 */
void detruire(Pile& p) {
	delete[] p.tab;
	p.tab = NULL;
}

/**
 * @brief Test de pile pleine
 * @param[in] p : la pile test�e
 * @return true si p est pleine, false sinon
 */
bool estPleine(const Pile& p) {
	return (p.sommet == (p.capacite - 1));
}

/**
 * @brief Test de pile vide
 * @param[in] p : la pile test�e
 * @return true si p est vide, false sinon
 */
bool estVide(const Pile& p) {
	return (p.sommet == -1);
}

/**
 * @brief Lire l'item au sommet de pile
 * @param[in] p : la pile
 * @return la valeur de l'item au sommet de pile
 * @pre la pile n�est pas vide
 */
Item sommet(const Pile& p) {
	assert(!estVide(p));
	return p.tab[p.sommet];
}

/**
 * @brief Empiler un item sur une pile
 * @param[in,out] p : la pile
 * @param[in] it : l'item � empiler
 * @pre la pile n�est pas pleine
 */
void empiler(Pile& p, const Item& it) {
	if (estPleine(p)) {
		/* Strat�gie de r�allocation proportionnelle au pas d'extension :
		 * initialisez la nouvelle taille du conteneur (newTaille)
		 * � i * c.pasExtension */
		unsigned int newTaille = p.capacite * p.pas;
		/* Allouez en m�moire dynamique un nouveau tableau (newT)
		 * � cette nouvelle taille*/
		Item* newT = new Item[newTaille];
		/* Recopiez les items d�j� stock�s dans le conteneur */
		for (unsigned int i = 0; i < p.capacite; ++i)
			newT[i] = p.tab[i];
		/* D�sallouez l'ancien tableau support du conteneur */
		delete[] p.tab;
		/* Actualiser la mise � jour du conteneur en m�moire dynamique
		 * Faites pointer le tableau support du conteneur
		 * sur le nouveau tableau en m�moire dynamique */
		p.tab = newT;
		/* Actualisez la taille du conteneur */
		p.capacite = newTaille;
		/* Affichage pour une trace de l'allocation en TP
	* En TP, pour tracer l'extension de l'allocation en m�moire,
	* affichez les informations qui suivent.
	* Cet affichage sera supprim� apr�s le test du conteneur */
		cout << "Extension - Allocaton/R�allocation de " << newTaille * sizeof(Item)
			<< " octets (" << newTaille << " items)." << endl;
	}
	p.sommet++;
	p.tab[p.sommet] = it;
}

/**
 * @brief D�piler l�item au sommet de pile
 * @param[in,out] p : la pile
 * @pre la pile n�est pas vide
 */
void depiler(Pile& p) {
	assert(!estVide(p));
	p.sommet--;
}
