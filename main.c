#include "utilidades.h"
#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    memset(tabelaHashCNPJ, 0, sizeof(tabelaHashCNPJ));
    memset(tabelaHashNome, 0, sizeof(tabelaHashNome));

    int maxLinhas = 100; // Número máximo de linhas que deseja ler
    lerArquivo("C:\\Users\\lucas\\Desktop\\POD\\K3241.K03200Y0.D40713.EMPRECSV", maxLinhas);

    int opcao;
    do {
        printf("\n------ Menu ------\n");
        printf("1. Buscar por CNPJ\n");
        printf("2. Buscar por Nome\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                buscarPorCNPJ();
                break;
            case 2:
                buscarPorNome();
                break;
            case 3:
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 3); 

    return 0;
}
