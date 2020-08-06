int fibonacci_rec(int n) {
    if ((n==0) || (n==1)) {
        return n;
    } else {
        return fibonacci_rec(n-1) + fibonacci_rec(n-2);
    }
}