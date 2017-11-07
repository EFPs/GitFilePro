/* Name: Supanut Boat
 * ID: 5881050
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "queue.h"

void push(Queue **q, char *word) {
    // IMPLEMENT
    if(*q ==NULL){
        *q = malloc(sizeof(Queue));
        (*q)->head = NULL;
        (*q)->tail = NULL;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = (char *)malloc(sizeof(word));
    strcpy( newNode->data, word);
    //First Element in queue
    if((*q)->head == NULL){
        (*q)->head = newNode;
    } else{
        //Second element in queue
        if((*q)->tail == NULL){
            (*q)->head->next = newNode;
            (*q)->tail = newNode;
            //The rest
        } else{
            (*q)->tail->next = newNode;
            (*q)->tail = newNode;
        }

    }


}

char *pop(Queue *q) {
    // IMPLEMENT
    if((q)->head == NULL){
        return NULL;
    }


    Node *temp = q->head;
    if(q->head->next != NULL){
        q->head = q->head->next;
        //Last element
        if(q->head == q->tail){
            q->tail = NULL;
        }
    } else{
        q->head = NULL;
    }

    char *word = malloc(sizeof(temp->data));
    strcpy( word,temp->data);
    free(temp->data);
    free(temp);
    return word;
}

void print(Queue *q) {
    // IMPLEMENT
    if(q == NULL || q->head == NULL ){
        printf("%s\n","No items");
        return;
    }
    Node *temp = q->head;
    while(1){
        printf("%s\n",temp->data);
        if(temp->next ==NULL){
            break;
        } else{
            temp = temp->next;
        }
    }
}

int isEmpty(Queue *q) {
    // IMPLEMENT
    return q->tail==NULL && q->head == NULL;
}

void delete(Queue *q) {
    // IMPLEMENT
    Node *temp = q->head;
    q->head = NULL;
    while(1){
        free(temp->data);
        if(temp->next ==NULL){
            q->tail = NULL;
            break;
        } else{
            Node *temp2 = temp->next;
            free(temp);
            temp = temp2;
        }
    }
//    free(q);
//    q = NULL;
//    printf("%p\n",q);
}

/***** Expected output: *****
No items
a
b
c
a
b
c
d
e
f
No items
s = World
t = Hello
*****************************/
int main(int argc, char **argv)
{
    Queue *q = NULL;
    // print the queue
    print(q);
    // push items
    push(&q, "a");
    push(&q, "b");
    push(&q, "c");
    print(q);

    // pop items
    while (!isEmpty(q)) {
        char *item = pop(q);
        printf("%s\n", item);
        free(item);
    }

    char *item = pop(q);
    assert(item == NULL);

    // push again
    push(&q, "d");
    push(&q, "e");
    push(&q, "f");
    print(q);

    // destroy the queue
    delete(q);

    // print again
    print(q);

    // check copy
    char *s = (char *)malloc(10);
    strcpy(s, "Hello");
    push(&q, s);
    strcpy(s, "World");
    char *t = pop(q);
    printf("s = %s\n", s);
    printf("t = %s\n", t);
    free(t);
    free(s);

    // free the queue
    free(q);

}
