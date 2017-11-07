////
//// Created by Supanut Thongnumchima on 10/19/2017 AD.
////
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int cmpfunc( const void *a, const void *b) {
//    return *(char*)a - *(char*)b;
//}
//
////// Get copy of jum, and actual dict word. return boolean
//int sort_compare(char jum[],char dic[],int size){
//
//
//    //Sort jum
//    qsort(jum,size,sizeof(char),cmpfunc);
//
//    //compare with dic(already sorted)
//    if(strcmp(jum,dic) == 0){
//        //return 1 if same
//        return 1;
//    } else{
//        //return 0 if not same
//        return 0;
//    }
//}
//
//
////void printDic2D(char dic[][21],int lim ){
////    for(int i =0 ; i< lim;i++){
////        printf("%s\n",dic[i]);
////
////    }
////}
//
//
//
//char dict[500000][21];
//int dict_numLetters[500000];
//char dict_sort[500000][21];
//char jum[500000][21];
//
//////index 0 is the size of the col.
//int jumToDict[500000][500000];
//
//int main(int arg,char **argv){
//
//    if(arg < 3){
//        printf("%s","insert 2 argument");
//        return 0;
//    }
//
//    FILE *file= fopen(argv[1],"r");
//    FILE *file2 = fopen(argv[2],"r");
//
//    int vocabCount =0;
//    int jumCount =0;
//
//    int index =0 ;
//    char word[21];
//    while(fgets(word,21,file)!= NULL){
//
//        vocabCount+=1;
//        int count = 0;
//
//        for(int i =0;i<21;i++){
//
//            if(word[i] == '\n'){
//                word[i] = '\0';
//            }
//            if(word[i] == '\0'){
//                break;
//            }
//            count +=1 ;
//        }
//
//        strncpy(dict[index],word,21);
//        qsort(word,count,sizeof(char),cmpfunc);
//        strncpy(dict_sort[index],word,21);
//
//
//        dict_numLetters[index] = count;
//        index+=1;
//
//    }
//    //Get jum
//    index= 0;
//    while (fgets(word,21,file2)!= NULL){
//        jumCount+=1;
//        int numMatch = 1;
//        int count = 0;
//        for(int i =0;i<21;i++){
//
//            if(word[i] == '\n'){
//                word[i] = '\0';
//            }
//            if(word[i] == '\0'){
//                break;
//            }
//            count +=1 ;
//        }
//        strncpy(jum[index],word,21);
//        qsort(word,count,sizeof(char),cmpfunc);
//
//        for(int i = 0;i<=vocabCount;i++){
//            //find the vocab that have the same number of letters as jum
//
//            if(dict_numLetters[i] == count){
//                //if the same, keep the index of vocab corresponding to the index of jum
//                if(sort_compare(word,dict_sort[i],count) == 1){
//                    jumToDict[index][numMatch] = i;
//                    numMatch+=1;
//                }
//            }
//
//        }
//        jumToDict[index][0] = numMatch-1;
//        index+=1;
//    }
//
//    //Print out all the words
//    //Run through jumToDic, jum
//    for(int i=0 ; i<jumCount;i++){
//        //get the jum
//        strncpy(word,jum[i],21);
//        //get rid of \n
//
//        //check if there are any vocab corresponding to it
//        if(jumToDict[i][0] <=0){
//            //No word match
//            //Print then continue
//            printf("%s: %s\n",word,"NO MATCHES");
//        } else{
//
//            printf("%s: ",word);
//            //Get all index of dict, and print it
//            for(int j =1 ;j<=jumToDict[i][0];j++){
//                printf("%s ",dict[jumToDict[i][j]]);
//            }
//            printf("\n");
//        }
//    }
//
//
//    fclose(file);
//    fclose(file2);
//}
//
//
