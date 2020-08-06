#include <stdio.h>

#define MAX 10

int main() {
    static int edge[MAX][MAX], i, j, v1, v2, vertices;

    printf("Enter number of vertices (up to 9):\n>> ");
    scanf("%d", &vertices);
    
    printf("Enter the directed edges of graph. Input 0 0 when complete.\n>> ");
    for (i=1; i <= vertices*(vertices-1); i++) {
        scanf("%d %d", &v1, &v2);
        printf("%d %d\n", v1, v2);
        if (v1 == 0 && v2 == 0) {
            break;
        }
        edge[v1][v2] = 1;
        edge[v2][v1] = 1;
    }

    printf("\nDirected adjacency matrix:\n");
    for (i=1; i <= vertices; i++) {
        printf("\t%d", i);
    }

    printf("\n-------------------------------------------");
    if (vertices > 5) {
        printf("---------------------------------\n");
    } else {
        printf("\n");
    }

    for (i=1; i <= vertices; i++) {
        printf("%d |\t", i);
        for (j=1; j <= vertices; j++) {
            printf("%d\t", edge[i][j]);
        }
        printf("\n");
    }

    return 0;
}