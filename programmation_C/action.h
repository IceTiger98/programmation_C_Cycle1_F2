void attaque(int tire[2])
{

        printf("Ligne: ");
        scanf("%d",&tire[0]);
        tire[0]--;

        printf("Colonne: ");
        scanf("%d",&tire[1]);
        tire[1]--;

}


void vise(int tire[2], int bateau[][2], int essaie)
{
        int ligne=0,
            colonne=0,
            rang;

        //count how many bateau there is ligne/colonne
        for(rang=0 ; rang < 3 ; rang++){
            if(bateau[rang][0]==tire[0])
                ligne++;
            if(bateau[rang][1]==tire[1])
                colonne++;
        }

        printf("\nTour %d: \nLigne %d -> %d Bateau(x)\nColonne %d -> %d Bateau(x)\n",essaie,tire[0]+1,ligne,tire[1]+1,colonne);
}

