//
//  dessin.c
//  pendu
//
//  Created by Michaël on 22/04/2018.
//  Copyright © 2018 Mickahell. All rights reserved.
//

#include "dessin.h"

void dessin(int coupsManque){
    
    int dessiner = 0;
    
    for(dessiner = 0; !(dessiner == 1 || dessiner == 2 || dessiner == 3 || dessiner == 4 || dessiner == 5 || dessiner == 6 || dessiner == 7 || dessiner == 8 || dessiner == 9);) {
        dessiner = coupsManque;
        switch (dessiner)
        {
            case 1:
                printf(" |       _    \n |      / \\  \n |      \\_/  \n |      _|_   \n |     /| |\\ \n |    / |_| \\ \n |       ^    \n |      / \\  \n |     /   \\ \n");
                break;
            case 2:
                printf(" |      / \\  \n |      \\_/  \n |      _|_   \n |     /| |\\ \n |    / |_| \\ \n |       ^    \n |      / \\  \n |     /   \\ \n");
                break;
            case 3:
                printf(" |      \\_/  \n |      _|_   \n |     /| |\\ \n |    / |_| \\ \n |       ^    \n |      / \\  \n |     /   \\ \n");
                break;
            case 4:
                printf(" |      _|_   \n |     /| |\\ \n |    / |_| \\ \n |       ^    \n |      / \\  \n |     /   \\ \n");
                break;
            case 5:
                printf(" |     /| |\\ \n |    / |_| \\ \n |       ^    \n |      / \\  \n |     /   \\ \n");
                break;
            case 6:
                printf(" |    / |_| \\ \n |       ^    \n |      / \\  \n |     /   \\ \n");
                break;
            case 7:
                printf(" |       ^    \n |      / \\  \n |     /   \\ \n");
                break;
            case 8:
                printf(" |      / \\  \n |     /   \\ \n");
                break;
            case 9:
                printf(" |     /   \\ \n");
                break;
            default:
                printf("  _______     \n |       |    \n |       _    \n |      / \\  \n |      \\_/  \n |      _|_   \n |     /| |\\ \n |    / |_| \\ \n |       ^    \n |      / \\  \n |     /   \\ \n");
                break;
        }
        break;
    }
}
