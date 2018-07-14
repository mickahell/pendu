//
//  dico.c
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
#include "dico.h"

int dicoMot (char *motDico){
    int ligneDuMot = 0;
    int caractereLu = 0;
    int i = 0;
    char motSecret[] = "";
    
    
    FILE* dico = NULL;
    dico = fopen("dico.txt", "r");
    if (dico != NULL){
        do{
            caractereLu = fgetc(dico);
            if (caractereLu == '\n')
                i++;
        } while(caractereLu != EOF);
        
        rewind(dico);
        srand(time(NULL));
        ligneDuMot = (rand() % (i - 1) + 1);
        
        while (ligneDuMot > 0){
            caractereLu = fgetc(dico);
            if (caractereLu == '\n')
                ligneDuMot--;
        }
        fgets(motSecret, 100, dico);
        
        // On vire le \n à la fin
        motSecret[strlen(motSecret) - 1] = '\0';
    }
    fclose(dico);
    
    return 1;
}
