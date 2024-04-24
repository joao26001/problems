using System;


class Program{
    public static void Main(string[] args){
        Geracao array = new QuickSort();

        string linha = Console.ReadLine();
        array.LerJogadores(linha);
        array.Sort();
        array.ImprimirJogadores();
      
    }
}


class Jogadores{
    public string Nome;
    string Foto;
    public int Id;
    public DateTime Nascimento;
    int[] Times;

    public void Leitura(string linha){
        string remove = linha.Replace("[", "");
        string remove1 = remove.Replace("]", "");
        string remove2 = remove1.Replace('"', '@');
        string remove3 = remove2.Replace("@", "");
        linha = remove3;
        int contador = 6;
        string[] Formatada = linha.Split(',');
        Nome = Formatada[1];
        Id = int.Parse(Formatada[5]);
        Foto = Formatada[2];
        Nascimento = DateTime.Parse(Formatada[3]);
        if (Formatada.Length <= 7){
            Times = new int[1];
            Times[0] = int.Parse(Formatada[6]);
        }else{
            Times = new int[Formatada.Length - 6];
            for (int i = 0; i < Times.Length; i++){
                Times[i] = int.Parse(Formatada[contador]);
                contador++;
            }
        }
    }
    public void Imprimir(){
        Console.Write(Id + " " + Nome + " " + Nascimento.ToString("d/MM/yyyy") + " " + Foto + " "+ "(");
        for (int i = 0; i < Times.Length; i++){
            if (i == Times.Length - 1){
                Console.Write(Times[i]);
                break;
            }else{
                Console.Write(Times[i] + ", ");
            }
        }
        Console.Write(")");
        Console.WriteLine("");
    }
}
class Geracao{
   protected Jogadores[] array;
   protected int n;
   public Geracao(){
      array = new Jogadores[100];
      n = 0;
   }
   public Geracao(int tamanho){
      array = new Jogadores[tamanho];
      n = 0;
   }
   public void LerJogadores(string entrada){
        int count = 0;
        while (entrada != "FIM"){
            array[count] = new Jogadores();
            array[count].Leitura(entrada);
            n++;
            count++;
            entrada = Console.ReadLine();
        }
   }
   public virtual void Sort(){

   }
   public void ImprimirJogadores(){
        for(int i=0; i<n; i++){
            array[i].Imprimir();
        }
   }
}

class QuickSort : Geracao {
    public void Swap(int i, int j) {
      Jogadores temp = array[i];
      array[i] = array[j];
      array[j] = temp;
   }
   public QuickSort() : base(){
      
   }
   public QuickSort(int tamanho) : base(tamanho){
      
   }
    public override void Sort() {
      SortQuicksort(0, n-1);
   }

    private void SortQuicksort(int esq, int dir) {
        int i = esq, j = dir;
        Jogadores pivo = array[(dir+esq)/2];
        while (i <= j) {
            while (string.Compare(array[i].Nome, pivo.Nome)< 0) i++;
            while (string.Compare(array[j].Nome, pivo.Nome)> 0) j--;
            if (i <= j) {
                Swap(i, j);
                i++;
                j--;
            }
        }
        if (esq < j)  SortQuicksort(esq, j);
        if (i < dir)  SortQuicksort(i, dir);
    }
}

