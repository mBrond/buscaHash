#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAXCHAR 1000

int calculoCnpj(char* cnpj){
    int soma = 0, i;
    int ascii;
    for(i=0;i<8;i++){
        ascii = cnpj[i];
        soma = (soma + ascii);
    }
    return soma % 17931362;
}

int calculoNome(char* linha){
    int soma = 0;
    int i = 12;

    while(linha[i] != '"') {
        soma += linha[i];
        i++;
    }
    return soma % 17931362;
}

int main(){
    //FILE* arq = fopen("C:\\Users\\Miguel\\Documents\\Aulas\\POD\\trab2\\Empresas0\\K3241.K03200Y0.D40713.EMPRECSV", "r");
    FILE* arq = fopen("C:\\Users\\lucas\\Desktop\\POD\\buscaHash\\K3241.K03200Y0.D40713.EMPRECSV", "r");

    if(arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    char row[MAXCHAR];
    int max = 0;
    char cnpj[9];
    
    while(feof(arq) != true && max != 50){
        fgets(row, MAXCHAR, arq);
        printf("%s\n", row);
        strncpy(cnpj, row+1, 8);
        cnpj[8] = '\0';
        
        int somaCnpj = calculoCnpj(cnpj);
        int somaNome = calculoNome(row);
        
        printf("CNPJ extraido: '%s'\n", cnpj);
        printf("Soma CNPJ: %d\n", somaCnpj);
        printf("Soma Nome: %d\n", somaNome);
        
        max++;
    }

    fclose(arq);
    return 0;
}
