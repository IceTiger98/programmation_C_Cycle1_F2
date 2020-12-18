#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#define  LARGEUR_Map 31
#define  HAUTEUR_Map 16
#define  RandMAX_X 29
#define  RandMAX_Y 14
#define PistMAX 4


/*void gotoxy(short x, short y)
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);            //Tentative de gotoxy
    COORD Pos={x,y};
    SetConsoleCursorPosition(hConsole,Pos);
}*/

//Type structuré



//Type structuré pour définir les coordonnées du pisteur et du monstre
typedef struct coord_Pisteur {
    int x;
    int y;
    } coord_Pisteur;

typedef struct coord_MonkC {
    int x;
    int y;
    } coord_MonkC;

    //programme principal
int main(){

    int n_i, n_j, n_pisteur;
    int *pt_pisteur = &n_pisteur;

    coord_MonkC pt_monk;

    int TtraceP[HAUTEUR_Map][LARGEUR_Map];
    int TtraceM[HAUTEUR_Map][LARGEUR_Map];

    coord_Pisteur T_pisteur[PistMAX];

    char map[HAUTEUR_Map][LARGEUR_Map]=
    {
        {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'/*,'0'*/},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'/*,'1'*/},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'/*,'2'*/},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'/*,'3'*/},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'/*,'4'*/},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'/*,'5'*/},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'/*,'6'*/},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'/*,'7'*/},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'/*,'8'*/},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'/*,'9'*/},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'/*,'10'*/},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'/*,'11'*/},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'/*,'12'*/},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'/*,'13'*/},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'/*,'14'*/},
        {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'/*,'15'*/},
        //{'0','1','2','3','4','5','6','7','8','9','1','1','1','1','1','1','1','1','1','1','2','2','2','2','2','2','2','2','2','2','3','/'},
        //{'/','/','/','/','/','/','/','/','/','/','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','/'},
    };

    titre();                                    //Procédure qui affiche le titre
    histoire();                                 //Procédure qui affiche le scénario
    Mpisteur();                                 //Procédure qui affiche les mécanique du pisteur
    Mmonkc();                                   //Procédure qui affiche les mécaniques du monstre
    afficheMap(map);                            //Procédure qui affiche la texture de la map
    afficheLegende();                           //Procédure qui affiche la legende
    parametrePisteur(&pt_pisteur);              //Procédure de parametrage de pisteur
    placePisteur(&pt_pisteur,map,T_pisteur);    //Procédure qui place le pisteur
    placeMonk(map,TtraceM,&pt_monk);            //Procédure qui place aléatoirement le monstre

    return 0;

}
//procédure pour afficher les couleurs (couleur caractère, couleur fond)
void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}
//procédure qui affiche le titre en ASCII art
void titre()
{
    color(2,0);

printf("      ___       ___                    ___           ___           ___           ___           ___           ___      \n");
printf("     /\\_ \\     /\\  \\                  /\\  \\         /\\  \\         /\\  \\         /\\  \\         /\\__\\         /\\  \\     \n");
printf("    /:/  /    /::\\  \\                 \\:\\  \\       /::\\  \\       /::\\  \\       /::\\  \\       /:/  /        /::\\  \\    \n");
printf("   /:/  /    /:/\\:\\  \\                 \\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\     /:/  /        /:/\\:\\  \\   \n");
printf("  /:/  /    /::\\~\\:\\  \\                /::\\  \\   /::\\~\\:\\  \\   /::\\~\\:\\  \\    \\:\\~\\:\\  \\   /:/  /  ___   /::\\~\\:\\  \\  \n");
printf(" /:/__/    /:/\\:\\ \\:\\__\\              /:/\\:\\__\\ /:/\\:\\ \\:\\__\\ /:/\\:\\ \\:\\__\\    \\:\\ \\:\\__\\ /:/__/  /\\__\\ /:/\\:\\ \\:\\__\\ \n");
printf(" \\:\\  \\    \\/__\\:\\/:/  /             /:/  \\/__/ \\/_|::\\/:/  / \\/__\\:\\/:/  /     \\:\\/:/  / \\:\\  \\ /:/  / \\:\\~\\:\\ \\/__/ \n");
printf("  \\:\\  \\        \\::/  /             /:/  /         |:|::/  /       \\::/  /       \\::/  /   \\:\\  /:/  /   \\:\\ \\:\\_\\   \n");
printf("   \\:\\  \\       /:/  /              \\/__/          |:|\\/__/        /:/  /        /:/  /     \\:\\/:/  /     \\:\ \\/__/   \n");
printf("    \\:\\__\\     /:/  /                              |:|  |         /:/  /        /:/  /       \\::/  /       \\:\\__\\     \n");
printf("     \\/__/     \\/__/                                \\|__|         \\/__/         \\/__/         \\/__/         \\/__/     \n");


    color(15,0);

}

//Procedure du "scénario" du jeu. La mise en contexte
void histoire ()
{
    printf("\n\n\n");
    color(12,0);
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_SCENARIO-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");
    color(15,0);
    printf("Monk C, monstre entid%cluvien, s'est échappé... Il rode dans la r%cgion !\n", 130);
    printf("\n");
    printf("Vous %ctes le responsable d'un groupe de pisteurs.\n", 136);
    printf("Ceux-ci vous informent des traces qu'ils d%ccouvrent: o%c et surtout quand le monstre est pass%c par l%c...\n", 130, 151, 130, 133);
    printf("Mais attention ! Monk C est intelligent, et si vous n'y prenez garde, il an%cantira vos pisteurs un %c un... \n", 130, 133);
    printf("\n");
    color(12,0);
}

//Procedure de la mécanique des pisteurs. Un mode d'emploi
void Mpisteur ()
{
    printf("\n\n\n");
    color(12,0);
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_MECANIQUES PISTEURS-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");
    color(15,0);
    printf("Les pisteurs\n");
    printf("\n");
    printf("Au d%cbut du jeu, vous pouvez placer jusqu'%c 4 pisteurs.\n", 130, 133);
    printf("Un pisteur peut se d%cplacer en haut, bas, gauche et droite.\n", 130);
    printf("\n");
    printf("Un  pisteur peut avoir trois apparences:\n");
    printf("-[P]: Indique la position du pisteur.\n");
    printf("-[!]: Indique que le pisteur a un rapport %c faire.\n", 133);
    printf("-[?]: Indique que le pisteur attend votre ordre.\n");
    printf("\n");
    printf("Le rapport peut indiquer:\n");
    printf("- Si il y a quelque chose: le monstre, une trace de pas, ou rien.\n");
    printf("- Si il y a une trace, le rapport indique la fraicheur du pas sur une %cchelle de 1 %c 16, plus la valeur est haute, plus la trace est fraiche.\n", 130, 133);
    printf("- Si le monstre est vu, le pisteur peut tirer en appuyant sur [T] et avoir une chance de le toucher. Il faut le toucher 4 fois pour l'abattre.\n");
    printf("\n");
    printf("Un pisteur peut voir dans une zone d'une case autour de lui: haut, bas, gauche, droite, diagonale haut gauche, haut droite, diagonale bas gauche et bas droite.\n");
    printf("\n");
    color(12,0);
}

//Procedure de la mécanique du jeu. Un mode d'emploi
void Mmonkc ()
{
    printf("\n\n\n");
    color(12,0);
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_MECANIQUES MONSTRE-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");
    color(15,0);
    printf("Monk C\n");
    printf("\n");
    printf("Au d%cbut du jeu, le monstre est plac%c al%catoirement sur la carte.\n", 130, 130, 130);
    printf("\n");
    printf("Le monstre peut suivre un de vos pisteurs !\n");
    printf("\n");
    printf("Si le monstre, %c son tour de se d%cplacer, se trouve sur la case voisine d'un de vos pisteurs, le monstre tue le pisteur en question en se d%cplacant sur sa case.\n", 133, 130, 130);
    printf("\n");
}


//Procedure pour afficher la map
void afficheMap (char map[16][LARGEUR_Map])
{
    int i,j;

    for (i=0; i<HAUTEUR_Map; i++){
        for (j=0; j<LARGEUR_Map; j++)
        {
            if(map[i][j]=='*'){
                color(4,2);
                printf("|%c|", map[i][j]);
                color(15,0);
            }
            if(map[i][j]=='P'){
                color(2,8);
                printf("|%c|", map[i][j]);
                color(15,0);
            }
            if(map[i][j]=='?'){
                color(12,8);
                printf("|%c|", map[i][j]);
                color(15,0);
            }
            if(map[i][j]=='!'){
                color(12,8);
                printf("|%c|", map[i][j]);
                color(15,0);
            }
            if(map[i][j]=='X'){
                color(12,8);
                printf("|%c|", map[i][j]);
                color(15,0);
            }
            /*if(map[i][j]=='/'){
                color(15,15);
                printf("|%c|", map[i][j]);                                              //Tentative de marquage du vide
                color(15,0);
            }*/
            if(map[i][j]==' '){
                color(0,8);
                printf("|%c|", map[i][j]);
                color(15,0);
            }
            /*if(map[i][j]=='0'||'1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'){          //Tentative de marquage des ligne et colonne
                color(0,15);
                printf("|%c|", map[i][j]);
                color(15,0);
            }*/
        }
        printf("\n");
    }
}

//Procedure afficher la légende
void afficheLegende()
{
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_LEGENDE-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");

    color(2,8);
    printf("|P|");
    color(15,0);
    printf(": Pisteurs");
    printf("\n");

    color(12,8);
    printf("|!|");
    color(15,0);
    printf(": Rapports");
    printf("\n");

    color(12,8);
    printf("|?|");
    color(15,0);
    printf(": Ou allez-vous ?");
    printf("\n");

    color(12,8);
    printf("|X|");
    color(15,0);
    printf(": Monk C a ete vu !");
    printf("\n");

    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");

}

//Procedure qui propose à l'utilisateur combien de pisteurs il veut placer
void parametrePisteur(int *pt_pisteur)
{
  int nbrPisteur;

  printf("Engagez entre 1 et 4 pisteurs: \n");
  scanf("%d", &nbrPisteur);

  if (nbrPisteur <= PistMAX){
    *pt_pisteur = nbrPisteur;
  }
  else{
    printf("Engagez entre 1 et 4 pisteurs: \n");
    scanf("%d", &nbrPisteur);
  }
}

//Procedure qui place les pisteurs
void placePisteur(int *pt_pisteur, char map[HAUTEUR_Map][LARGEUR_Map], struct coord_Pisteur T_pisteur[4])

{
    int i,n_x,n_y;

    for (i=1; i<=*pt_pisteur; i++)
    {
        printf("Dans quelle colonne (de 1 a 29) voulez-vous placer le pisteur %d: \n", i);
        scanf("%d", &n_x);
        printf("Dans quelle ligne (de 1 a 14) voulez-vous placer le pisteur %d: \n", i);
        scanf("%d", &n_y);

        map[n_y][n_x]='P';

        T_pisteur[i].x=n_x;
        T_pisteur[i].y=n_y;

    }
}

//Procedure qui génère la position de départ de Monk C
void placeMonk(char map[HAUTEUR_Map][LARGEUR_Map], int mapMonk[HAUTEUR_Map][LARGEUR_Map],coord_MonkC *pt_monk)
{
    int monk_x, monk_y, i, j, k, l, vie, Cg_X, Cg_Y, Cd_X, Cd_Y;

    //initialisation du placement en aléatoire du monstre
    srand(time(NULL));
    monk_x=(rand()%(RandMAX_X)+1);
    monk_y=(rand()%(RandMAX_Y)+1);
    i = monk_y;
    j = monk_x;

    //placement aléatoire du monstre
    while (vie > 0){
        if (map[i][j]==' '){
            if(i-1<0){Cg_Y=0;}else{Cg_Y=i-1;}
            if(i-1>=HAUTEUR_Map){Cd_Y=HAUTEUR_Map;}else{Cd_Y=i-1;}
            if(j-1<0){Cg_X=0;}else{Cg_X=j-1;}
            if(i-1>=LARGEUR_Map){Cd_X=LARGEUR_Map;}else{Cd_X=i-1;}

            vie=0;
            for (k=Cg_Y;k<=Cg_Y;k++){
                for (k=Cg_X;k<=Cg_X;k++){
                    if (map[k][l]=='P'){
                        vie++;
                    }
                }
            }
        }
    }
    mapMonk[i][j]=15;
    pt_monk -> x = j;
    pt_monk -> y = i;

}














//Le reste de la tentative


/*void initPlateau(int Tplateau[29][16])
{
    int ligne, colonne;
        for(ligne=0 ; ligne < 16 ; ligne++ )
            for(colonne=0 ; colonne < 29 ; colonne++ )
                Tplateau[ligne][colonne]=-1;
}

void printMap(int map[][29])
{
	int i;
    int j;
    //caseNb nbCase;

    //tracé horizontal haut
    for(i=0;i<LARGEUR_Map+1;i++){
        gotoxy(i,0);
        printf("%c",delimtMap);
    }

    //tracé horizontal bas
    for(i=0;i<LARGEUR_Map+1;i++){
        gotoxy(i,HAUTEUR_Map+1);
        printf("%c",delimtMap);
    }

    //tracé vertical gauche
    for(i=0;i<HAUTEUR_Map+1;i++){
        gotoxy(0,i);
        printf("%c",delimtMap);
    }

    //tracé vertical droit
    for(i=0;i<HAUTEUR_Map+1;i++){
        gotoxy(LARGEUR_Map+1,i);
        printf("%c",delimtMap);
    }

void placePist(int pisteur[2])
{

        printf("Ligne: ");
        scanf("%d",&pisteur[0]);
        pisteur[0]--;

        printf("Colonne: ");
        scanf("%d",&pisteur[1]);
        pisteur[1]--;

        gotoxy(pisteur[0],pisteur[1]);
        printf("P");
}




int main() {
        int map[16][29];
        int pisteur[2];
        printMap(map);
        placePist(pisteur);




        getchar();
        return 0;
}*/
