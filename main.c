#include "utilidades.h"
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Estrutura para armazenar os dados de uma empresa */
/* Para lidar com colisões na tabela hash */
/*
#define TAMANHO_TABELA 10007 /* Tamanho da tabela hash */
/*
typedef struct Empresa {
    char cnpj[20];
    char nome[MAXCHAR];
    char cod1[10];
    char cod2[10];
    char valor[20];
    char situacao[5];
    struct Empresa* proximo; 
} Empresa;

Empresa* tabelaHashCNPJ[TAMANHO_TABELA];
Empresa* tabelaHashNome[TAMANHO_TABELA];
*/

#define MAXCHAR 1000
const char* caminhoArquivo = "C:\\Users\\lucas\\Desktop\\POD\\buscaHash\\dados.txt";

/* Função auxiliar para limpar o formato do CNPJ (remover pontos e traços) */
void limparFormatoCNPJ(char* cnpj) {
    char cnpjLimpo[20];
    int i, j = 0;
    for (i = 0; cnpj[i] != '\0'; i++) {
        if (cnpj[i] >= '0' && cnpj[i] <= '9') {
            cnpjLimpo[j++] = cnpj[i];
        }
    }
    cnpjLimpo[j] = '\0';
    strcpy(cnpj, cnpjLimpo);
}

/* Função para remover espaços extras e aspas duplas de um nome */
void limparNome(char* nome) {
    char nomeLimpo[MAXCHAR];
    int i, j = 0;
    for (i = 0; nome[i] != '\0'; i++) {
        if (nome[i] != '"' && nome[i] != ' ') {  /*Ignora aspas duplas e espaços*/
            nomeLimpo[j++] = nome[i];
        }
    }
    nomeLimpo[j] = '\0';
    strcpy(nome, nomeLimpo);
}

/* Função para transformar todos os caracteres em minúsculos */
void converterParaMinusculo(char* str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

/* Insere uma empresa na tabela hash, tanto pela chave CNPJ quanto Nome */
/* Limpa o formato do CNPJ antes de inserir */
/*
void inserirTabelaHash(Empresa* emp) {
    limparFormatoCNPJ(emp->cnpj); 
    unsigned int indiceCNPJ = calculoCnpj(emp->cnpj);
    unsigned int indiceNome = calculoNome(emp->nome);

    emp->proximo = tabelaHashCNPJ[indiceCNPJ];
    tabelaHashCNPJ[indiceCNPJ] = emp;

    emp->proximo = tabelaHashNome[indiceNome];
    tabelaHashNome[indiceNome] = emp;
}

*/

/* Busca uma empresa na tabela hash usando o CNPJ como chave */
/* Limpa o formato do CNPJ antes de buscar */
/* Empresa encontrada */
/* Empresa não encontrada */
/*
Empresa* buscarTabelaHashCNPJ(char* cnpj) {
    limparFormatoCNPJ(cnpj); 
    unsigned int indice = calculoCnpj(cnpj);
    Empresa* emp = tabelaHashCNPJ[indice];
    while (emp != NULL) {
        if (strcmp(emp->cnpj, cnpj) == 0) {
            return emp; 
        }
        emp = emp->proximo;
    }
    return NULL; 
}
*/


/* Busca uma empresa na tabela hash usando o Nome como chave */
/* Empresa encontrada */
/* Empresa não encontrada */
/*
Empresa* buscarTabelaHashNome(char* nome) {
    unsigned int indice = calculoNome(nome);
    Empresa* emp = tabelaHashNome[indice];
    while (emp != NULL) {
        if (strcmp(emp->nome, nome) == 0) {
            return emp; 
        }
        emp = emp->proximo;
    }
    return NULL; 
}
*/


/* Lê o arquivo de entrada e popula a tabela hash com os dados das empresas */
/* Extrai o CNPJ do índice 1 ao 8 */
/* Limpa o formato do CNPJ extraído */
/* Extrai o nome do índice 12 até o primeiro caractere '"' */
/* Linha de impressão para depuração */
/* Cria uma estrutura Empresa e preenche com os dados extraídos */
/*
void lerArquivo(const char* caminho, int maxLinhas) {
    FILE* arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    
    char linha[MAXCHAR];
    int linhasLidas = 0;

    while (fgets(linha, MAXCHAR, arq) && linhasLidas < maxLinhas) {
        char cnpj[20];
        sscanf(linha, "%19[^;];", cnpj);
        limparFormatoCNPJ(cnpj); 

        
        char nome[MAXCHAR];
        int i = 12;
        int j = 0;
        while (linha[i] != '"' && linha[i] != '\0') {
            nome[j++] = linha[i++];
        }
        nome[j] = '\0';

        
        printf("Linha %d: ", linhasLidas + 1);
        printf("CNPJ: %s | ", cnpj);
        printf("Nome: %s\n", nome);

        
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
*/

/* Remove o caractere de nova linha ('\n') de uma string */
void removerNovaLinha(char* str) {
    char* pos;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = '\0';
    }
}

/* Função para buscar e exibir os dados de uma empresa usando o CNPJ no arquivo */
void buscarPorCNPJNoArquivo(const char* caminho, const char* cnpj) {
    FILE* arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    
    char linha[MAXCHAR];
    int encontrado = 0;
    char cnpjBusca[20];
    strcpy(cnpjBusca, cnpj);
    limparFormatoCNPJ(cnpjBusca); /* Limpa o formato do CNPJ para busca */
    
    while (fgets(linha, MAXCHAR, arq)) {
        char cnpjArquivo[20];
        sscanf(linha, "%19[^;];", cnpjArquivo);
        limparFormatoCNPJ(cnpjArquivo); /* Limpa o formato do CNPJ extraído */

        if (strcmp(cnpjArquivo, cnpjBusca) == 0) {
            char nome[MAXCHAR];
            char cod1[10], cod2[10], valor[20], situacao[5];
            
            sscanf(linha, "%*[^;];%[^;];%[^;];%[^;];%[^;];%[^;];", nome, cod1, cod2, valor, situacao);
            
            printf("Dados para CNPJ %s:\n", cnpj);
            printf("Nome: %s\n", nome);
            printf("Codigo 1: %s\n", cod1);
            printf("Codigo 2: %s\n", cod2);
            printf("Valor: %s\n", valor);
            printf("Situacao: %s\n", situacao);
            
            encontrado = 1;
            break;
        }
    }
    
    if (!encontrado) {
        printf("CNPJ não encontrado.\n");
    }
    
    fclose(arq);
}

/* Função para buscar e exibir os dados de uma empresa usando o Nome no arquivo */
void buscarPorNomeNoArquivo(const char* caminho, const char* nome) {
    FILE* arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    
    char linha[MAXCHAR];
    int encontrado = 0;
    
    /* Limpar e padronizar o nome de busca */
    char nomeBusca[MAXCHAR];
    strcpy(nomeBusca, nome);
    limparNome(nomeBusca);
    converterParaMinusculo(nomeBusca);

    while (fgets(linha, MAXCHAR, arq)) {
        char nomeArquivo[MAXCHAR];
        sscanf(linha, "%*[^;];%[^;];", nomeArquivo);

        /* Limpar e padronizar o nome extraído do arquivo */
        limparNome(nomeArquivo);
        converterParaMinusculo(nomeArquivo);

        if (strcmp(nomeArquivo, nomeBusca) == 0) {
            char cnpj[20];
            char cod1[10], cod2[10], valor[20], situacao[5];
            
            sscanf(linha, "%[^;];%*[^;];%[^;];%[^;];%[^;];%[^;];", cnpj, cod1, cod2, valor, situacao);
            
            printf("Dados para Nome %s:\n", nome);
            printf("CNPJ: %s\n", cnpj);
            printf("Codigo 1: %s\n", cod1);
            printf("Codigo 2: %s\n", cod2);
            printf("Valor: %s\n", valor);
            printf("Situacao: %s\n", situacao);
            
            encontrado = 1;
            break;
        }
    }
    
    if (!encontrado) {
        printf("Nome nao encontrado.\n");
    }
    
    fclose(arq);
}

void buscarPorCNPJ(){
    char cnpjTeste[20];
    printf("Digite o CNPJ para buscar: ");
    fgets(cnpjTeste, 20, stdin);
    removerNovaLinha(cnpjTeste); /* Remove a nova linha ao final */
    buscarPorCNPJNoArquivo(caminhoArquivo, cnpjTeste);
}

void buscarPorNome(){
    char nomeTeste[MAXCHAR];
    printf("Digite o nome para buscar: ");
    fgets(nomeTeste, MAXCHAR, stdin);
    removerNovaLinha(nomeTeste); /* Remove a nova linha ao final */
    buscarPorNomeNoArquivo(caminhoArquivo, nomeTeste);
}

/* Função principal */
int main() {
    int opcao;
    do {
        printf("\n------ Menu ------\n");
        printf("1. Buscar por CNPJ\n");
        printf("2. Buscar por Nome\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); /* Consumir o '\n' deixado pelo scanf */

        switch (opcao) {
            case 1: {
                buscarPorCNPJ();
                break;
            }
            case 2: {
                buscarPorNome();
                break;
            }
            case 3:
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 3);

    return 0;
}
