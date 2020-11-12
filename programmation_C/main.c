#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* commentaire paragraphe*/
    // commentaire ligne

    //unsigned : non sign� ex: unsigned short sn_entier
    //integer
    short sn_entier;
    int n_entier;
    long l_entier;

    printf("Taille en octet du short : %d\n", sizeof(sn_entier));
    printf("Taille en octet de entier : %d\n",sizeof(n_entier));
    printf("Taille en octet du long : %d\n",sizeof(l_entier));

    //reel
    //unsigned : non sign� ex: unsigned float flt_entier
    float flt_reel;
    double dbl_reel;
    long double ldbl_reel;

    printf("Taille en octet du float : %d\n", sizeof(flt_reel));
    printf("Taille en octet de double : %d\n",sizeof(dbl_reel));
    printf("Taille en octet du long double : %d\n",sizeof(ldbl_reel));

    //caract�re
    char c_car;
    printf("Taille en octet du caractere : %d\n", sizeof(c_car));


    //op�rateurs


    //== (�galit�)
    //<= (plus petit ou �gal)
    //>= (plus grand ou �gal)
    //!= (pas =)
    //+
    //-
    /* '/' division */
    //% (modulo)
    //= (assignation)
    //, (la s�quence (ordre) ex: instruction 1,instruction 2)
    //& (&&)
    //| (||)
    //! (not)
    //++
    //+= (res+=a revient � res=res+a)
    //-= (res-=a revient � res=res-a)
    //'/='(res/=a revient � res=res/a)
    //*=(res*=a revient � res=res*a)

    //printf("%d\n",(n_a>n_b));
    // voir dans cplusplus.com/references/cstdio



    int n_a = 255;
    int n_b = 0;

    printf ("val de n_a: %d\n", n_a);
    printf ("val de n_b: %d\n", n_b);

    //ecrire
    printf ("val de n_a et n_b: %d\n", n_a, n_b);
    printf ("val de n_a et n_b: %x\n", n_a, n_b);

    printf ("Saisir un entier dans n_a\n");
    //lire
    scanf("%d",&n_a);
    printf ("Saisir un entier dans n_b\n");
    scanf("%d",&n_b);

    printf ("val de n_a et n_b: %d\n", n_a, n_b);




    return 0;

}
