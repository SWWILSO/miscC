#include <stdio.h>

int gcd(int a, int b);

int gcd(int a, int b) {
    int quotient;
    quotient = a%b;
    //printf("%d\n", quotient);
    //printf("%d\n\n", b);
    if (quotient == 0) {
        return b;
    } else {
        return gcd(b, quotient);
    }
}

int main () {
    int x, y, g;
    printf("Enter two numbers:\n>> ");
    scanf("%d %d", &x, &y);
    g = gcd(x, y);
    printf("Greatest common divisor of %d and %d is %d\n", x, y, g);
    return 0;
}