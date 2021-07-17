#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkVowel(char c){
    char vowels[] = "aAUuIiOoeE";
    int len_vowels = strlen(vowels);
    for (int i=0; i<len_vowels; i++){
        if (c == vowels[i]){
            return 1;
        }
    }
    return 0;

}

void countAndPrint(char str[], int n){
    int len_str = strlen(str);
    for (int i=0; i<len_str-n;i++){ 
        int count = 0;
        for(int j =i; j<i+n; j++){
            if (checkVowel(str[j]) == 1){
                count++;
            }
        }

        if (count == 2){
            for(int j =i; j<i+n; j++){
                printf("%c", str[j]);
            } 
            printf("\n");
        }
    }

}


int main(){
    char str1[] = "forExample";
    int n = 4;
    countAndPrint(str1, n);

    return 0;
}