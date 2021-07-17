#include <stdio.h>
#include <stdlib.h>

void prodCartFilt(int *v1, int d1, int *v2, int d2){
    for (int i =0;i<d1;i++){
        for(int j=0;j<d2;j++){
            if (abs(*(v1+i) - *(v2+j))< 2){
                printf("%d %d \n", *(v1+i), *(v2+j));
            }
        }
    }
}


int main(){
    int v1[] = {1, 2, 3};
    int v2[] = {3, 4, 5, 6};
    int d1 = sizeof(v1)/sizeof(v1[0]);
    int d2 = sizeof(v2)/sizeof(v2[0]);
    prodCartFilt(v1, d1, v2, d2) ;
    return 0;
}