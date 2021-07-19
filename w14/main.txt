#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int searchSequence(int vet[], int n, int m){
    for(int i=0; i<=n-m;i++){
        int value = vet[i];
        int count = 0;
        for(int j=0; j<m;j++){
            if(value <= vet[i+j]){
                count++;
            }
            else{
                break;
            }
        }

        if (count == m){
            return i;
        }
    }
    return -1;

}

int main(){

    int vet[]={1,2,0,5,-1,0,5,6,13,4,7,9,10,22};
    int m=4;
    int n = sizeof(vet)/sizeof(int);
    int out = searchSequence(vet,n,m);
    printf("out is %d \n", out);

    return 0;
}
