/*
Faça um Programa que peça a temperatura em graus Fahrenheit,
transforme e mostre a temperatura em graus Celsius.
C = 5 * ((F-32) / 9).
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    int a = 0;
    printf("Digite uma temperatura em farenheit para ser convertida em celsius:\n");
    scanf("%d", &a);
    
    a = 5 * ((a-32)/9);
    printf("%dC", a);
    return 0;
}