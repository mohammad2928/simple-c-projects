
#include <stdio.h>
#include <string.h>

void printCharArray(char array[], int start, int end){
   for(int i = start; i < end; i++){
      printf("%c", array[i]);
   }
   printf("\n");
}

int similar(char str1[], char str2[], int start, int len_str2){
    int count = 0;
    int index = 0;
    for (int i = start; index < len_str2; i++,index++){
        if (str1[i] == str2[index]){ 
            count++;
        }
    }
    if (count >= len_str2/2){
        return 1;
    }
    return 0;
}


int strFindSimilar(char str1[], char str2[]){
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    int start = 0;
    while (start <= (len_str1-len_str2)){
        if (similar(str1, str2, start, len_str2) == 1){
            return start;
        }
        start++;
    }
    return -1;
    
}


int main(){
    char str1[] = "fifthOfNowember";
    char str2[] = "september";
    int l[] = {1, 2, 4, 6, 7};
    int l_length = sizeof(l)/sizeof(l[0]);
    printf("l length is %i\n", l_length); 
    int out = strFindSimilar(str1, str2);
    printf("The integer is: %d\n", out);
    return 0;
}