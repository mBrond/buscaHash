#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAXCHAR 1000

int calculoCnpj(char* cnpj){
    int soma = 0, i;
    int ascii;
    int cnpjInt = atoi(cnpj);
//    for(i=0;i<8;i++){
//        ascii = cnpj[i];
//        soma = (soma + ascii);
//    }
    return cnpjInt * 2654435761 % 10000;
}

int calculoNome(char* linha){
    int soma = 0;
    int i = 12;

    while(linha[i] != '"') {
        soma += linha[i];
        i++;
    }
    return soma * 2654435761 % 10000;
}

int verifica_repeticao(int* array, int tamanho, int numero) {
    int i;
    for (i = 0; i < tamanho; i++) {
        if (array[i] == numero) {
            return 1; // número encontrado
        }
    }
    return 0; // número não encontrado
}

int main(){
    //FILE* arq = fopen("C:\\Users\\Miguel\\Documents\\Aulas\\POD\\trab2\\Empresas0\\K3241.K03200Y0.D40713.EMPRECSV", "r");
    FILE* arq = fopen("Empresas0\\K3241.K03200Y0.D40713.EMPRECSV", "r");

    if(arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    char row[MAXCHAR];
    int max = 0;
    char cnpj[9];
    
	// !!!RETIRAR!!!
	int qtdParada =900000;
    int chaves[qtdParada];
    int qtdColi = 0, vetChave=0;
    
    while(feof(arq) != true && max != qtdParada){
        fgets(row, MAXCHAR, arq);
//        printf("%s\n", row);
        strncpy(cnpj, row+1, 8);
        cnpj[8] = '\0';
        
        int somaCnpj = calculoCnpj(cnpj)*100000;
        int somaNome = calculoNome(row);
        
        int chave = somaCnpj + somaNome;
        
//        printf("CNPJ extraido: '%s'\n", cnpj);
//        printf("Soma CNPJ: %d\n", somaCnpj);
//        printf("Soma Nome: %d\n", somaNome);
//        printf("Chave Hash: %d\n", chave);

        
		
		if(verifica_repeticao(chaves, vetChave, chave)==1){
//			printf("!!!!COLISAO PARA %d\n", chave);
			qtdColi++;
		}
		chaves[vetChave] = chave;
        vetChave++;
		
        max++;
    }

    fclose(arq);
    
    printf("\n\nHOUVERAM %d COLISOES", qtdColi);
    return 0;
}
