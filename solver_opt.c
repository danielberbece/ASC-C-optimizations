/*
 * Tema 2 ASC
 * 2019 Spring
 * Berbece Daniel
 */
#include "utils.h"

double *addMatrix(int N, double *A, double *B) {
	register int i, j;
	register double *res = (double *)calloc(N * N, sizeof(double));

	for (i = 0; i < N; i++) {
		register double *pa = &A[i * N + i];
		register double *pb = &B[i * N + i];
		register double *pres = &res[i * N + i];
		for (j = i; j < N; j++) {
			*pres = *pa + *pb;
			pa++;
			pb++;
			pres++;
		}
	}

	return res;
}


double *multiplyMatrix(int N, double *A, double *B) {
	register int i, j, k;
	register double *res = (double *)calloc(N * N, sizeof(double));

	for (k = 0; k < N; k++) {
		for (i = 0; i < N; i++) {
			register double *pa = &A[i * N + k];
			register double *pb = &B[k * N];
			register double *pres = &res[i * N];
			for (j = 0; j < N; j++) {
				*pres += *pa * *pb;
				pres++;
				pb++;
			}
		}
	}

	return res;
}

double *transposeMatrix(int N, double *A) {
	register int i, j;
	register double *res = (double *)malloc(N * N * sizeof(double));

	for (i = 0; i < N; i++) {
		register double *pa = &A[i * N + i];
		register double *pres = &res[i * N + i];
		register double *revpa = pa;
		register double *revpres = pres;
		for (j = i; j < N; j++) {
			if(i == j) {
				*pres = *pa;
			} else {
				*pres = *revpa;
				*revpres = *pa;
			}
			pa++;
			pres++;
			revpres += N;
			revpa += N;
		}
	}

	return res;
}

double* my_solver(int N, double *A, double *B) {
	printf("OPT SOLVER\n");

	register double *At = transposeMatrix(N, A);
	register double *Bt = transposeMatrix(N, B);

	register double *m1 = multiplyMatrix(N, At, B);
	register double *m2 = multiplyMatrix(N, Bt, A);
	free(At); free(Bt);

	register double *sum = addMatrix(N, m1, m2);
	free(m1); free(m2);

	register double *rez = multiplyMatrix(N, sum, sum);
	free(sum);

	return rez;
}
