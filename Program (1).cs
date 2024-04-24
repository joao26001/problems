using System;

class Program{

static void Main (string[] args){
    //quantidade de testes
    int numTestes = int.Parse(Console.ReadLine());
    

    
    //testes
    for(int i=0; i<numTestes; i++){
        int soma = 0;
        //quantidade de caixas
        int numCaixas = int.Parse(Console.ReadLine());

        //quantidade de doces em cada caixa
        string quantDoces = Console.ReadLine();

        //Formatação
        string[] quantFormatada = quantDoces.Split(' ');
        int[] quantPorCaixa = new int[numCaixas];
        for(int j=0; j<numCaixas; j++){
            quantPorCaixa[j] = int.Parse(quantFormatada[j]);
        }

        //Ordenação
        for(int k=0; k<(numCaixas-1); k++){
            int menor = k;
            for(int y = (k+1); y<numCaixas; y++){
                if(quantPorCaixa[menor] > quantPorCaixa[y]){
                    menor = y;
                }
            }
            int aux = quantPorCaixa[menor];
            quantPorCaixa[menor] = quantPorCaixa[k];
            quantPorCaixa[k] = aux;
        }

        for(int h=0; h<numCaixas-1; h++){
            if(h == numCaixas-1){
                soma += quantPorCaixa[numCaixas-1] - quantPorCaixa[0];

            }else if(quantPorCaixa[0] != quantPorCaixa[h+1]){
                soma += quantPorCaixa[h+1] - quantPorCaixa[0];
            }
        }

        Console.WriteLine(soma);

    }
    
        

}
}
