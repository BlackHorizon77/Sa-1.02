
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
		/* Strat�gie de r�allocation proportionnelle au pas d'extension :
		 * initialisez la nouvelle taille du conteneur (newTaille)
		 * � (i+1) * c.pasExtension */
		unsigned int newTaille = (i + 1) * c.pasExtension;
		/* Allouez en m�moire dynamique un nouveau tableau (newT)
		 * � cette nouvelle taille*/
		Mot* newT = new Mot[newTaille];

		/* Recopiez les items d�j� stock�s dans le conteneur */
		for (unsigned int j = 0; j < c.capacite; j++) {
			newT[j] = c.tab[j];
		}
		/* D�sallouez l'ancien tableau support du conteneur */
		delete[] c.tab;
		/* Actualiser la mise � jour du conteneur en m�moire dynamique
		 * Faites pointer le tableau support du conteneur
		 * sur le nouveau tableau en m�moire dynamique */
		c.tab = newT;
		/* Actualisez la taille du conteneur */
		c.capacite = newTaille;
	}
	/* Ecriture de l'item (it) � la position i dans le conteneur */
	c.tab[i] = it;
}

