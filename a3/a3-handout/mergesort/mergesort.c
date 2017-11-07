/* Name: Supanut Boat
 * ID: 5881050
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.h"

void print(Entry *t,int n){
    for(int i =0 ; i< n ;i++){
        printf("%d %s\n",t[i].data,t[i].name);
    }
}

void merge(Entry *output, Entry *L, int nL, Entry *R, int nR) {
    // IMPLEMENT
//    printf("%s\n","Merging");
    int i = 0,j = 0,k = 0;
    while(k<(nL+nR)){

        if( j >= nR || ( (i < nL)&&(L[i].data < R[j].data) ) ){
            output[k].data = L[i].data;
            output[k].name = L[i].name;
            i++;
        } else{
            output[k].data = R[j].data;
            output[k].name = R[j].name;
            j++;
        }
        k++;
    }
}



void split(Entry *a,Entry *subA,int f,int t){
    int aIndex = f;
    for(int i =0 ; aIndex <= t;i++){
        subA[i].data =  a[aIndex].data;
        subA[i].name = malloc(sizeof(char)*MAX_NAME_LENGTH);
        strcpy(subA[i].name,a[aIndex].name);
        aIndex++;
    }

}

void merge_sort(Entry *entries, int n) {
    // IMPLEMENT
    if(n>1){
        //Split array
        int nL,nR;
        //Odd
        if(n%2 != 0){
            nL = n/2;
            nR = nL+1;
        } else{
            //even
            nL = n/2;
            nR = nL;
        }

        Entry *L = malloc(sizeof(Entry) *nL);
//        printf("%s\n","Split L");
        split(entries,L,0,nL-1);


        Entry *R = malloc(sizeof(Entry) *nR);
//        printf("%s\n","Split R");
        split(entries,R,nL,n-1);


        Entry *temp = malloc(sizeof(Entry) * n);

        for(int i =0;i<n ;i ++){
            temp[i].name = malloc(sizeof(char) * MAX_NAME_LENGTH);
        }

//        printf("%s\n","Merge_sort L");
        merge_sort(L,nL);
//        printf("%s\n","Merge_sort R");
        merge_sort(R,nR);
//        printf("%s\n","Merge LR");
        merge(temp,L,nL,R,nR);
//        for(int i = 0 ; i < nL;i++){
//            free(L[i].name);
//        }
        free(L);
//        for(int i = 0 ; i < nR;i++){
//            free(R[i].name);
//        }
        free(R);
        for(int i =0;i<n ;i ++){
            entries[i].data = temp[i].data;
//            printf("%s %d\n","Copied data",temp[i].data);
            strcpy(entries[i].name,temp[i].name);
//            printf("%s\n","Copied name");
            free(temp[i].name);
        }

        free(temp);


    }
}

/*
TEST: ./mergesort < test.in
OUTPUT:
1 lsdfjl
2 ghijk
3 ksdljf
5 abc
6 def
*/
int main(void) {
    // IMPLEMENT
    int n;

    scanf("%d",&n);
    Entry *allEntry = NULL;
    allEntry = malloc(sizeof(Entry)*n);
    for(int i = 0; i < n;i++){

        allEntry[i].name = malloc(sizeof(char)*MAX_NAME_LENGTH);
        scanf("%d",&allEntry[i].data);
        fgets(allEntry[i].name,MAX_NAME_LENGTH,stdin);

    }
    merge_sort(allEntry,n);

    for(int i= 0 ; i<n;i++){
        printf("%d %s",(allEntry[i]).data,(allEntry[i]).name);
        free((allEntry[i]).name);
    }
    free(allEntry);
}
