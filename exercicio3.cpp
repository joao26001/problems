/*Faça um programa que imprima os L primeiros elementos da série de Fibonacci. Por exemplo, se o usuário digitou o número 40, deverão ser apresentados os 40 números da
sequência na tela.*/

#include <iostream>
using namespace std;

int main() {
  int n; //Determinar o loop
  int a = 1;
  int b = 1;
  int c = 0;
  
  cout << "Quantos números da sequência você deseja?\n";
  cin >> n;

  cout << a << " " << b;
  for(int i=2; i<n; i++){
    //Próximo número da sequência
    c = a + b;
    //Printa ele
    cout << " " << c;
    //Atribui os próximos valores as variáveis
    a = b;
    b = c;
  }
}

