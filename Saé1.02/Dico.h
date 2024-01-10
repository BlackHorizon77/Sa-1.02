#ifndef _DICO_
#define _DICO_

/**
 * @file Dico.h
 * @author Ethan LEGRAND 104
 * @version 1 18/12/2023
 * @brief Projet S1.02 - Lexicon
 */

 /**
  * @brief Nombre de charactères maximum dans un mot français 
  */
const int MOTMAX = 26;
 /**
  * @brief Verification d'un mot dans un dictionnaire 
  * @return true or false
  */
bool verification(const char* argc);

#endif 
