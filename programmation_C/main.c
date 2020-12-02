#include <stdio.h>
#include <stdlib.h>
//#include <window.h>
#include "bateau.h"
#include "plateau.h"
#include "action.h"



int main() {
        int Tplateau[10][10];
        int bateau[3][2];
        int tire[2];
        int essaie=0,
            touche=0;

        initPlateau(Tplateau);
        initBateau(bateau);

        printf("\n");

        do{
            plateau(Tplateau);
            attaque(tire);
            essaie++;

            if(coule(tire,bateau)){
                vise(tire,bateau,essaie);
                touche++;
            }
            else
                vise(tire,bateau,essaie);

            initPlateau2(tire,bateau,Tplateau);


        }while(touche!=3);

        printf("\n\n\n BRAVO, tu viens d'eradiquer tout les bateaux en %d essaies", essaie);
        plateau(Tplateau);
    }



