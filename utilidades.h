#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "hash.h"

#define MAXCHAR 1000
#define TAMANHO_TABELA 10007 /* Tamanho da tabela hash */

/* Retorna 1 se encontrou o número dentro do array, 0 caso contrário*/
int verifica_repeticao(int* array, int tamanho, int numero);

/* Imprime a quantidade de vezes que cada número aparece dentro do array*/
void confereRepeticoes(int vet[], int tam);

/* Lê o arquivo de entrada e popula a tabela hash com os dados das empresas*/
void lerArquivo(const char* caminho, int maxLinhas);

/* Remove o caractere de nova linha ('\n') de uma string*/
void removerNovaLinha(char* str);

#endif
