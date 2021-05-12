#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char objetivo[] = "METHINKS IT IS LIKE A WEASEL";
const char alfa[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

#define ESCOLHA (sizeof(alfa) - 1)
#define MUTAR 15 //aux na função mutar()
#define COPIES 30

int irand (int n){
    int r, randMax = RAND_MAX - (RAND_MAX % n);
    while((r = rand()) >= randMax);
    return r / (randMax / n);
}//Retorna inteiro aleatório de 0 até n - 1

int diferenca(const char *a, const char *b){
    int i, soma = 0;
    for (i = 0; a[i]; i++){
        soma += (a[i] != b[i]);
    }
    return soma;
}//Retorna o total de caracteres diferentes entre a e b

void mutar(const char *a, char *b){
    int i;
    for(i = 0; a[i]; i++){
        b[i] = irand(MUTAR) ? a[i] : alfa[irand(ESCOLHA)];
    }
    b[i] = '\0'; //null
}//b tem 1/MUTAR chances de ser diferente de a

int main(){
    int i, melhor_i, ruim, melhor = 0;
    char spec[COPIES][sizeof(objetivo) / sizeof(char)];

    for (i = 0; objetivo[i]; i++){
        spec[0][i] = alfa[irand(ESCOLHA)];
    }
    spec[0][i] = 0;

    do{
        for (i = 1; i < COPIES; i++){
            mutar(spec[0], spec[i]);
        }

        for (melhor_i = i = 0; i < COPIES; i++){
            ruim = diferenca(objetivo, spec[i]);
            if(ruim < melhor || !i){
                melhor = ruim;
                melhor_i = i;
            }
        }

        if (melhor_i) strcpy(spec[0], spec[melhor_i]);
        printf("Acertos: %d: %s\n", melhor, spec[0]);
    } while(melhor);

    return 0;
}