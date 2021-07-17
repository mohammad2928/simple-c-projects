#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXR = 3;
const int MAXC =5;

int buildMatrix(int V[], int N, int M[MAXR][MAXC], int nr, int nc){
    int number_of_elements = 0;
    for(int i=0; i<N; i++){
        if (i%2!=0){
            number_of_elements = number_of_elements + V[i];
        }
    }
    if (number_of_elements != nr*nc){
        return 0;
    }

    int values[nr*nc];
    int start = 0;
    for(int i=0; i<N; i+=2){
        for(int j=0; j<V[i+1]; j++){
            values[start] = V[i];
            start++;
        }
    }

    int index = 0; 
    for(int i=0; i<nr;i++){
        for(int j=0; j<nc;j++){
            M[i][j] = values[index];
            index++;
        }
    }

    for(int i=0; i<nr;i++){
        for(int j=0; j<nc;j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    return 1;

}

int main(){
    int nr = 3;
    int nc = 5;
    int M[nr][nc];
    int N = 14;
    int V[]={1,2,17,2,3,1,8,4,6,1,7,3,5,2};
    int result = buildMatrix(V, N, M, nr, nc);
    printf("reslut is %d \n", result);
    return 0;
}