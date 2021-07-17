#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void shift(char *str, int d, int index){
  for (int i = index; i <d; i++){
    *(str+i) = *(str+i+1);
  }
}

void removeSpaces(char *str){
    int len_str = strlen(str);
    for (int i = 0; i < len_str; i++){
      if (*(str+i) == ' '){
        shift(str, len_str, i);
      }
    }
    for (int i = 0; i < len_str; i++){
      printf("%c", *(str+i) );
    }
    printf("\n");
  }

int charErase(char str[], int pos[]){
    int max_number = 100000;
    int count = 0;
    for (int i=0; i<max_number; i++){
      if (pos[i] == -1) break;
      count++;
      str[pos[i]] = ' ';
    }
    removeSpaces(str);
    return count;
}

int main(){
    char str[] = "ThisIsAString";
    int pos[] = {7,4,2,0,11,-1};
    int count = charErase(str, pos);
    printf("the deleted count is: %d\n", count);
    return 0;
}