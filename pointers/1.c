#include <stdio.h>

int main(){
    int a = 25;
    int *ptr;
    printf("a is %d (a) \n ", a);
    ptr = &a;
    printf("a address is %p \n", ptr);
    printf("a value is %d \n", *ptr);
}