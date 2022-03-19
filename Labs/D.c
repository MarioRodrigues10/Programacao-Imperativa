#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//  máximo da memória RAM
signed long long max = 33554432;

// Array de Bools para o Mooshak não se queixar de ocupar demasiada memória
static bool vetor[33554432];


int triangulares(int x) {
  double teste1 = sqrt(8*x + 1);
  return (teste1 == (int)teste1);
}

int main() {
    // Algoritmo do Crivo de Eratóstenes (cria um array de True ou False com todos os primos)
    int raiz = sqrt(max);
    for (int i=2; i<=max; i++) {
        vetor[i]=true;
    }

    for (int i=2; i<=raiz; i++) {
        if (vetor[i]==true) {
            for (int j=i+i; j<=max; j+=i) {
                vetor[j]=false;
            }
        }
    }

// Parte normal: Receber 2 inputs e depois através de um ciclo for ver todos os números no intervalo que são
// ou triangulares ou primos.

    int x, y;
    if (scanf("%d %d", &x, &y) == 2) {
        int triangulares1 = 0;
        int primos = 0;
        for (int i = x; i <= y; i++) {
            if (triangulares(i)) triangulares1++;
            if (vetor[i]) primos++;
        }
        printf("%d %d\n", triangulares1, primos);
    }
    return 0;
}