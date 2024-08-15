#include "utilidades.h"
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Retorna 1 se encontrou o número dentro do array, 0 caso contrário*/
int verifica_repeticao(int* array, int tamanho, int numero) {
    int i;
	for (i = 0; i < tamanho; i++) {
        if (array[i] == numero) {
            return 1; // Número encontrado
        }
    }
    return 0; // Número não encontrado
}

/* Imprime a quantidade de vezes que cada número aparece dentro do array*/
void confereRepeticoes(int vet[], int tam) {
    int jaforam[tam], foiQtd = 0;
    int i, j;
    for (i = 0; i < tam; i++) {
        if (verifica_repeticao(jaforam, foiQtd, vet[i]) == 0) {
            jaforam[foiQtd] = vet[i];
            foiQtd++;
            int repeticao = 0;
            for (j = 1; j < tam; j++) {
                if (vet[i] == vet[j]) {
                    repeticao++;
                }
            }
            printf("\nNum %d repetiu %d vezes\n", vet[i], repeticao);
        }
    }
}

/* Lê o arquivo de entrada e popula a tabela hash com os dados das empresas*/
void lerArquivo(const char* caminho, int maxLinhas) {
    FILE* arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    
    char linha[MAXCHAR];
    int linhasLidas = 0;

    while (fgets(linha, MAXCHAR, arq) && linhasLidas < maxLinhas) {
        /* Extrai o CNPJ do índice 1 ao 8*/
        char cnpj[9];
        strncpy(cnpj, linha + 1, 8);
        cnpj[8] = '\0';

        /* Extrai o nome do índice 12 até o primeiro caractere '"'*/
        char nome[MAXCHAR];
        int i = 12;
        int j = 0;
        while (linha[i] != '"' && linha[i] != '\0') {
            nome[j++] = linha[i++];
        }
        nome[j] = '\0';

        /* Linha de impressão dos dados lidos*/
        printf("Linha %d: ", linhasLidas + 1);
        printf("CNPJ: %s | ", cnpj);
        printf("Nome: %s\n", nome);

        /* Cria uma estrutura Empresa e preenche com os dados extraídos*/
        Empresa* emp = (Empresa*)malloc(sizeof(Empresa));
        strcpy(emp->cnpj, cnpj);
        strcpy(emp->nome, nome);
        sscanf(linha, "%*[^;];%*[^;];%[^;];%[^;];%[^;];%[^;];", emp->cod1, emp->cod2, emp->valor, emp->situacao);
        
        inserirTabelaHash(emp);
        linhasLidas++;
    }

    fclose(arq);
    printf("Leitura de %d linhas concluída.\n", linhasLidas);
}

/* Remove o caractere de nova linha ('\n') de uma string*/
void removerNovaLinha(char* str) {
    char* pos;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = '\0';
    }
}
