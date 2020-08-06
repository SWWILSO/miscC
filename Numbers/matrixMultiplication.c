#include <stdio.h>

int main() {
    int matA[2][3], matB[3][4], matR[2][4];
    int aRow, aCol, bRow, bCol;
    int i, j, k;

    /* Input matrix dimensions */
    printf("Enter dimensions of matrix A:\n");
    scanf("%d", &aRow);
    scanf("%d", &aCol);
    printf("Enter dimensions of matrix B (aRow must equal bCol):\n");
    scanf("%d", &bRow);
    scanf("%d", &bCol);

    /* Input Matrix A */
    printf("Enter elements of first matrix size %d x %d\n", aRow, aCol);
    for (i=0; i<aRow; i++) {
        for (j=0; j<aCol; j++) {
            scanf("%d", &matA[i][j]);
        }
    }

    /* Input Matrix B */
    printf("Enter elements of second matrix size %d x %d\n", bRow, bCol);
    for (i=0; i<bRow; i++) {
        for (j=0; j<bCol; j++) {
            scanf("%d", &matB[i][j]);
        }
    }

    for (i=0; i<aRow; i++) {
        for (j=0; j<bCol; j++) {
            matR[i][j] = 0;
            for (k=0; k<3; k++) {
                matR[i][j] = matR[i][j]+matA[i][k]*matB[k][j];
            }
        }
    }

    printf("\n[+] First Matrix: \n");
    for (i=0; i<aRow; i++) {
        for (j=0; j<aCol; j++) {
            printf("%-4d", matA[i][j]);
        }
        printf("\n");
    }

    printf("\n[+] Second Matrix: \n");
    for (i=0; i<bRow; i++) {
        for (j=0; j<bCol; j++) {
            printf("%-4d", matB[i][j]);
        }
        printf("\n");
    }

    printf("\n[+] Output Matrix: \n");
    for (i=0; i<aRow; i++) {
        for (j=0; j<bCol; j++) {
            printf("%-4d", matR[i][j]);
        }
        printf("\n");
    }

    return 0;
}