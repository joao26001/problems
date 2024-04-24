// Vamos criar uma agenda de compromissos! Para isso serão necessárias os seguintes tipos de dados:
// ○ Data: composto por dia, mês, ano
// ○ Hora: composto por horas, minutos, segundos
// ○ Compromisso: composto por data, hora e descrição.
// Faça um menu para o usuário com as seguintes opções:
// 1. Registrar compromisso
// 2. Listar todos os compromissos
// 3. Listar compromissos de um mês
// A funcionalidade listar por mês, deve solicitar ao usuário o mês (de 01 a 12) e listar os compromissos daquele mês (do ano corrente).

#include <stdio.h>
#include <string.h>
#define FLAG -99

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
    printf("Digite a descrição do compromisso: \n");
    scanf("%s", compromisso->descricao);
}

// funcao imprimir(imprime todos os compromissos ou os compromissos de um mês escolhido)
void imprimir(compromisso compromisso){
    printf("Compromisso: %s \n Data: %d/%d/%d \n Horário: %d/%d/%d\n ", compromisso.descricao, compromisso.data.dia, compromisso.data.mes, compromisso.data.ano, compromisso.hora.horas, compromisso.hora.minutos, compromisso.hora.segundos);
}

int main(void){
    // variaveis
    int n = 0, qtd = 0, mes = 0;
    compromisso comp[100];

    // looping(enquanto n for diferente da FLAG definida no inicio da função, o código continua)
    while(n != FLAG){
        printf("Olá! Seja bem-vindo! Escolha uma das opções: \n 1. Registrar compromisso \n 2. Listar todos os compromissos \n 3. Listar compromissos de um mês \n");    
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
                } else {
                    printf("Você não possui compromissos agendados! \n");
                }
                break;
            default:
                printf("Opção inexistente \n");
        }
    }
    
}
