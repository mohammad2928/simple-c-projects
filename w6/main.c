#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int *array, int d){
    for(int i=0; i <d; i++){
        for(int j=i; j <d; j++){
            if (*(array+i) > *(array+j)){
                int temp = *(array+i);
                *(array+i) = *(array+j);
                *(array+j) = temp;
            }
        }
    }
}

void prodCartOrd(int *v1, int d1, int *v2, int d2){
    sort(v1,d1);
    sort(v2,d2);
    int max_value = *(v1) + *(v2);
    int final = *(v1+d1-1)+*(v2+d2-1);
    while(max_value <= final){
        for (int i=0; i<d1; i++){
            for (int j=0; j<d2; j++){
                if ((*(v1+i) + *(v2+j)) == max_value){
                    printf("%d %d \n", *(v1+i), *(v2+j));
                }
            
            }
         } 

        max_value ++;
    }

}


int main(){
    int v1[] = {2, 1, 3};
    int v2[] = {4, 5, 3, 6};
    int d1 = sizeof(v1)/ sizeof(int);
    int d2 = sizeof(v2)/ sizeof(int); 
    printf("d1 %d d2 %d \n", d1,d2);
    prodCartOrd(v1, d1, v2, d2);
    return 0;
}