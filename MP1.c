#include <stdio.h>
#include <stdlib.h>

//Function displaying the matrix

void displays(float **matrix, int row, int col){

int i,j;
for(i=0; i < row; i++){
     for(j = 0; j < col; j++) {
       printf("%.2f",matrix[i][j]);
     }
     printf("\n");
   }
   printf("\n");
}


int negative(float **matrix, int row, int col){
     for(int i = 0; i < col; i++){
		if(matrix[row-1][i] > 0){
			return 1;
		}
     }
     return 0;
}


int positive(float **matrix, int row, int col){
   for(int i = 0; i < col; i++){
	if(matrix[row-1][i] < 0){
		return 1;
	}
   }
   return 0;
}

//Function that returns an array with the row, column and pivot value

int* pivot(float **matrix, int row, int col)
{
     int ind_col_pivot;
     int ind_row_pivot;

     int *tab = (int *)malloc(2 * sizeof(int));


     //Initializing the pivot

     float pivot = matrix[row-1][0];


     //Find the pivot column

     for (int i = 1; i < col ; i++)
     {
         if (pivot < matrix[row-1][i])
         {
             pivot = matrix[row-1][i];
             ind_col_pivot=i;
         }
     }


     pivot = 10000000;


     //Find the pivot row

     for (int j = 0 ; j < row-1 ;j++)
     {
         if (matrix[j][ind_col_pivot] != 0){


         if (pivot > matrix[j][0]/matrix[j][ind_col_pivot]){

          pivot = matrix[j][0]/matrix[j][ind_col_pivot];
          ind_row_pivot =j ;

          }
      }
      }


      //We fill an array with the indices and the pivot value to use them later

      tab[0] = ind_row_pivot;
      tab[1] = ind_col_pivot;

      return tab;


}

void simplex_matrix(float **matrix, int row , int col)
{
    int row1;
    int column;

    int *p = pivot(matrix, row ,col );
    column = p[1];
    row1 = p[0];

    float pivot = matrix[row1][column];


    for(int i = 0; i < row ; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if (i != row1 && j != column ) 

                matrix[i][j] -= (matrix[i][column] * matrix[row1][j]) / pivot ;


        }

    }





}

void simplex_method(float **matrix, int row , int col , int *solution)
{
    int row1;
    int column;

    int *p = pivot(matrix, row ,col );


    column =p [1];
    row1 = p[0];

    float pivot = matrix[row1][column];


    solution[column-1] = row1;



    simplex_matrix(matrix, row, col);



    for(int i = 0; i < col; i++)
    {
            matrix[row1][i] = matrix[row1][i]/pivot;

    }
        for(int i = 0; i< row; i++)
    {
        if (i != row1)
            matrix[i][column] = 0;
    }


    displays(matrix , row , col) ;


    if (negative(matrix, row, col) )
        simplex_methode(matrix, row, col, solution);



}




int* pivot1(float **matrix,int row,int col)
{
     int ind_col_pivot;
     int ind_row_pivot;

     int *tab = (int *)malloc(2 * sizeof(int));


     //Initializing the pivot

     float pivot = matrix[row-1][0];



     //Find the pivot column

     for (int i = 1; i < col; i++)
     {
         if (pivot > matrix[row-1][i])
         {
             pivot = matrix[row-1][i];
             ind_col_pivot = i;
         }
     }


     pivot = 10000000;


     //Find the pivot line

     for (int j = 0; j < row-1; j++)
     {
         if (matrix[j][ind_col_pivot] != 0){

         if (pivot > matrix[j][0]/matrix[j][ind_col_pivot]){

          pivot = matrix[j][0]/matrix[j][ind_col_pivot];
          ind_row_pivot = j;

          }
      }
      }


      //We fill an array with the indices and the pivot value to use them later

      tab[0] = ind_row_pivot;
      tab[1] = ind_col_pivot;

      return tab;


}
void method_simplex1(float **matrix, int row, int col, int *solution)
{
     int row1;
     int column;

     int *p = pivot1(matrix,row,col);


     column = p[1];
     row1 = p[0];

     float pivot = matrix[row1][column];


     solution[column-1] = row1;



     simplex_matrix(matrix, row, col);


     for(int i = 0; i < col; i++)
     {
             matrix[row1][i] = matrix[row1][i]/pivot;

     }
         for(int i = 0; i< row; i++)
     {
         if (i != row1)
             matrix[i][column]=0;
     }

     int r=0, v=1, q=2;
     printf("%d",r);

     displays(matrix, row, col);

     printf("%d",v);


     if (positive(matrix,row,col) != 0)
         method_simplex1(matrix, row, col, solution);


     printf("%d",q);


}
void make_matrix_negative(float **matrix, int row, int col)
{
     int i, j;
     for (i = 0; i < row; i++)
     {
         for (j = 0; j < (row-col+1); j++)
         {
             matrix[i][j] *= -1;
         }
     }
}
