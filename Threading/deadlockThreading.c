#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 10

pthread_mutex_t pop_mutex;
pthread_mutex_t push_mutex;

int stack[MAX];
int top = -1;

void *push (void *arg) {
    int n;
    pthread_mutex_lock(&push_mutex);
    sleep(2);
    pthread_mutex_lock(&pop_mutex);

    printf("Enter the value to push:\n>> ");
    scanf("%d", &n);

    top++;
    stack[top] = n;

    pthread_mutex_unlock(&pop_mutex);
    pthread_mutex_unlock(&push_mutex);

    printf("[+] %d has been pushed to stack\n", n);
    
    return NULL;
}

void *pop(void *arg) {
    int k;
    pthread_mutex_lock(&push_mutex);
    sleep(5);
    pthread_mutex_lock(&pop_mutex);

    k = stack[top];
    top--;
    
    printf("[+] %d has been popped from stack\n", k);
    pthread_mutex_unlock(&pop_mutex);
    pthread_mutex_unlock(&push_mutex);

    return NULL;
}

int main() {
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, &push, NULL);
    pthread_create(&tid2, NULL, &pop, NULL);
    printf("[+] Both threads have been created\n");

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}