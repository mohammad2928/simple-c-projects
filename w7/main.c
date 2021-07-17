#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAXM = 5;

int isEqual(char *str1, char *str2){
    int d1 = strlen(str1), d2 = strlen(str2);
    for(int i = 0; i <d1; i++){
        if (*(str1+i) != *(str2+i)){
            return 0;
        }
    }
    return 1;
}

int count(char A[][MAXM], int n, int m, char str[]){
    int len_str = strlen(str);
    int count1 = 0;
    

    // check horizontally 
    for(int i=0; i<n; i++){
        for(int j=0; j<=m-len_str; j++){
            char temp[len_str];
            for (int k=0; k<len_str; k++){
                temp[k] = A[i][j+k];
            }

            if (isEqual(temp, str) == 1){
                count1++;
            }
        }
    }
    // check vertically
    for(int i=0; i<=n-len_str; i++){
        for(int j=0; j<m; j++){
            char temp[len_str];
            for (int k=0; k<len_str; k++){
                temp[k] = A[i+k][j];
            }
            if (isEqual(temp, str) == 1){
                count1++;
            }
        }
    }
    printf("count is %d \n", count1);
    return count1;
}

int main(){
    int n = 4;
    int m = 5;
    char str[] = "cat";
    char a1[] = "xceca";
    char a2[] = "waecq";
    char a3[] = "dtpaz";
    char a4[] = "pcatf";
    char A[4][5];
    for(int i = 0; i <m; i++){
        A[0][i] = a1[i];
    }

    for(int i = 0; i <m; i++){
        A[1][i] = a2[i];

    }
    for(int i = 0; i <m; i++){
        A[2][i] = a3[i];
    }
    for(int i = 0; i <m; i++){
        A[3][i] = a4[i];
    }
    count(A,n,m,str);
    return 0;
}