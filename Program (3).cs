using System;
class program{
    public static void Main(string []args){
        string vetor;
        string cifra = "";
        vetor = Console.ReadLine();
        while(vetor != "FIM"){
            int i = 0;
            int tamanho = vetor.Length;
            Console.WriteLine(CifraRecursivo(vetor,i,tamanho,cifra));
            vetor = Console.ReadLine();
        }
    }

    static string CifraRecursivo(string vetor,int i, int tamanho, string cifra){
        if(i == tamanho ){
            return cifra;
        }
        else{
            cifra += (char)(Convert.ToInt32(vetor[i])+3);
            cifra = CifraRecursivo(vetor,i+1,tamanho,cifra);
        }
        return cifra;
    }
}