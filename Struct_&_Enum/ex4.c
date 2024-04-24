// Escreva um programa que possua a estrutura carro, com dois atributos: uma string modelo (Fusca, Gol, etc.) e consumo, sendo o consumo referente a quantos km esse carro faz por litro. Leia do usu ́ario os modelos e os seus respectivos consumos e imprima qual dos carros é o mais econˆomico. Seu programa deve alocar dinamicamente o espaço necessário para a estrutura.

#include <stdio.h>

typedef struct carro_{
    char modelo[15];
    float consumo;
} carros;


int main(void){
    // declarando variáveis 
    int n, maior_consumo = 0;
    char *carro_maior;

    // recebendo a qtd de carros que o usuário quer registrar
    printf("Digite quantos carros quer registar: \n");
    scanf("%d", &n);

    // declarando vetor para não perder os valores atribuídos a cada carro
    carros carro[n];

    // looping para receber nome do carro e seu consumo de acordo com a qtd determinada, além de definir qual o carro com maior consumo
    for(int i = 0; i < n; i++){
        printf("Digite o nome do carro \n");
        scanf("%s", &carro[i].modelo);
        printf("Digite o consumo do carro: \n");
        scanf("%f", &carro[i].consumo);
        if(carro[i].consumo > maior_consumo){
            maior_consumo = carro[i].consumo;
            carro_maior = carro[i].modelo;
        }
    }
    
    // saída do carro com maior consumo
    printf("%s \n", carro_maior);
}   