#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int conta_linhas(FILE *exemplo){
    rewind(exemplo);
    char n[100];
    int tam = 0;
    while(!feof(exemplo)){
        fgets(n, 100, exemplo);
        tam++;
    }
    return tam;
}

int maior_linha(FILE *exemplo){
    rewind(exemplo);
    char n[100];
    int maior_linha = 1, atual_linha = 1, tam_maior_linha = 0;
    while(!feof(exemplo)){
        fgets(n, 100, exemplo);
        if(tam_maior_linha < strlen(n)){
            tam_maior_linha = strlen(n);
            maior_linha = atual_linha;
        }
        atual_linha++;
    }
    return maior_linha;
}

int menor_linha(FILE *exemplo){
    rewind(exemplo);
    char n[100];
    int menor_linha = 1, atual_linha = 1, tam_menor_linha = 101;
    while(!feof(exemplo)){
        fgets(n, 100, exemplo);
        if(tam_menor_linha > strlen(n)){
            tam_menor_linha = strlen(n);
            menor_linha = atual_linha;
        }
    atual_linha++;
    }
    return menor_linha;
}

int* conta_vogais(FILE *exemplo){
    rewind(exemplo);
    int* vogal = (int*) calloc(5, sizeof(int));
    char n[100];
    while(!feof(exemplo)){
        switch(getc(exemplo)){
            case 'A':
            case 'a':
                vogal[0]++;
                break;      
            case 'E':
            case 'e':
                vogal[1]++;
                break; 
            case 'I':
            case 'i':
                vogal[2]++;
                break;
            case 'O':
            case 'o':
                vogal[3]++;
                break;
            case 'U':
            case 'u':
                vogal[4]++;
                break;
        }
    }
    printf("a: %d e: %d i: %d o: %d u: %d \n", vogal[0], vogal[1], vogal[2], vogal[3], vogal[4]);
}

int main(void){
    FILE *exemplo = fopen("exemplo.txt","r");

    printf("Conta linhas: %d\n", conta_linhas(exemplo));
    printf("Maior linha: %d\n", maior_linha(exemplo));
    printf("Menor linha: %d\n", menor_linha(exemplo));
    conta_vogais(exemplo);
}