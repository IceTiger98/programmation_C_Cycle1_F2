
void initBateau(int bateau[][2]){
        srand(time(NULL));
        int n_bat, last;

        for(n_bat=0 ; n_bat < 3 ; n_bat++){
            bateau[n_bat][0]= rand()%10;
            bateau[n_bat][1]= rand()%10;

            //vérifie si le tire a deja ete fait a cette endroit la
            //si non, on sort de la boucle
            for(last=0 ; last < n_bat ; last++){
                if( (bateau[n_bat][0] == bateau[last][0])&&(bateau[n_bat][1] == bateau[last][1]) )
                    do{
                        bateau[n_bat][0]= rand()%10;
                        bateau[n_bat][1]= rand()%10;
                    }while( (bateau[n_bat][0] == bateau[last][0])&&(bateau[n_bat][1] == bateau[last][1]) );
            }

        }
    }

int coule(int tire[2], int bateau[][2])
{
    int n_bat;

        for(n_bat=0 ; n_bat < 3 ; n_bat++){
            if( tire[0]==bateau[n_bat][0] && tire[1]==bateau[n_bat][1]){
                printf("Touche en (%d,%d)\n",tire[0]+1,tire[1]+1);
                return 1;
            }
        }
        return 0;
    }
