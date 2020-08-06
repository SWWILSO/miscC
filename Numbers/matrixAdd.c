//matrix addition

#include <stdio.h>

#define SIZE 5

typedef double vector_t[SIZE];
typedef vector_t sqmatrix_t[SIZE];

void vector_add(vector_t A, vector_t B, vector_t C, int n);
void sqmatrix_add1(sqmatrix_t A, sqmatrix_t B, sqmatrix_t C, int n);
void sqmatrix_add2(vector_t A[], vector_t B[], vector_t C[], int n);

int
main(int argc, char *argv[]) {

	vector_t A, B;
	sqmatrix_t C;
	int i;

	for (i=0; i<SIZE; i++) {
		A[i] = 0.5*i;
		B[i] = 1.0/(i+1);
	}
	vector_add(A, B, C[0], SIZE);
	for (i=1; i<SIZE; i++) {
		vector_add(A, C[i-1], C[i], SIZE);
	}
	sqmatrix_add2(C, C, C, SIZE);
	{ int j;
		for (i=0; i<SIZE; i++) {
			for (j=0; j<SIZE; j++) {
				printf("%6.3f  ", C[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

void
vector_add(vector_t A, vector_t B, vector_t C, int n) {
	int i;
	for (i=0; i<n; i++) {
		C[i] = A[i] + B[i];
	}
}

void
sqmatrix_add1(sqmatrix_t A, sqmatrix_t B, sqmatrix_t C,
		int n) {
	int i,j;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

void
sqmatrix_add2(vector_t A[], vector_t B[], vector_t C[],
		int n) {
	int i;
	for (i=0; i<n; i++) {
		vector_add(A[i], B[i], C[i], n);
	}
}