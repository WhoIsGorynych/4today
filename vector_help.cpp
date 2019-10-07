#include <stdio.h>
#include "math.h"
#include "vector_help.h"


//печать вектора
void print_vector(double* vect, int N){

  int i;

  for(i = 0; i < N; i++){
    printf("%lf ", vect[i]);
  }
  printf("\n");
}


//норма вектора
double norma(double* column, int k, int N){

  int i;
  double result = 0;

  for(i = k; i < N; i++){
    result += column[i] * column[i];
  }

  return sqrt(result);
}



double scalar(double* one, double* two, int k, int N){

  int i;
  double scalar = 0;

  for(i = k; i < N; i++){
    scalar += one[i] * two[i];
  }

  return scalar;
}





void vectXk(double* vect, double k, int j, int N){

  int i;


  for(i = j; i < N; i++){
    vect[i] = vect[i] * k;
  }
}



double* sum_vect(double* one, double* two, int N){

  int i;
  double* result;

  result = new double[N];
  for(i = 0; i < N; i++){
    result[i] = one[i] + two[i];
  }

  return result;
}
