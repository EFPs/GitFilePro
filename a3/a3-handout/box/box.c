/* Name: Supanut Boat
 * ID: 5881050
 */
#include <stdio.h>
#include <stdlib.h>
#include "box.h"


void createBox(Box **b, int init_cap) {
    if(*b != NULL){
        return;
    }
    *b= (Box *) malloc(sizeof(Box));

    (*b)->cap = init_cap;

    (*b)->size = 0;

    (*b)->data = malloc(sizeof(int)*init_cap);


    // IMPLEMENT
}

void insert(Box *b, int elem) {
    // IMPLEMENT

    if(b->size == b->cap){
        b->data = (int *)realloc(b->data,sizeof(int)*b->cap*2);
        b->cap *= 2;

        b->data[b->size] = elem ;
        b->size +=1;
    }else{
        b->data[b->size] =  elem;
        b->size +=1;
  }

}

void removeAll(Box *b, int elem) {
    int sizeReduction = 0;
    int countElementChecked = 0;
    for(int i =0 ; countElementChecked < b->size;i++){
      if(b->data[i] == elem){
        sizeReduction ++;

        //condencing
        for(int j =i;j<b->size-1;j++){
          b->data[j] = b->data[j+1];
        }
        i -=1;
      }
        countElementChecked++;
    }

    b->size -= sizeReduction;

}

void printBox(Box *b) {
    for(int i = 0 ;i<b->size;i++){
        printf("%d\n",b->data[i]);
    }
}

double getMean(Box *b) {
    // IMPLEMENT
    long allSum = 0;
    for(int i = 0 ;i<b->size;i++){
        allSum+= b->data[i];
    }
    return allSum/(double)b->size;
}

void dealloc(Box **b) {
    // IMPLEMENT

    free((*b)->data);
    free(*b);

}

/*
TEST: ./box < test.in
OUTPUT:
AVG = 4.00
box1 size = 10
box2 size = 1
box1 cap = 16
box2 cap = 2
-- b1
11
2
3
4
5
2
3
2
2
6
-- b2
2
--
-- b1 (after remove)
11
3
4
5
3
6
--
-- b2 (after remove)
--
*/
int main(int argc, char **argv)
{
    Box *b1 = NULL;
    Box *b2 = NULL;
    createBox(&b1, 1);
    createBox(&b2, 2);

//    printf("%s\n","Created Box");
//    fflush(stdout);
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int tmp;
        scanf("%d",&tmp);
        insert(b1, tmp);
//        printf("%s %d\n","Insert elem",i+1);
//        fflush(stdout);

    }
//    printf("%s\n","Done Insert elem");
//    fflush(stdout);
    insert(b2, 2);
//    printf("%s\n","Insert elem in b2");
//    fflush(stdout);

    printf("AVG = %0.2f\n",getMean(b1));
    printf("box1 size = %d\n",b1->size);
    printf("box2 size = %d\n",b2->size);
    printf("box1 cap = %d\n",b1->cap);
    printf("box2 cap = %d\n",b2->cap);

    printf("-- b1\n");
    printBox(b1);
    printf("-- b2\n");
    printBox(b2);
    printf("--\n");

    removeAll(b1, 2);
    printf("-- b1 (after remove)\n");
    printBox(b1);
    printf("--\n");
    removeAll(b2, 2);
    printf("-- b2 (after remove)\n");
    printBox(b2);
    printf("--\n");

    dealloc(&b1);
    dealloc(&b2);
}
