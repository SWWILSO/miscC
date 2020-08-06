#include <stdio.h>

int main() {

    int array;

    printf("Enter numbers: ");
    while (scanf("%d", &array)==1) {
        printf("%d |", array);
       for (int i = 0; i < array; i++) {
        printf("*");
        }
    printf("\n");
    }
    return 0;
}