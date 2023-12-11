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
