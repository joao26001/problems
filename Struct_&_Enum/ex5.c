#include <stdio.h>
#include <string.h>

typedef struct nota_{
    char carac;
    float dur;
}nota;


int main(void){
    // variaveis 
    int resul = 0, n, tam = 0;
    float tempo = 0;
    char compasso[50];
    nota notas[7] = {
        {'W', 1.0},
        {'H', 1/2},
        {'Q', 1/4},
        {'E', 1/8},
        {'S', 1/16},
        {'T', 1/32},
        {'X', 1/64}
    };

    // entrada do compasso inteiro
    scanf("%s", &compasso);
    // propriedade que calcula o tamanho de char
    tam = strlen(compasso);

    // looping que verifica se cada parte do compasso separado por '/' cumpre o requisito da soma ser igual a 1
    for(int i = 0; i < tam; i++){
        if(compasso[i] == '/'){
            if(tempo == 1){
                resul++;
            }
            tempo = 0;
        }
        for(int j = 0; j < 7; j++){
            if(compasso[i] == notas[j].carac){
                tempo += notas[j].dur;
            }
        }
    }

    // saída do resultado de quantas partes do compasso cumprem o requisito
    printf("%d\n", resul);
}

