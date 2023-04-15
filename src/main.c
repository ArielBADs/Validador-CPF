#include <stdio.h>

int main() {
    int cpf[11], i, weight=10, remainder1, sum1=0, remainder2, sum2=0;
    
    // Recebe os 11 dígitos do CPF como entrada
    for (i = 0; i < 11; i++)
        scanf("%d", &cpf[i]);
    
    // Calcula o primeiro dígito verificador
    for (i = 0; i < 9; i++) {
        remainder1 = cpf[i] * weight;
        sum1 += remainder1;
        weight--;
    }
    
    sum1 = sum1 % 11;
    sum1 = 11 - sum1;
    
    if (sum1 > 9) {
        sum1 = 0;
    }
    
    weight = 10;
    
    // Calcula o segundo dígito verificador
    for (i = 1; i < 9; i++) {
        remainder2 = cpf[i] * weight;
        sum2 += remainder2;
        weight--;
    }
    
    sum2 = sum2 + (sum1 * 2);
    sum2 = sum2 % 11;
    sum2 = 11 - sum2;
    
    if (sum2 > 9) {
        sum2 = 0;
    }
    
    // Verifica se o CPF é válido ou inválido
    if (cpf[9] == sum1 && cpf[10] == sum2) { 
        printf("CPF válido: ");
        for (i = 0; i < 11; i++) {
            printf("%d", cpf[i]);
        }
    } else {
        printf("CPF inválido, o correto seria: ");
        for (i = 0; i < 9; i++) {
            printf("%d", cpf[i]);
        }
        printf("%d%d", sum1, sum2);
    }
    
    return 0;
}
