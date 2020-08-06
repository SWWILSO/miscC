#include <stdlib.h>
#include <stdio.h>

typedef struct node node_t;

struct node {
    char node_id;
    node_t *vert;
    node_t *edge;
};

int main() {
    int vertices, i, j, edges;
    char v1, v2;

    node_t *startList, *newNode, *tmp1, *tmp2;
    printf("Enter number of vertices:\n>> ");
    scanf("%d", &vertices);

    startList = NULL;
    printf("Enter all vertex IDs as single chars:\n>> ");
    for (i=1; i <= vertices; i++) {
        if (startList == NULL) {
            newNode = malloc(sizeof(node_t));
            scanf(" %c", &newNode->node_id);
            startList = newNode;
            tmp1 = newNode;
            newNode->vert = NULL;
            newNode->edge = NULL;
        } else {
            newNode = malloc(sizeof(node_t));
            scanf(" %c", &newNode->node_id);
            newNode->vert = NULL;
            newNode->edge = NULL;
            tmp1->vert = newNode;
            tmp1 = newNode;
        }
    }

    printf("Enter the edges between vertices e.g 'A B'. Input '0 0' once complete.\n>> ");
    edges = vertices * (vertices-1);
    for (j=1; j <= edges; j++) {
        scanf(" %c %c", &v1, &v2);
        if (v1 == '0' && v2 == '0') {
            break;
        } 
        tmp1 = startList;
        while (tmp1 != NULL && tmp1->node_id != v1) {
            tmp1 = tmp1->vert;
        }
        if (tmp1 == NULL) {
            printf("Cannot find this vertex.\n");
            break;
        }
        tmp2 = tmp1;
        while (tmp2->edge != NULL) {
            tmp2 = tmp2->edge;
        }
        newNode = malloc(sizeof(node_t));
        newNode->node_id = v2;
        tmp2->edge = newNode;
        newNode->edge = NULL;
        newNode->vert = NULL;
    }

    printf("\n\nAdjacency list representation of graph is:\n");
    tmp1 = startList;
    while (tmp1 != NULL) {
        printf("%c |\t", tmp1->node_id);
        tmp2 = tmp1->edge;
        while (tmp2 != NULL) {
            printf("%c\t", tmp2->node_id);
            tmp2 = tmp2->edge;
        }
        printf("\n");
        tmp1 = tmp1->vert;
    }
}