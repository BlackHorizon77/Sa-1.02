#ifndef _MOT_
#define _JEU_

struct Mot {
	char mot[26];
	int taille;
};

struct ConteneurTDE{
	unsigned int capacite; 	   // capacité du conteneur (>0)
	unsigned int pasExtension; // pas d'extension du conteneur (>0)
	Mot* tab;		   // conteneur alloué en mémoire dynamique
};

void afficher(const Mot& m);
void initialiser(ConteneurTDE& t, unsigned int c, unsigned int p);
void detruire(ConteneurTDE& t);
Mot lire(const ConteneurTDE& t, unsigned int i);
void ecrire(ConteneurTDE& t, unsigned int i, const Mot& it);
Mot s();

#endif 
