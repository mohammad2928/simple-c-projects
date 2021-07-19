#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX = 25;

typedef struct {
    char surname[25], name[25];
    int id;
    float avg;
}student_t;


int roundNumber(float n ){
    printf("x is %d \n", (n - (int)n));
    if((n - (int)n) >= 0.5){
        return (int)n + 1;
    }
    return (int)n; 
}

int mostFrequent(student_t s[], int n){
    float avgs[n];
    for(int i=0; i<n; i++){
        avgs[i] = s[i].avg;
        avgs[i] = roundNumber(avgs[i]);
    }

    int max = 0 ;
    int out=0 ;
    for (int i=0; i<n; i++){
        int value = avgs[i];
        int count = 0;
        for (int i=0; i<n; i++){
            if (avgs[i] == value){
                count++;
                out = value;
            }
        }
        if (count > max){
            max = count;
        }
    }


    return out;


}

int main(){

    student_t s1;
    strcpy(s1.name, "x"); strcpy(s1.surname, "d"); s1.id=1;s1.avg=18.3;
    student_t s2;
    strcpy(s2.name, "xx"); strcpy(s2.surname, "dd"); s2.id=2;s2.avg=22.1;
    student_t s3;
    strcpy(s3.name, "xxx"); strcpy(s3.surname, "ddd"); s3.id=3;s3.avg=28.7;
    student_t s4;
    strcpy(s4.name, "xxxx"); strcpy(s4.surname, "dddd"); s4.id=3;s4.avg=21.9;
    student_t s[] = {s1,s2,s3,s4};
    int avg = mostFrequent(s,4);
    printf(" avg is %d\n", avg);

    return 0;
}