#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *next;
}; 
typedef struct node node_t;

void printlist(node_t *head) {
    node_t *temporary = head;

    while (temporary != NULL) {
        printf("%d - ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

//create a new node with input value
node_t *create_new_node(int value) {
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

//search for a value
node_t *find_node(node_t *head, int value) {
    node_t *tmp = head;
    while (tmp != NULL) {
        if (tmp->value == value) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

//insert new node after any given node
void insert_after_node(node_t *node_to_insert_after, node_t *newnode) {
    newnode->next = node_to_insert_after->next;
    node_to_insert_after->next = newnode;
}

int main() {
    node_t *n1, n2, n3;
    node_t *head;
    node_t *tmp;

    //memory and manual assign node values
    n1 = malloc(sizeof(node_t));
    n1->value = 1;
    n2.value = 5;
    n3.value = 10;

    //link nodes
    head = n1;
    n1->next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    //insert new node and redirect pointers (edges)
    node_t n4;
    n4.value = 18;
    n4.next = &n3;
    n2.next = &n4;

    //use function to create new nodes
    node_t *n5 = create_new_node(32);
    n3.next = n5;
    tmp = create_new_node(48);
    tmp->next = head;
    head = tmp;

    tmp = find_node(head, 18);
    printf("Found node with value %d\n", tmp->value);

    insert_after_node(tmp, create_new_node(80));

    printlist(head);

    return 0;
}