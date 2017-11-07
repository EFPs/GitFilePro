#include <stdio.h>
#include <ctype.h>

int main() {


    int alpha[26];
    int keyAlpha[26];
    int key = 'a';
    //fill alpha with 0
    for(int i= 0 ; i < 26;i++){
        alpha[i]= 0;
        keyAlpha[i]= key;
        key++;
    }



    char line[10];
    while(fgets(line,10,stdin) != NULL ) {
        for (int i = 0; i < 10; i++) {
            char c = line[i];
            if (line[i] == '\0' || line[i] == EOF) {
                break;
            }
            if (!isalpha(c)) {
                continue;
            }
            if(!tolower(c)){
                printf("Can't change to lower alphabet");
            }
            c = tolower(c);
//            printf("%c\n",c);


            for(int j = 0 ; j<27;j++){
                if(keyAlpha[j] == c){
                    alpha[j] += 1;
                }
            }
        }


    }

    //Print
    int max = -1;
    for(int j =0; j <26;j++){
        if(max < alpha[j]){
            max = alpha[j];
        }
    }
    while(max > 0){
        for(int j =0; j <26;j++){
            if(max == alpha[j]){
                alpha[j] = alpha[j]-1;
                printf("*");
            } else{
                printf(" ");
            }
        }
        printf("\n");
        max = max-1;
    }
//    printf("\n");
    printf("abcdefghijklmnopqrstuvwxyz\n");

}
