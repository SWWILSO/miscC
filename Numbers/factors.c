#include <stdio.h>

int count_factors(int n);

int 
main() {
    int n = 15;
    printf("%d\n", count_factors(n));
}

int
count_factors(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n%i == 0) {
            count += 1;
        }
    }
    return count;
}