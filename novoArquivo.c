#include<stdio.h>
#include<string.h>

#define totalHash 999999999
#define pathFile "novoArquivo.csv"
#define pathTemp "temp.csv"

void criarNovoArquivo(){
	FILE* arq = fopen(pathFile, "w");
	unsigned int i;
	for(i=0;i<totalHash;i++){
		fputs("\n", arq);
	}
	fclose(arq);
}

//!!!melhoravél!!!
//1 para linha usada, 0 para linha livre.
int confereLinhaUsada(int index){ 
	FILE* arq = fopen(pathFile, "r");
	char linha[300];
	char quebra[300] = "\n";
	int i=0;
	int retorno = 1;
	
	while(fgets(linha, 300, arq)){
		if(i == index-1){ //RETIRA 1 para que a primeira linha seja a linha 1.
			if(strcmp(linha, quebra)==0){
				retorno = 0;
			}
		}
		i++;
	}
	fclose(arq);
	return retorno;
}

void insereLinha(char dados[300], int codHash){
	char linha[300];
	char quebra[300] = "\n";
	int i =0;
	int comparacao;
	
	FILE* arq = fopen(pathFile, "r");
	FILE* temp = fopen(pathTemp, "w");
	
	
	while(fgets(linha, 300, arq)){
		if(i == codHash){
			printf("A\n");
			comparacao = strcmp(linha, quebra);
				
			if(comparacao==0){
				printf("Linha: %s aa\n", linha);
				fwrite(dados, 300, 1, arq);
				break;
			}
		
		}
		else{
			printf("ELSE");
			fwrite(linha, 1, 300, temp);	
		}
		
		
		i++;
	}
	
	
	fclose(arq);
	fclose(temp);
	return;
}

int confereQuebras(char* texto, int tam){
	int i = 0, qtd=0;
	char quebra[1] = "\n";
	char olhando;
	while(i<tam){
		olhando = texto[i];
		if(texto[i] == quebra[0]){
			qtd++;
		}
		i++;
	}
	return qtd;
}

void putCharString(FILE* arq, char string[], int tam){
	int i;
	char c;
	while(i<tam){
		c = string[i];
		fputc(c, arq);
		i++;
	}
}

void adicionaMeio(int index, char registro[], int tamReg){
	int quebras = 0, j;
	char charOriginal, charReg;
	
	FILE* arq = fopen(pathFile, "r");
	FILE* temp = fopen(pathTemp, "w");
	while((charOriginal=fgetc(arq))!=EOF){
		
		if(charOriginal=='\n'){
			quebras++;
		}
		
		if(quebras == index){
			if(confereLinhaUsada(index)==0){
				j=0;
				while(j<tamReg){
					charReg = registro[j];
					fputc(charReg, temp);
					j++;
				}
				fputc('\n', temp);
				index = -1; /* mais nada a adicionar de novo no arquivo*/
			}
			else{
				fputc('\n', temp);
				index++;
			}
		}
		else{
			fputc(charOriginal, temp);
		}
	}
	
	fclose(arq);
	fclose(temp);
}

void printArq(){
	FILE* arq = fopen(pathFile, "r");
	char buffer[300];
	while(fgets(buffer, 300, arq)){
		printf("%s", buffer);
	}
	
	fclose(arq);
}
