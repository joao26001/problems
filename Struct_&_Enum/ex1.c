// Faça um programa que controla o consumo de energia dos eletrodomésticos de uma casa. Para isso crie a estrutura eletrodoméstico com os seguintes atributos:
// ○ Nome: char[30]
// ○ Potência em kW: float
// ○ Tempo ativo por dia (em horas): float
// Leia do usuário os N eletrodomésticos da sua casa (pode perguntar o valor de N no início da execução) e calcule o consumo total da casa por mês, e o consumo relativo de cada eletrodoméstico também por mês (consumo/consumo_total). Apresente esse último dado em porcentagem.

#include <stdio.h>

// struct do eletrodoméstico
typedef struct eletro_ {
    char nome[30];
    float potencia, horas;
} eletro;

int main(void){
    // variáveis
    int n;
    float consumo_total;
    
    // saída do pedido da qtd de eletro e entrada da qtd desejada pelo usuário
    printf("Digite quantos eletrodomesticos irá registrar: \n");
    scanf("%d", &n);

    // criando vetor para armazenar os eletro
    eletro eletros[n];

    // looping para receber as info sobre os eletrodomésticos
    for(int i = 0; i < n; i++){
        printf("Digite o nome do eletrodomestico: \n");
        scanf("%s", eletros[i].nome);
        printf("Digite a potência em kw: \n");
        scanf("%f", &eletros[i].potencia);
        printf("Digite a quantidade de horas ativas por dia: \n");
        scanf("%f", &eletros[i].horas);
        // formação do consumo total
        consumo_total += (eletros[i].potencia * eletros[i].horas) * 30;
    }  
    
    // looping para printar o consumo relativo de cara eletrodoméstico
    for(int i = 0; i < n; i++){
        printf("O consumo relativo de %s é: %.2f \n", eletros[i].nome, ((eletros[i].potencia * eletros[i].horas) * 30) / consumo_total);
    }

    // saída do consumo total
    printf("O consumo total é: %.2f\n", consumo_total);
}