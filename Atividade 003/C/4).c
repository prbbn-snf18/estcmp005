/*
4) Faça um programa que resolva a MÉDIA DA UEA
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    float ap1, ap2 = 0;

    printf("Digite a primeira media (AP1): ");
    scanf("%f", &ap1);
    printf("\nDigite a segunda media (AP2): ");
    scanf("%f", &ap2);

    float mp, pf = 0;
    mp = (ap1 + ap2)/2;
    printf("\nMedia parcial: %.2f", mp);
    
    if (mp < 8){
        printf("\nDigite a nota da prova final:  ");
        scanf("%f", &pf);
        pf = ((mp * 2) + pf) / 3;
        printf("\nMedia final: %.2f", pf);

        if(pf > 6) printf("\nAprovado!");
        else printf("\nReprovado.");
    }else{
        printf("\nAprovado direto!");
    }

    return 0;
}