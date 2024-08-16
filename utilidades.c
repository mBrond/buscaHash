#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>

/* Retorna 1 se achou o número dentro do array */
int verifica_repeticao(int* array, int tamanho, int numero) {
    int i;
    for (i = 0; i < tamanho; i++) {
        if (array[i] == numero) {
            return 1; /* Número encontrado */
        }
    }
    return 0; /* Número não encontrado */
}

/* Printa a quantidade de vezes que cada número aparece dentro do array */
void confereRepeticoes(int vet[], int tam) {
    int i, j, repeticao = 0, foiQtd = 0;
    int jaforam[tam]; /* Array para armazenar números já verificados */

    for (i = 0; i < tam; i++) {
        if (verifica_repeticao(jaforam, foiQtd, vet[i]) == 0) {
            jaforam[foiQtd] = vet[i];
            foiQtd++;
            for (j = 1; j < tam; j++) {
                if (vet[i] == vet[j]) {
                    repeticao++;
                }
            }
            printf("\nNum %d repetiu %d vezes\n", vet[i], repeticao);
            repeticao = 0;
        }
    }
}
