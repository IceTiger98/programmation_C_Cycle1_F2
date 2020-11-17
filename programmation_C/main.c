#include <stdio.h>
#include <stdlib.h>

/*-------Programme principal-------*/
int main ()                                                                                                 //Programme principal
{
    int j1 = 0, j2 = 0, /*tour=1*/ de;                                                                              //VAR :  j1, j2, de : ENTIER
    srand(time(NULL));//Chaque partie est unique
    do                                                                                                              //DEBUT :
    {                                                                                                                           //j1 = 0
        //printf ("Tour %d\n", tour+1);                                                                                         //j2 = 0
                                                                                                                                //TANT QUE
        printf ("joueur 1 : ");                                                                                                     //(j1 <> 66 et j2 <> 66)
            lanceDe (&de);                                                                                                      //FAIRE
            positionJoueur (&j1, &de);                                                                                              //ECRIRE "joueur 1 : "
            printf ("Tire un %d", de);                                                                                                  //lancede
            printf (" et va a la case %d\n", j1);                                                                                       //positionJoueur
                                                                                                                                        //ECRIRE "Tire un ", de
        printf ("joueur 2 : ");                                                                                                         //ECRIRE " et va a la case", j1
            lanceDe (&de);                                                                                                          // ECRIRE "joueur 2 : "
            positionJoueur (&j2, &de);                                                                                                  //lancede (&de)
            printf ("Tire un %d", de);                                                                                                  // positionJoueur
            printf (" et va a la case %d\n\n", j2);                                                                                     //ECRIRE "Tire un ", de
                                                                                                                                        //ECRIRE " et va a la case, j2
    }while (j1 != 66 && j2 != 66);//Tant qu'il n'y a aucun vainqueur, continuer le programme                                    //FINTANTQUE
    victoire (j1);                                                                                                              //victoire
                                                                                                                    //FIN.
    return 0;


}

/*-------Fonction du lancement de 2 des de 6 (12)-------*/
void lanceDe (int *de)                                                                                      //FONCTION lancede (*de : ENTIER): ENTIER
{
    *de =(rand()%(12 - 2 + 1)) + 2;// 2 des 6                                                                           //DEBUT:
}                                                                                                                               //*de <- alea(2,12)
                                                                                                                        //FIN
/*-------Fonction des evenements du jeu-------*/
void positionJoueur (int *position, int *de)                                                                //FONCTION positionJoueur (*position, *de : ENTIER): CHAINE
{
    *position = *position + *de;                                                                                        //VAR : nbrcase : ENTIER
    int nbrcase;
                                                                                                                        //DEBUT:
        if (*position % 9 == 0)                                                                                                 //*position = *position + *de
            {                                                                                                                   //SI *position MOD(9) = 0
                *position = *position + *de;                                                                                            //ALORS ECRIRE "Case Oie, le lance est double !"
                printf ("Case Oie, le lance est double !\n");//Toutes les 9 cases, le lance vaut double...                      //FINSI
            }
                                                                                                                                //SI *position = 63
        if (*position == 63)                                                                                                            //ALORS *position = 63
        {                                                                                                                       //FINSI
            *position = 63;//... sauf a la case 63
        }                                                                                                                       //SI *position = 17
                                                                                                                                        //ALORS *position = 40
        if (*position == 17)                                                                                                            //ECRIRE "Vous etes tombez du pont, emporte par le courant !
            {                                                                                                                   //FINSI
                *position = 40;
                ;printf ("Vous etes tombez du pont, emporte par le courant !\n");                                               //SI *position = 85
            }                                                                                                                       //ALORS *position = 0
                                                                                                                                    //ECRIRE "Pas de chance, retour a la case depart !"
        if (*position == 58)                                                                                                    //FINSI
            {
                *position = 0;                                                                                                  //SI *position > 66
                printf ("Pas de chance, retour a la case depart !\n");                                                              //ALORS *position = 66 - nbrcase
            }                                                                                                                       //nbrcase = *position - 66
                                                                                                                                //FINSI
        if (*position > 66)//On recule si le joueur si le joueur dépasse la case 66                                     //FIN
            {
                *position = 66 - nbrcase;
                nbrcase = *position - 66;
            }
}

/*-------Fonction condition de victoire-------*/
void victoire (int position)                                                                                //FONCTION victoire (position : ENTIER): CHAINE
{
     if (position == 66)                                                                                                //DEBUT:
        printf ("Joueur 1 vainqueur\n");
     else                                                                                                                       //SI position = 66
         printf ("joueur 2 vainqueur\n");                                                                                           //ALORS ECRIRE "Joueur 1 vainqueur"
}                                                                                                                                   //SINON ECRIRE "Joueur 2 vainqueur"
                                                                                                                                //FINSI
                                                                                                                        //FIN
