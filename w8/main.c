#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isEqual(char *str1, char *str2){
    int d1 = strlen(str1), d2 = strlen(str2);
    for(int i = 0; i <d1; i++){
        if (*(str1+i) != *(str2+i)){
            return 0;
        }
    }
    return 1;
}


int isSubstring(char *str1, char *str2){
    if (strlen(str1) < strlen(str2))return 0;
    for (int i = 0; i <= strlen(str1)-strlen(str2); i++){
        char temp[strlen(str2)];
        for (int j = 0; j < strlen(str2); j++){
            temp[j] = *(str1+i+j);
        }
        if (isEqual(str2, temp) == 1){
            return 1;
        }
    }
    return 0;
}

int count(char *words[], int nwords, char *wordToSearch){

    int count1 = 0;
    for (int i=0; i<nwords; i++){
        if (isSubstring(*(words+i), wordToSearch) == 1){
            count1++;
        }
    }
    printf("count is %d\n", count1);
    return count1;

}


int main(int argc, char* argv[]){

    int nwords = argc-2;
    char *wordToSearch= *(argv+argc-1);
    printf("wordToSearch is %s \n", wordToSearch);
 
    char *words[argc];
    for (int i=0; i<nwords; i++){
        words[i] = argv[i+1];
    }

    for(int i = 0; i < nwords; i++)
    {
        printf("string = %s  with length %d \n", words[i], strlen(words[i]));
    }

    count(words, nwords, wordToSearch);
    return 0;
}