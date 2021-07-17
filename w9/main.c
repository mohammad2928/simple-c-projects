#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 5;

int check_in_array(int value, int array[]){
    int length =sizeof(array)/sizeof(int);
    printf("length %d\n", length);
    for(int i=0; i<length;i++){
        if (array[i] == value){
            return 1;
        }
    }
    return 0;
}


int sumFrames(int mat[MAXN][MAXN], int N, int *vet){
    int frams[N];
    int count =0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(check_in_array(mat[i][j], frams) != 1){
                frams[count] = mat[i][j];
                count++;
            }
        }
    }

    for(int i=0; i<count; i++){
        int count1 =0;
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                if (mat[j][k] == frams[i]){
                    count1++;
                } 
            }
        
        }
        *(vet+i) = count1;
    }

    for(int i = 0; i <count; i++){
        printf("%d ", *(frams+i));
    }
    printf("\n");
    
}

int main(){
    // assume 1,2,3 is a types of frames
    int N=5;
    int mat[MAXN][MAXN];

    for(int i=0; i<N;i++){
        mat[0][i] = 1;
        mat[N-1][i] = 1;
    }
    mat[1][0]=1; mat[1][1]=2; mat[1][2]=2; mat[1][3]=2; mat[1][4]=1;
    mat[3][0]=1; mat[3][1]=2; mat[3][2]=2; mat[3][3]=2; mat[3][4]=1;
    mat[2][0]=1; mat[2][1]=2; mat[2][2]=3; mat[2][3]=2; mat[2][4]=1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    int vet[3];
    sumFrames(mat, N, vet);
    printf("the number is ");
    for(int i=0; i<3; i++){
        printf("%d ", *(vet+i));
    }
    printf("\n");
    return 0;
}