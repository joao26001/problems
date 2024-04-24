/*Faça um programa que leia dois valores inteiros e chame uma função que receba estes 2 valores por referência (ponteiros) e coloque o maior valor na primeira variável e o menor valor na segunda variável. Escreva o conteúdo das 2 variáveis na tela no programa principal.*/

void troca(int *n1, int *n2){
  int aux;// variável para guarddar o valor de n1 para ele não ser perdido

  if(*n2 > *n1){
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
  }
}

#include <iostream>
using namespace std;
int main() {
  int a, b;
  cout << "Entre com os dois valores:\n";
  cin >> a >> b;

  troca(&a, &b);
  cout << a << " " << b;
}
