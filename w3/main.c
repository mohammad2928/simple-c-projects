#include <stdio.h>


int main(){
    int v[] = {1,3,7,1,0,1,9,3,1,0,0,1,3,3,3};
    int N = 15;
    maxOdd(v, N); 
    return 0;
}



void maxOdd(int v[], int N){
int max_odd_length = 0;
int temp_max = 0;
for(int i=0; i<N; i++){
    
    if (checkOdd(v[i]) == 0 ){
       if (temp_max > max_odd_length){
           max_odd_length=temp_max;
           temp_max = 0;
           }
    }
    else{temp_max++;}
}
printf("max_odd_length %d \n", max_odd_length);
int start = 0;
int end = 0;
temp_max = 0;
for (int i=0; i < N; i++){
    printf("temp_max %d \n", temp_max);
     if (checkOdd(v[i]) == 0 ){
       if (temp_max == max_odd_length){
           end = start + max_odd_length;
           printIntArray(v, start, end);
           temp_max = 0;
           }
        start = i+1;
    }
    else{temp_max++;}

}
printf("temp_max %d \n", temp_max);
if (temp_max == max_odd_length){
    end = start + max_odd_length;
    printIntArray(v, start, end);
    temp_max = 0;
    start = max_odd_length;
    }


}

void printIntArray(int array[], int start, int end){
   for(int i = start; i < end; i++){
      printf("%d ", array[i]);
   }
   printf("\n");
}


int checkOdd(int value){
    if (value%2 == 0)return 0; 
    return 1;
}