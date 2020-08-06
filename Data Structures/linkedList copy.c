#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    list_t *list = make_empty_list();
    student_t student;
    node_t *head, *old_head;

    int i;
    while(scanf("%d",  &student.id) == 1) {
        for (i = 0; i < NUM_MARKS; i++) {
            scanf("%lf",  &student.marks[i]);
            }   
    insert_at_foot(list, student);
    }

head = list->head;
while(head) {
    printf("%d", head->data.id);
    for (i = 0; i < NUM_MARKS; i++) {
        printf(" %f",  head->data.marks[i]);
        }
    printf("\n");
    old_head = head;
    head = head->next;
    free(old_head);
    }
free(list);
return 0;
}