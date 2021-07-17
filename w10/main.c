#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int MAXN=4;
const int MAXM=3;

int max_index(int score[], int n){
    int max=0;
    for(int i=0; i<n;i++){
        if (score[i]>max){
            max = score[i];
        }
    }

    for(int i=0; i<n;i++){
        if (score[i]==max){
            return i;
        }
    }
}

void displRanking(int C[MAXN][MAXM], int n, int m){
    int score[n];
    for (int i=0; i<n;i++){
        score[i] = 0;
    }

    int leading[m];
    for (int i=0; i<m;i++){

       for (int j=0; j<n;j++){
           score[j] = score[j] + C[j][i]; 
       }

       leading[i] = max_index(score, n);

    }

    printf("The leading team in each of the %d matchdays is: ", m);
    for (int i=0; i<m; i++){
        printf("%d ", leading[i]);
    }
    printf("\n");

}

int main(){
    int n=4;
    int m=3;
    int C[n][m];
    C[0][0]=3; C[0][1]=1; C[0][2]=0;
    C[1][0]=0; C[1][1]=1; C[1][2]=1;
    C[2][0]=1; C[2][1]=1; C[2][2]=1;
    C[3][0]=1; C[3][1]=1; C[3][2]=3;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    displRanking(C, n, m);
    return 0;
}