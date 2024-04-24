/*Fazer um programa leia uma seqüência de valores inteiros fornecida pelo usuário em uma linha de entrada e conte o número de valores positivos, negativos e zeros.*/

#include <iostream>
using namespace std;


int main() {
  int quant, x, pos=0, neg=0, zero=0;

  cout << "Entre com os números, dando um espaço entre eles(quando quiser parar digite -1234):\n";
  while(cin >> x && x != -1234){
    if(x > 0){
      pos++;
    }else if(x < 0){
      neg++;
    }else{
      zero++;
    }
  }

  cout << pos << " positivos\n" << neg << " negativos\n" << zero << " zeros\n";
   

}