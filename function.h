#ifndef FUNCTION_H
#define FUNCTION_H

void full_process(double** matrix_left, double** matrix_right, int N);



void make_reflection(double** matrix_old, double** matrix_new, int N);

void refvecPRmatrix(double* refvec, double** matrix, int N);

void rev_gauss(double** right, double** left, int N);


double* reflection_vect(double* column, int N);
double* refvec_product(double* refvec, double* column, int N);



#endif
