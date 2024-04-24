#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data_{
    int dia, mes, ano;
}data;

typedef struct hora_{
    int horas, minutos, segundos;
}hora;

typedef struct compromisso_{
    struct data_ data;
    struct hora_ hora;
    char descricao[50];
}compromisso;

// funcao registrar(registra os compromissos quando chamada pela função int main)
void registrar(compromisso *compromisso){
    printf("Digite a data: \n");
    scanf("%d %d %d", &compromisso->data.dia, &compromisso->data.mes, &compromisso->data.ano);
    printf("Digite o horário: \n");
    scanf("%d %d %d", &compromisso->hora.horas, &compromisso->hora.minutos, &compromisso->hora.segundos);
    printf("Digite a descrição do compromisso (uma palavra): \n");
    scanf("%s", compromisso->descricao);
}

// funcao imprimir(imprime todos os compromissos ou os compromissos de um mês escolhido)
void imprimir(compromisso compromisso){
    printf("Compromisso: %s \n Data: %d/%d/%d \n Horário: %d:%d:%d\n ", compromisso.descricao, compromisso.data.dia, compromisso.data.mes, compromisso.data.ano, compromisso.hora.horas, compromisso.hora.minutos, compromisso.hora.segundos);
}

void salvar(compromisso *compromisso, char *nome, int qtd){
    FILE *arq = fopen(nome, "w");
    fwrite(compromisso, sizeof(compromisso), qtd, arq);
    printf("Arquivo Salvo com sucesso! \n");
}

void carregar(compromisso *compromisso, char *nome){
    FILE *arq = fopen(nome, "r");
    fseek(arq, 0, SEEK_END);
    int qtd = ftell(arq)/sizeof(compromisso);
    fseek(arq, 0, SEEK_SET);

    compromisso = realloc(compromisso, sizeof(compromisso)*qtd);

    for(int i =0; i < qtd; i++){
        fread(&compromisso[i], sizeof(compromisso), 1, arq);
    }
    fclose(arq);
}

int main(void){
    // variaveis
    int n = 0, qtd = 0, mes = 0;
    compromisso comp[100];
    char nome[50];

    // looping(enquanto n for diferente da FLAG definida no inicio da função, o código continua)
    while(n != 6){
        printf("Olá! Seja bem-vindo! Escolha uma das opções: \n 1. Registrar compromisso \n 2. Listar todos os compromissos \n 3. Listar compromissos de um mês \n 4. Salvar Agenda \n 5. Carregar agenda Salva \n 6. Sair \n");    
        scanf("%d", &n);
        // condicional para verificar se a opção escolhida existe e executar a função 
        switch(n){
            case 1:
                registrar(&comp[qtd]);
                qtd++;
                break;
            case 2:
                if(qtd > 0){
                    for(int i = 0; i < qtd; i++){
                        imprimir(comp[i]);
                    }
                    break;
                } else {
                    printf("Você não possui compromissos agendados! \n");
                    break;
                }
            case 3:
                printf("Digite qual mês(em número) quer pesquisar: \n");
                scanf("%d", &mes);
                if(qtd > 0){
                    for(int i = 0; i < qtd; i++){
                        if(comp[i].data.ano == 2022 &&comp[i].data.mes == mes){
                            imprimir(comp[i]);
                        }
                    }
                } 
                break;
            case 4: 
                printf("Digite o caminho do arquivo que deseja salvar: \n");
                scanf("%s", nome);
                salvar(comp, qtd, nome);
                break;
            case 5:
                printf("Digite o caminho do arquivo que deseja carregar: \n");
                scanf("%s", nome);
                carregar(comp, nome);
                break;
            case 6: 
                break;
            default:
                printf("Comando Inválido! \n");
                break;
        }
    }
}
