/**
 * Euclidian Algorithm
 *
 * The Euclidean algorithm (also called Euclid's algorithm) is an
 * algorithm to determine the greatest common divisor of two integers.
 */                                   
#include <stdio.h>   // printf         // On inclut la librairie standard d'entrées/sorties pour utiliser printf
#include <stdlib.h>  // atoi           // On inclut la librairie standard pour utiliser atoi (conversion chaîne -> entier)

// PGCD (algorithme d'Euclide) 
int gcd(int a, int b) {               // Déclaration/definition de la fonction gcd prenant deux entiers a et b, retourne un int (le PGCD)
  // valeurs absolues pour a et b
  if (a < 0) a = -a;                  // Si a est négatif, on le rend positif 
  if (b < 0) b = -b;                  // Si b est négatif, on le rend positif

  // cas simples
  if (a == 0) return b;               // Si a vaut 0, le PGCD est b 
  if (b == 0) return a;               // Si b vaut 0, le PGCD est a

  // boucle d’Euclide: (a, b) <- (b, a % b)
  while (b != 0) {                    // Tant que le reste b n’est pas nul, on continue l’algorithme
    int r = a % b;                    // r prend le reste de la division euclidienne de a par b
    a = b;                            // l’ancien b devient le nouveau a
    b = r;                            // le reste r devient le nouveau b
  }                                   // Fin de la boucle quand b == 0
  return a;                           // Quand b == 0, a contient le PGCD; on le retourne
}                                     // Fin de la fonction gcd

int main(int argc, char* argv[]) {    // Point d’entrée du programme: argc = nb d’arguments, argv = tableau des arguments (en chaînes)
  // on attend 2 arguments : a et b
  if (argc < 3) {                     // Si on a moins de 3 éléments (nom du programme + 2 nombres
    return -1;                        //on quitte avec un code d’erreur 
  }

  int a = atoi(argv[1]);              // Conversion du 1er argument (chaîne) en entier: a
  int b = atoi(argv[2]);              // Conversion du 2e argument (chaîne) en entier: b

  int result = gcd(a, b);             // Appel de la fonction gcd pour calculer le PGCD de a et b; stockage dans result
  printf("%d\n", result);             // Affiche le résultat suivi d’un saut de ligne 

  return 0;                           // Retourne 0 pour indiquer que tout s’est bien passé
}                                     // Fin de main
