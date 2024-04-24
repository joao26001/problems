#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno_{
    char nome[20];
    char sobrenome[20];
    int matricula;
    int n1, n2, n3, n4;
}Aluno;

int main(void){

    FILE *alunos = fopen("alunos.txt","r");
    FILE *notas = fopen("notas.txt", "r");
    FILE *medias = fopen("media.txt", "w");
    int n1, n2, n3, n4, n;
    Aluno aluno[5];
    char nome[15], sobrenome[15];
    
    for(int i = 0; i < 5; i++){
        fscanf(alunos, "%s %s %d", aluno[i].nome, aluno[i].sobrenome, &aluno[i].matricula);
    }

    for(int i = 0; i < 5; i++){
        fscanf(notas, "%d", &n);
        for(int j = 0; j < 5; j++){
            if(n == aluno[j].matricula){
                fscanf(notas, "%d %d %d %d", &aluno[j].n1, &aluno[j].n2, &aluno[j].n3, &aluno[j].n4);
            }
        }
    }

    for(int i = 0; i < 5; i++){
        fprintf(medias, "%s %s %d \n", aluno[i].nome, aluno[i].sobrenome, (aluno[i].n1 + aluno[i].n2 + aluno[i].n3 + aluno[i].n4) / 4);
    }
}