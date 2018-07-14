//
//  main.c
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
#include "caractere.h"
#include "dessin.h"


int main(int argc, char* argv[]){
    
    char maLettre = 0;
    int tailleMot = 0;
    int coups = 10;
    char *propositionLettre = NULL;
    int i = 0;
    int p = 0;
    char motSecret[] = "MARRON";
    int mode = 0;
    int newPartie = 0;
    
    int ligneDuMot = 0;
    int caractereLu = 0;
    
    do{
        for(mode = 0; !(mode == 1 || mode == 2);) {
            printf("=== MODE ===\n1. 1 joueur\n2. 2 joueurs\nVotre choix ?\n");
            mode = getchar();
            mode -= '0'; //Convertit un string en int
            switch (mode)
            {
                case 1:
                    printf("Forever alone... c'est triste. Allez je choisi un chiffre pour toi!\n\n");
                    break;
                case 2:
                    printf("Oh un copain\n\n");
                    break;
                default:
                    printf("T'es sur de ton choix ?\n\n");
                    break;
            }
        }
        if(mode == 2){
            printf("Choisi le mot secret : ");
            scanf("%s", &motSecret);
        }
        else{
                FILE* dico = NULL;
                dico = fopen("dico.txt", "r");
                if (dico != NULL){
                    do{
                        caractereLu = fgetc(dico);
                        if (caractereLu == '\n')
                            i++;
                    } while(caractereLu != EOF);
            
                    srand(time(NULL));
                    ligneDuMot = (rand() % (i - 1) + 1);
            
                    rewind(dico);
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
        }
        
        while (getchar() != '\n') ;
//        printf("Mot secret = %s\n", motSecret);
        tailleMot = strlen(motSecret);
        
        char motDecouvert[tailleMot];
        for(i = 0 ; i < tailleMot ; i++){
            motDecouvert[i] = '*';
        }
        while (coups != 0 && strcmp(motSecret, motDecouvert) != 0){
            printf("Mot : %s\n", motDecouvert);
            printf("Vous avez %d coups pour trouver le mot mystere, propose une lettre\n", coups);
            maLettre = lireCaractere();
            propositionLettre = strchr(motSecret, maLettre);
            
            if (propositionLettre != NULL){
                while (motSecret[p] != '\0'){
                    if (motSecret[p] == maLettre){
                        motDecouvert[p] = maLettre;
                    }
                    else{
                    }
                    ++p;
                }
                p = 0 ;
                printf("Il vous reste %d coups\n", coups);
            }
            else{
                coups--;
                dessin(coups);
                printf("%s\n", motDecouvert);
                printf("Il vous reste %d coups\n", coups);
            }
        }
        if (strcmp(motSecret, motDecouvert) == 0) {
            printf("Bravo, you WIN\n");
        }
        else{
            printf("C'est perdu !\n");
        }
        // Nouvelle partie ?
        printf("Veux faire une autre partie ? 1/0\n");
        scanf("%d", &newPartie);
    }while (newPartie != 0); {
        printf("Fin\n");
    }
    
    
    return 0;
}
