void initPlateau(int Tplateau[][10])
{
    int ligne, colonne;
        for(ligne=0 ; ligne < 10 ; ligne++ )
            for(colonne=0 ; colonne < 10 ; colonne++ )
                Tplateau[ligne][colonne]=-1;
}

void plateau(int Tplateau[][10])
{

    int ligne, colonne;

        printf("\t1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9 \t10");
        printf("\n");

        for(ligne=0 ; ligne < 10 ; ligne++ ){
            printf("%d",ligne+1);
            for(colonne=0 ; colonne < 10 ; colonne++ ){
                if(Tplateau[ligne][colonne]==-1){
                    printf("\t~");
                }else if(Tplateau[ligne][colonne]==0){
                    printf("\t*");
                }else if(Tplateau[ligne][colonne]==1){
                    printf("\tX");
                }

            }
            printf("\n");
        }

}

void initPlateau2(int tire[2], int bateau[][2], int Tplateau[][10]){
        if(coule(tire,bateau))
            Tplateau[tire[0]][tire[1]]=1;
        else
            Tplateau[tire[0]][tire[1]]=0;
    }
