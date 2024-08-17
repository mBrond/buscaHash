#include<stdio.h>
#include"novoArquivo.c"
#include"hash.c"

#define PATH "K3241.K03200Y0.D40713.EMPRECSV"
#define MAXCHAR 300

void leitura(){
	FILE *arq = fopen(PATH, "r");
	char buffer[MAXCHAR], cnpj[8];
	int i, qtdParada = 5;
	int somaCnpj, somaNome, chave;
	int max = 0;
	
    while(feof(arq) != 1 && max != qtdParada){
        fgets(buffer, MAXCHAR, arq);
        strncpy(cnpj, buffer+1, 8);
        cnpj[8] = '\0';
        
        somaCnpj = calculoCnpj(cnpj)*10000;
		somaNome = calculoNome(buffer);
        
        chave = somaCnpj + somaNome;

		adicionaMeio(chave, cnpj, MAXCHAR);	
		max++;
    }
	
}
