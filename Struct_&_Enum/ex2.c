// Seu programa irá precisar de um tipo de dado enum com os dias da semana. Crie também uma matriz de char onde cada linha é o nome de um dia da semana. Ambas as estruturas devem ser correspondentes, ou seja, o valor de uma constante do enum deve se referir à linha da matriz que contém o nome daquele dia da semana. O usuário vai fornecer o nome de um dia da semana, seu programa deve:
// ○ converter o nome para um inteiro (a linha da matriz)
// ○ realizar um switch-case para imprimir se aquele é um dia da semana ou um fim de semana.

#include <stdio.h>
#include <string.h>

// enum com os dias da semana
enum dias_ {Domingo, Segunda, Terca, Quarta, Quinta, Sexta, Sabado} dias;

int main(void){
    // declarando variáveis
    int resul = 0;
    char escolha[10], dia[7][7] = {
        "Domingo",
        "Segunda",
        "Terca",
        "Quarta",
        "Quinta",
        "Sexta",
        "Sabado"
    };

    // recebendo um dia da semana escolhido pelo usuário
    printf("Digite um dia da semana: \n");
    scanf("%s", &escolha);

    // verificando se o dia da semana existe em enum e atribuindo o valor para uma variavel
    for(int i = 0; i < 7; i++){
        if(strcmp(escolha, dia[i]) == 0){
            resul = i;
        }
    }

    // condicional para imprimir se o dia escolhido é um dia de semana ou fim de semana
    switch(resul){
        case Domingo:
        case Sabado:
            printf("Fim de Semana \n");
            break;
        default:
            printf("Dia da semana \n");
            break;
    }
}