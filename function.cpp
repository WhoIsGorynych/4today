#include "vector_help.h"
#include "matrix_help.h"
#include "function.h"

//получить вектор отражения
double* reflection_vect(double* column, int N){

  int i;
  double* vect;
  double normal;

  vect = new double[N];

  for(i = 0; i < N; i++){
    vect[i] = column[i];
  }
  normal = norma(vect, N);

  vect[0] = vect[0] - normal;
  normal = 1 / norma(vect, N);

  vect = vectXk(vect, normal, N);

  return vect;
}


//произведение вектора отражения на вектор
double* refvec_product(double* refvec, double* column, int N){

  int i;
  double scal;
  double* result;
  double* vector;

  result = new double[N];
  vector = new double[N];

  for(i = 0; i < N; i++){
    vector[i] = refvec[i];
  }

  scal = scalar(refvec, column, N);
  vector = vectXk(vector, -2 * scal, N);

  result = sum_vect(vector, column, N);

  return result;
}


//умножение на матрицу вектора отражения
void refvecPRmatrix(double* refvec, double** matrix, int N){

  int i, j;
  double* column;
  double* vect;

  column = new double[N];
  vect = new double[N];

  for(i = 0; i < N; i++){
    column = get_col(matrix, i, N);
    vect = refvec_product(refvec, column, N);
    put_col(matrix, vect, i, N);
  }

}

//процесс отражения матриц
void make_reflection(double** matrix_left, double** matrix_right, int N){

  int i;
  double* reflection;

  reflection = new double[N];
  reflection = reflection_vect(get_col(matrix_left, 0, N), N);

  refvecPRmatrix(reflection, matrix_right, N);
  refvecPRmatrix(reflection, matrix_left, N);

}


//полный процесс
void full_process(double** matrix_left, double** matrix_right, int N){

  int i, j;
  double*** left;
  double*** right;

  left = new double**[N - 1];
  right = new double**[N - 1];

  for(i = 0; i < N-1; i++){
    right[i] = new double*[N - i];
    left[i] = new double*[N - i];
  }
  for(i = 0; i < N-1; i++){
    for(j = 0; j < N - i; j++){
      right[i][j] = new double[N - i];
      left[i][j] = new double[N - i];
    }
  }


  for(i = 0; i < N - 1; i++){

    right[i] = get_matrix(matrix_right, i, N);
    left[i] = get_matrix(matrix_left, i, N);

    printf("Iteration: %d", i);
    matrix_print(left[i], N - i);

    make_reflection(left[i], right[i], N - i);

    printf("After reflection: left\n");
    matrix_print(left[i], N - i);
    printf("After reflection: right\n");
    matrix_print(right[i], N - i);

    put_matrix(matrix_right, right[i], i, N);
    put_matrix(matrix_left, left[i], i, N);

    printf("After putting: left\n");
    matrix_print(matrix_left, N);
    printf("After putting: right\n");
    matrix_print(matrix_right, N);

  }
}


void rev_gauss(double** left, double** right, int N){

  int i, j, k;
  double element;

  for(k = 0; k < N; k++){
    for(i = N - 1; i >= 0; --i){
      element = right[i][k];
      for(j = i + 1; j < N; j++){
        element -= left[i][j] * right[j][k];
      }
      left[i][k] = element / left[i][i];

    }
  }


  matrix_print(left, N);
  matrix_print(right, N);
}
