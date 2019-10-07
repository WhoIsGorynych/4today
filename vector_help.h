#ifndef VECTOR_HELP_H
#define VECTOR_HELP_H



#include <stdio.h>

void print_vector(double* vect, int N);


double norma(double* column, int k, int N);
double scalar(double* one, double* two, int k, int N);


void vectXk(double* vect, double k, int j, int N);
double* sum_vect(double* one, double* two, int N);



#endif
