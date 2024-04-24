/*Faça um algoritmo que leia o ano de nascimento de uma pessoa e calcule sua idade,
considerando o ano atual. Para verificar se já fez aniversário no ano atual pergunte se a
pessoa já fez aniversário, sendo que ela pode entrar com a informação "S"(sim) ou "N"
(não). Com isto é possível se ter maior precisão sobre a idade. Verifique também se a
pessoa já tem idade para conseguir Carteira de Habilitação (18 anos ou mais) e imprima a
mensagem referente a esta checagem. Imprima a idade da pessoa*/
#include <iostream>
using namespace std;


int main() {
  char f_niver;
  int ano, idade;

  //Leitura do ano que a pessoa nasceu
  cout << "Em que ano você nasceu?\n";
  cin >> ano;

  //Perguntando se fez ou não aniversário
  cout << "Você já fez aniversário esse ano?(S para sim, N para não):\n";
  cin >> f_niver;

  if(f_niver == 'N'){
    idade = 2022 - ano;
  }else if(f_niver == 'S'){
    idade = (2022 - ano) - 1;
  }else{
    cout << "Letra inválida!!!\n";
  }

  if(idade > 17){
    cout << "Você pode tirar carteira!\n"  << idade << " anos";
  }else{
    cout << "Você não pode tirar carteira!\n"  << idade << " anos";
  }
}