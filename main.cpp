#include <stdio.h>
#include "matrix_help.h"
//#include "vector_help.h"
//#include "function.h"
#include "function_v1.h"

int main(){

  int N = -1;
  double **matrix_old;
  double **matrix_new;


  printf("Hello!\n");
  printf("1 - matrix from file ('in.txt')\n");
  printf("2 - matrix from function\n");
  printf("Input mode: ");

  int input_mode;
  scanf("%d", &input_mode);



  if(input_mode == 1){
    FILE* file = fopen("in.txt", "r");
    matrix_old = matrix_read(file, N);
  }
  else if(input_mode == 2){
      printf("not ready yet");
      return -1;
  }

  matrix_new = identity_matrix(N);
/*
  full_process(matrix_old, matrix_new, N);

  printf("Answer: \n");
  matrix_print(matrix_old, N);
  matrix_print(matrix_new, N);

  rev_gauss(matrix_old, matrix_new, N);
*/
  Function(N, matrix_old, matrix_new);

  printf("Answer: \n");
  matrix_print(matrix_new, N);




}
