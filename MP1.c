#include <stdio.h>
#include <stdlib.h>

//Fonction affichant la matrice

void affiche(float **matrice,int ligne ,int col ){

	int i ,j ;
	for(i=0; i < ligne; i++){
    	for(j = 0; j < col; j++) {
      		printf("%.2f   ",matrice[i][j]);
    	}
    	printf("\n");
  	}
  	printf("\n");
}


int negative(float **matrice,int ligne ,int col ){
	for(int i = 0 ; i < col ; i++){
		if(matrice[ligne-1][i] > 0){
			return 1 ;
		}
	}
	return  0;
}


int positive(float **matrice,int ligne ,int col ){
	for(int i = 0 ; i < col ; i++){
		if(matrice[ligne-1][i] < 0){
			return 1 ;
		}
	}
	return  0;
}

//Fonction qui retourne un tableau avec la ligne, la colonne et la valeur du pivot

int* pivot(float **matrice,int ligne ,int col )
{
    int ind_col_pivot;
    int ind_ligne_pivot;

    int *tab = (int *)malloc(2 * sizeof(int));


    //Initialisation du pivot

    float pivot=matrice[ligne-1][0];



    //Trouver la colonne du pivot

    for (int i=1;i<col;i++)
    {
        if (pivot<matrice[ligne-1][i])
        {
            pivot=matrice[ligne-1][i];
            ind_col_pivot=i;
        }
    }


    pivot = 10000000 ;


    //Trouver la ligne du pivot

    for (int j=0;j<ligne-1;j++)
    {
        if (matrice[j][ind_col_pivot]!=0){


        if (pivot>matrice[j][0]/matrice[j][ind_col_pivot]){

         pivot=matrice[j][0]/matrice[j][ind_col_pivot];
         ind_ligne_pivot=j;

         }
     }
     }


     //On remplit un tableau avec les indices et la valeur du pivot pour les utiliser plus tard

     tab[0]=ind_ligne_pivot;
     tab[1]=ind_col_pivot;

     return tab;


}


void matrice_simplex(float **matrice, int ligne , int col)
{
    int ligne1;
    int colonne;

    int *p=pivot(matrice,ligne ,col );
    colonne=p[1];
    ligne1=p[0];


    float pivot = matrice[ligne1][colonne];




    for(int i=0;i<ligne;i++)
    {
        for(int j=0;j<col;j++)
        {
            if (i!=ligne1 && j!=colonne )//autre que ligne et colonne du pivot

                matrice[i][j] -= (matrice[i][colonne] * matrice[ligne1][j]) / pivot ;


        }

    }





}
void methode_simplex(float **matrice,int ligne ,int col ,int *solution)
{
    int ligne1;
    int colonne;

    int *p=pivot(matrice,ligne ,col );


    colonne=p[1];
    ligne1=p[0];

    float pivot = matrice[ligne1][colonne];


    solution[colonne-1]=ligne1;



    matrice_simplex(matrice, ligne, col);



    for(int i=0;i<col;i++)
    {
            matrice[ligne1][i]=matrice[ligne1][i]/pivot;

    }
        for(int i=0;i<ligne;i++)
    {
        if (i!=ligne1)
            matrice[i][colonne]=0;
    }


    affiche(matrice , ligne , col) ;


    if (negative(matrice,ligne,col) )
        methode_simplex(matrice,ligne ,col ,solution);



}









int* pivot1(float **matrice,int ligne ,int col )
{
    int ind_col_pivot;
    int ind_ligne_pivot;

    int *tab = (int *)malloc(2 * sizeof(int));


    //Initialisation du pivot

    float pivot=matrice[ligne-1][0];



    //Trouver la colonne du pivot

    for (int i=1;i<col;i++)
    {
        if (pivot>matrice[ligne-1][i])
        {
            pivot=matrice[ligne-1][i];
            ind_col_pivot=i;
        }
    }


    pivot = 10000000 ;


    //Trouver la ligne du pivot

    for (int j=0;j<ligne-1;j++)
    {
        if (matrice[j][ind_col_pivot]!=0){


        if (pivot>matrice[j][0]/matrice[j][ind_col_pivot]){

         pivot=matrice[j][0]/matrice[j][ind_col_pivot];
         ind_ligne_pivot=j;

         }
     }
     }


     //On remplit un tableau avec les indices et la valeur du pivot pour les utiliser plus tard

     tab[0]=ind_ligne_pivot;
     tab[1]=ind_col_pivot;

     return tab;


}
void methode_simplex1(float **matrice,int ligne ,int col ,int *solution)
{
    int ligne1;
    int colonne;

    int *p=pivot1(matrice,ligne ,col );


    colonne=p[1];
    ligne1=p[0];

    float pivot = matrice[ligne1][colonne];


    solution[colonne-1]=ligne1;



    matrice_simplex(matrice, ligne, col);


    for(int i=0;i<col;i++)
    {
            matrice[ligne1][i]=matrice[ligne1][i]/pivot;

    }
        for(int i=0;i<ligne;i++)
    {
        if (i!=ligne1)
            matrice[i][colonne]=0;
    }

    int r=0,v=1,q=2;
    printf("%d",r);

    affiche(matrice , ligne , col) ;

    printf("%d",v);


    if (positive(matrice,ligne,col)!=0 )
        methode_simplex1(matrice,ligne ,col ,solution);


    printf("%d",q);


}

void rendre_matrice_negative(float **matrice, int ligne, int col)
{
    int i, j;
    for (i = 0; i < ligne; i++)
    {
        for (j = 0; j < (col-ligne+1); j++)
        {
            matrice[i][j] *= -1;
        }
    }
}


int main() {


    int nc, nv;
    int g;
    printf("**********************WELCOME**********************\n");
    printf("Choisir le type de probleme :  \n");
    printf("1. Maximisation.\n");
    printf("2. Minimisation.\n");
    scanf("%d",&g);getchar();

    switch(g)
    {
        case 1:{
    printf("Entrez le nombre de variables : ");
    scanf("%d", &nv);
    printf("Entrez le nombre de contraintes : ");
    scanf("%d", &nc);



	int col = nv + nc + 1 ;
	int ligne = nc + 1 ;

    int i ,j;
    int solution[nv] ;


    for( i = 0 ; i < nv ; i++)
    		{solution[i] = -1 ;}

    float **matrice=(float**)malloc(ligne * sizeof(float*));
    for (i=0; i < ligne; i++) {
        matrice[i] = (float*)calloc(col , sizeof(float));
    }


    printf("Entrez les coefficients de la fonction objectif Z :\n");


    for (i = 1; i <= nv; i++){
    	printf("X%d  : ",i) ;
        scanf("%f", &matrice[ligne-1][i]);
    	}
    	matrice[ligne-1][0]=0; //second membre de z
    	printf("\n\n") ;




    printf("Entrez les coefficients des contraintes :\n");


    for (i = 0; i < ligne-1; i++) {
        printf("Contrainte %d : \n", i + 1);
        for (j = 1; j <= nv; j++){

        	printf("X%d   :", j) ;
            scanf("%f", &matrice[i][j]);
    	}

    	printf("\nEntrez le second membre : ") ;
    	scanf("%f", &matrice[i][0]);
    	matrice[i][nv+i+1] = 1 ;
    	printf("\n");
    }



    printf("\n\n") ;

    affiche(matrice , ligne , col) ;

    methode_simplex(matrice , ligne, col,solution);

		for(int i = 0 ; i <nv; i++){
			if(solution[i] == -1 ){
				printf("   X%d = 0   ",i+1) ;
			}
			else{

                printf("   X%d = %.2f    ",i+1,matrice[solution[i]][0]) ;
			}
			}



    printf("     \n\nZ = %.2f    \n\n",-matrice[ligne-1][0]);
    break;}



    case 2:{printf("Entrez le nombre de variables : ");
    scanf("%d", &nv);
    printf("Entrez le nombre de contraintes : ");
    scanf("%d", &nc);



	int col = nv + nc + 1 ;
	int ligne = nc + 1 ;

    int i ,j;
    int solution[nv] ;


    for( i = 0 ; i < nv ; i++)
    		{solution[i] = -1 ;}

    float **matrice=(float**)malloc(ligne * sizeof(float*));
    for (i=0; i < ligne; i++) {
        matrice[i] = (float*)calloc(col , sizeof(float));
    }


    printf("Entrez les coefficients de la fonction objectif Z :\n");


    for (i = 1; i <= nv; i++){
    	printf("X%d  : ",i) ;
        scanf("%f", &matrice[ligne-1][i]);
    	}
    	matrice[ligne-1][0]=0; //second membre de z
    	printf("\n\n") ;


    printf("Entrez les coefficients des contraintes :\n");


    for (i = 0; i < ligne-1; i++) {
        printf("Contrainte %d : \n", i + 1);
        for (j = 1; j <= nv; j++){

        	printf("X%d   :", j) ;
            scanf("%f", &matrice[i][j]);
    	}

    	printf("\nEntrez le second membre : ") ;
    	scanf("%f", &matrice[i][0]);
    	matrice[i][nv+i+1] = 1 ;
    	printf("\n");
    }



    printf("\n\n") ;
    rendre_matrice_negative(matrice , ligne, col);
    affiche(matrice , ligne , col) ;

    methode_simplex1(matrice , ligne, col,solution);

		for(int i = 0 ; i <nv; i++){
			if(solution[i] == -1 ){
				printf("   X%d = 0   ",i+1) ;
			}
			else{

                printf("   X%d = %.2f    ",i+1,-matrice[solution[i]][0]) ;
			}
			}



    printf("     \n\nZ = %.2f    \n\n",-matrice[ligne-1][0]);
    break;}

    default :break;}

 return 0;


    }

/*

2 3
30 50
3 2 1800
1 0 400
0 1 600





4 3
7 9 18 17
2 4 5 7 42
1 1 2 2 17
1 2 3 3 24
*/
