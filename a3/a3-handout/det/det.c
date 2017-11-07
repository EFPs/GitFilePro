#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int **mat,int n){
    for(int i = 0;i<n;i++){
        for(int j = 0; j<n ;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void subMat(int**a,int **t,int n,int xi,int xj ){
    int ti = 0;
    int tj = 0;
    for(int i = 0; i<n;i++){
        if(i == xi){
            continue;
        }
        t[ti] = malloc(sizeof(int)*(n-1));
        for(int j=0;j<n;j++){

            if(j == xj){
                continue;
            }
//            printf("%d\n",a[i][j]);
//            printf("%d %d\n",ti ,tj);
            t[ti][tj] = a[i][j];
            tj++;
        }
        tj = 0;
        ti++;
    }

//    printf("%s\n","Sub Gets");
//    print(t,n-1);
}

double recurMat(int **a, int n,int ans){
//    print(a,n);
    if(n <= 1){
        return a[0][0];
    } else{
        double newAns = 0 ;
        int i =0;
        int xi = i;
        for(int j = 0 ; j < n ; j++){
            int xj = j;
            int lead = a[xi][xj];
            int **temp = (int **)malloc(sizeof(int *)*(n-1));
            subMat(a,temp,n,xi,xj);
            if(j%2 == 0){
                newAns += lead*recurMat(temp,n-1,ans);
            } else{
                newAns -= lead*recurMat(temp,n-1,ans);
            }

            for(int i = 0 ; i < n-1 ; i++){
                free(temp[i]);
            }
            free(temp);

        }
        return newAns;
    }
}

double compute_det(int **a, int n) {
  // implement this
    return recurMat(a,n,0);

}

/*
TEST: ./det < det.in
OUTPUT:
-105.00000
*/
int main(void) {
  // implement this
    int n;
    scanf("%d",&n);
    int **mat = NULL;
    mat = (int **)malloc(sizeof(int *)*n);

    for(int i = 0;i<n;i++){
        mat[i] = (int *)malloc(sizeof(int) * n);
        for(int j = 0; j<n ;j++){
            scanf("%d",&mat[i][j]);
        }
    }
//    print(mat,n);
//    printf("%.5f\n",2.1234567);
    printf("%.5f\n",compute_det(mat,n));
    for(int i = 0;i<n;i++){
        free(mat[i]);
    }
    free(mat);

}
