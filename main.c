int main() {


     int nc, nv;
     int g;
     printf("**********************WELCOME**********************\n ");
     printf("Choose problem type: \n");
     printf("1. Maximization.\n");
     printf("2. Minimization.\n");
     scanf("%d",&g); getchar();

     switch(g)
     {
         case 1:{
     printf("Enter the number of variables: ");
     scanf("%d", &nv);
     printf("Enter the number of constraints: ");
     scanf("%d", &nc);



    int col = nv + nc + 1;
    int row = nc + 1;

     int i,j;
     int solution[nv];


     for(i = 0; i < nv; i++)
     {solution[i] = -1;}

     float **matrix=(float**)malloc(row * sizeof(float*));
     for (i=0; i < row; i++) {
         matrix[i] = (float*)calloc(col, sizeof(float));
     }


     printf("Enter the coefficients of the objective function Z:\n");


     for (i = 1; i <= nv; i++){
     printf("X%d: ",i);
         scanf("%f", &matrix[line-1][i]);
     }
     matrix[row-1][0]=0; //second member of z
     printf("\n\n");




     printf("Enter the constraint coefficients:\n");


     for (i = 0; i < row-1; i++) {
         printf("Constraint %d: \n", i + 1);
         for (j = 1; j <= nv; j++){

         printf("X%d:", j);
             scanf("%f", &matrix[i][j]);
     }

     printf("\nEnter the second member: ");
     scanf("%f", &matrix[i][0]);
     matrix[i][nv+i+1] = 1;
     printf("\n");
     }



     printf("\n\n");

     displays(matrix, row, col);

     simplex_method(matrix, row, col, solution);

     for(int i = 0; i <nv; i++){
	if(solution[i] == -1 ){
		printf("X%d = 0",i+1);
	}
	else{

                printf("X%d = %.2f",i+1,matrix[solution[i]][0]);
	}
     }


     printf(" \n\nZ = %.2f \n\n",-matrix[row-1][0]);
     break;}



     case 2:{printf("Enter the number of variables: ");
     scanf("%d", &nv);
     printf("Enter the number of constraints: ");
     scanf("%d", &nc);



    int col = nv + nc + 1;
    int line = nc + 1;

     int i,j;
     int solution[nv];


     for(i = 0; i < nv; i++)
     {solution[i] = -1;}

     float **matrix=(float**)malloc(row * sizeof(float*));
     for (i=0; i < row; i++) {
         matrix[i] = (float*)calloc(col, sizeof(float));
     }


     printf("Enter the coefficients of the objective function Z:\n");


     for (i = 1; i <= nv; i++){
         printf("X%d: ",i);
         scanf("%f", &matrix[row-1][i]);
     }
	     
     matrix[row-1][0]=0; //second member of z
     printf("\n\n");


     printf("Enter the constraint coefficients:\n");


     for (i = 0; i < row-1; i++) {
         printf("Constraint %d: \n", i + 1);
         for (j = 1; j <= nv; j++){

             printf("X%d:", j);
             scanf("%f", &matrix[i][j]);
          }

         printf("\nEnter the second member: ");
         scanf("%f", &matrix[i][0]);
         matrix[i][nv+i+1] = 1;
         printf("\n");
     }



     printf("\n\n");
     make_matrix_negative(matrix, row, col);
     displays(matrix, row, col);

     method_simplex1(matrix, row, col, solution);

     for(int i = 0; i <nv; i++){
	if(solution[i] == -1 ){
		printf("X%d = 0",i+1);
	}
        else{

                 printf("X%d = %.2f",i+1,-matrix[solution[i]][0]);
        }
     }   



     printf(" \n\nZ = %.2f \n\n",-matrix[row-1][0]);
     break;}

     default :break;}

  return 0;

}
