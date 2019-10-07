#ifndef MATRIX_HELP_H
#define MATRIX_HELP_H



#include <stdio.h>

double** matrix_read(FILE* file, int &N);

void matrix_print(double** matrix, int N);


void put_row(double** matrix, double* vect, int k, int N);
void put_col(double** matrix, double* vect, int k, int N);
double* get_row(double** matrix, int k, int N);
double* get_col(double** matrix, int k, int N);
double* get_horizon(double** matrix, int k, int k1, int k2);
double* get_vertical(double** matrix, int k, int k1, int k2);
void put_horizon(double** matrix, double* vector, int k, int k1, int k2);
void put_vertical(double** matrix, double* vector, int k, int k1, int k2);

void lineXk(double** matrix, double k, int i, int j, int N);

double** identity_matrix(int N);


void put_matrix(double** matrix, double** result, int k, int N);
double** get_matrix(double** matrix, int k, int N);
#endif
