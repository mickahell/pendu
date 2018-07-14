//
//  caractere.c
//  pendu
//
//  Created by Michaël on 18/04/2018.
//  Copyright © 2018 Mickahell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "caractere.h"

char lireCaractere()
{
    char caractere = 0;
    
    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà
    
    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
    while (getchar() != '\n') ;
    
    
    return caractere; // On retourne le premier caractère qu'on a lu
}
