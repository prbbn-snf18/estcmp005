//2) Faça um Programa que peça dois números e imprima o maior deles.

#include <stdio.h>
#include <stdlib.h>

int main() {

    int a, b = 0;
    printf("Digite dois numeros:\n");
    scanf("%d", &a);
    scanf("%d", &b);

    if(a>b){
        printf("\n%d", a);
    }else{
        printf("\n%d", b);
    }

    return 0;
}