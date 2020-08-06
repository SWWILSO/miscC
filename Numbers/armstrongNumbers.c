#include <stdio.h>
#include <math.h>

#define MAX 10

void push(int);
int pop();
int findArmstrong(int num);

int top = -1;
int stack[MAX];

void push(int m) {
    top++;
    stack[top] = m;
}

int pop() {
    int j;
    if (top == -1) {
        return (top);
    } else {
        j = stack[top];
        top--;
        return j;
    }
}

int findArmstrong(int num) {
    int j, remainder, temp, count, value;

    /* Add each digit to stack */
    temp = num;
    count = 0;
    while (num > 0) {
        remainder = num%10;
        push(remainder);
        count++;
        num = num/10;
    }

    /* Raise each digit to power of digit count */
    num = temp;
    value = 0;
    while (top >= 0) {
        j = pop();
        value = value + pow(j, count);
    }

    if (value == num) {
        return 1;
    } else {
        return 0;
    }

}

int main() {
    int n;
    printf("Enter a number:\n>> ");
    scanf("%d", &n);
    if (findArmstrong(n)) {
        printf("%d is an Armstrong number\n", n);
    } else {
        printf("%d is not an Armstrong number\n", n);
    }
    return 0;
}