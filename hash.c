#include"hash.h"

#include<stdio.h>
#include<stdlib.h>

unsigned int primo  = 2654435761;


int calculoCnpj(char* cnpj){
    int soma = 0, i;
    int ascii;
    int cnpjInt = atoi(cnpj);
//    for(i=0;i<8;i++){
//        ascii = cnpj[i];
//        soma = (soma + ascii);
//    }
    return cnpjInt * primo % 10000;
}

int calculoNome(char* linha){
    int soma = 0;
    int i = 12;

    while(linha[i] != '"') {
        soma += linha[i];
        i++;
    }
    return soma * primo % 10000;
}
