/*
1) Faça um programa que receba dois números inteiros e gere os números
inteiros que estão no intervalo compreendido por eles.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b = 0;
    printf("Escreva dois números inteiros:\n");
    scanf("%d\n", a);

    if(a > b){
        for (int i = 0; i < (a-b); i++){
            printf("%d\n", (i + b));
        }
    }else if(b > a){
        for (int i = 0; i < (b-a); i++){
            printf("%d\n", (i + a));
        }
    }else{
        printf("%d\n", a-b);
    }

    return 0;
}