/*
 * Tema 2 ASC
 * 2019 Spring
 * Berbece Daniel
 */
#include <stdlib.h>
#include "utils.h"

double *addMatrix(int N, double *A, double *B) {
	int i, j;
	double *res = (double *)malloc(N * N * sizeof(double));

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			res[i * N + j] = A[i * N + j] + B[i * N + j];
		}
	}

	return res;
}


double *multiplyMatrix(int N, double *A, double *B) {
	int i, j, k;
	double *res = (double *)calloc(N * N, sizeof(double));

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				res[i * N + j] += A[i * N + k] * B[k * N + j];
			}
		}
	}

	return res;
}

double *transposeMatrix(int N, double *A) {
	int i, j;
	double *res = (double *)malloc(N * N * sizeof(double));

	for (i = 0; i < N; i++) {
		for (j = i; j < N; j++) {
			if(i == j) {
				res[i * N + j] = A[i * N + j];
			} else {
				res[i * N + j] = A[j * N + i];
				res[j * N + i] = A[i * N + j];
			}
		}
	}

	return res;
}

double *zerotr(int N, double *A) {
	int i, j;
	double *res = (double *)calloc(N * N, sizeof(double));

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if(i <= j)
				res[i * N + j] = A[i * N + j];
		}
	}

	return res;
}

double* my_solver(int N, double *A, double *B) {
	printf("NEOPT SOLVER\n");

	double *At = transposeMatrix(N, A);
	double *Bt = transposeMatrix(N, B);

	double *m1 = multiplyMatrix(N, At, B);
	double *m2 = multiplyMatrix(N, Bt, A);
	free(At); free(Bt);

	double *sum = addMatrix(N, m1, m2);
	free(m1); free(m2);

	double *triangM = zerotr(N, sum);
	free(sum);

	double *rez = multiplyMatrix(N, triangM, triangM);
	free(triangM);

	return rez;
}
