
#include "Mot.h"

#include <cassert>
#include <iostream>

using namespace std;


void afficher(const Mot& m) {
	for (int i = 0; i < m.taille; i++) {
		cout << m.mot[i];
	}
}

void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p) {
	assert(capa > 0 && p > 0);

	c.capacite = capa;
	c.pasExtension = p;
	c.tab = new Mot[capa];
}

void detruire(ConteneurTDE& c) {
	c.capacite = 0;
	c.pasExtension = 0;
	delete[] c.tab;
}
Mot s() {
	Mot d;
	cin >> d.mot;
	d.taille = strlen(d.mot);
	return d;
}

Mot lire(const ConteneurTDE& c, unsigned int i) {
	assert(i < c.capacite);
	return c.tab[i];
}

void ecrire(ConteneurTDE& c, unsigned int i, const Mot& it) {
	if (i >= c.capacite) {
		/* Stratégie de réallocation proportionnelle au pas d'extension :
		 * initialisez la nouvelle taille du conteneur (newTaille)
		 * à (i+1) * c.pasExtension */
		unsigned int newTaille = (i + 1) * c.pasExtension;
		/* Allouez en mémoire dynamique un nouveau tableau (newT)
		 * à cette nouvelle taille*/
		Mot* newT = new Mot[newTaille];

		/* Recopiez les items déjà stockés dans le conteneur */
		for (unsigned int j = 0; j < c.capacite; j++) {
			newT[j] = c.tab[j];
		}
		/* Désallouez l'ancien tableau support du conteneur */
		delete[] c.tab;
		/* Actualiser la mise à jour du conteneur en mémoire dynamique
		 * Faites pointer le tableau support du conteneur
		 * sur le nouveau tableau en mémoire dynamique */
		c.tab = newT;
		/* Actualisez la taille du conteneur */
		c.capacite = newTaille;
	}
	/* Ecriture de l'item (it) à la position i dans le conteneur */
	c.tab[i] = it;
}

