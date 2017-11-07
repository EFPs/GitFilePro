#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//argv[0] = tabutil
//argv[1] = -d

//turn space to tap
void te(int n){
    char c;
    int spaceCount =0;
    while((c = (char)getchar()) != EOF ) {


        if(c == 0x20 ){
            spaceCount++;
            continue;
        } else{
            if (spaceCount==n){
                printf("\t");
                spaceCount = 0;
            }
            if(spaceCount > 0 ){
                for(int i = 0; i<spaceCount;i++){
                    printf("%c",' ');
                }
                spaceCount = 0;
            }
            if(c == '\t'){
                printf("%c",'\t');
                continue;
            }
            printf("%c",c);
        }
    }

}

//tap to space
void td(int n){
    char c;
    while((c=(char)getchar())!=EOF ) {
        if(c == '\t'){
            for(int i = 0 ; i< n;i++){
                printf("%c",' ');
            }
        } else{
            printf("%c",c);
        }
    }

}

int main(int arg,char **argv){
//    printf("%s",argv[2]);
    int n = atoi(argv[2]);
//    printf("%d",n);

    if(arg < 3 || arg > 3){
        printf("Put in 2 argument, plz");
    }


    if(strcmp(argv[1],"-d") == 0){
        td(n);
        printf("%c",'\n');
    }else if(strcmp(argv[1],"-e") == 0){
        //run -e
        te(n);
        printf("%c",'\n');

    }


}

