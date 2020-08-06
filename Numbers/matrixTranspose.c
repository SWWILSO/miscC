#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("Enter number of rows and columns in matrix:\n>> ");
    scanf("%d %d", &rows, &cols);

    int *address, m;

    address = (int *)malloc(rows * cols * sizeof(int));
    printf("Enter elements of %d x %d matrix:\n", rows, cols);

    for (int i=0; i<rows; ++i) {
        for (int j=0; j<cols; ++j) {
            scanf("%d", &m);
            *(address + i*cols + j) = m;
        }
    }

    printf("\nMatrix transpose is:\n");
    for (int i=0; i<rows; ++i) {
        for (int j=0; j<cols; ++j) {
            printf("%-6d", *(address + j*cols + i));
        }
        printf("\n");
    }
    return 0;
}