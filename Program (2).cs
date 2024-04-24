using System;

class Program{


  


    static void Main(string[] args){
        //Leitura dos MB mensais
        int quota = int.Parse(Console.ReadLine());

        //Leitura dos meses
        int meses = int.Parse(Console.ReadLine());

        //String guardando o valor que sobra em cada mês
        int[] restos = new int[meses];

        //String guardando o valor de cada mês
        int[] cadaMes = new int[meses];

        //String pra guardar um valor ajustado da quota

        int count = 0;
        for(int i=0; i<meses; i++){
            count++;
        }
        
        //Para não dar index out of range na string novaQuota
        int[] novaQuota = new int[count+1];
        novaQuota[0] = quota;

        //Leitura dos MB por mês
        for(int i=0; i<meses; i++){ 
            //Variável para guardar o valor de cada mês
            cadaMes[i] = int.Parse(Console.ReadLine());

            //Guarda quanto sobrou do mês (i)
            restos[i] = quota - cadaMes[i];

            novaQuota[i+1] = novaQuota[i] + restos[i];
        }


        Console.WriteLine(novaQuota[count]);

        

        

        

    }
}
