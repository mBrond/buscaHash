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

int calculoNome(char* nome){
	int soma = 0, i;
}

int main(){
	FILE* arq = fopen("C:\\Users\\Miguel\\Documents\\Aulas\\POD\\trab2\\Empresas0\\K3241.K03200Y0.D40713.EMPRECSV", "r");
	char row[MAXCHAR];
	int max = 0;
	char cnpj[8];
	
	while(feof(arq) != true && max != 50){
		fgets(row, MAXCHAR, arq);
		printf("%s\n", row);
		strncpy(cnpj, row+1, 8);
		int soma = calculoCnpj(cnpj);
		printf("%d\n", soma);
		max++;
	}

}
