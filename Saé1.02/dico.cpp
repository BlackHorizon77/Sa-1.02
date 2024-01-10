
/**
 * @file Dico.cpp
 * @author Ethan LEGRAND 104
 * @version 1 18/12/2023
 * @brief Projet S1.02 - Lexicon
 */

#include <iostream>
#include <fstream> 
#include <iomanip> 
#include <cstring>

#include "Dico.h"

using namespace std;

bool verification(const char* argc) {
	ifstream in("dico.txt"); 
	if (!in) {
		return false;
	}
	
	int nb = 0;
	char s[MOTMAX];
	in >> setw(MOTMAX) >> s; 
	while (in) {
		if (strcmp(argc, s)==0) {
			nb++;
		}
		in >> setw(MOTMAX) >> s; 
	}
	in.close(); 
	if (nb > 0) return true;
	else return false;
}