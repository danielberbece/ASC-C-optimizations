/*
 * Tema 2 ASC
 * 2019 Spring
 * Berbece Daniel
 */
#include "utils.h"
#include "cblas.h"

double* my_solver(int N, double *A, double *B) {
	printf("BLAS SOLVER\n");
	
	double *zerotr = (double *) calloc(N * N, sizeof(double));
	cblas_dsyr2k(CblasRowMajor, CblasUpper, CblasTrans, N, N, 1, A, N, B, N, 0, zerotr, N);
	
	double *rez = (double *) calloc(N * N, sizeof(double));
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, 1, zerotr, N, zerotr, N, 0, rez, N);
	
	free(zerotr);
	return rez;
}
