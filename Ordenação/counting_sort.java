class counting_sort{
  static boolean counting_sort(int[] vector, int vector_size, int min_value, int max_value){
    int padding = min_value; //utilizado para indexar o vetor do histograma de 0 à count_size-1, de modo que tenha o menor tamanho possível e possa adimitir valores negativos
    int i; //variável auxiliar de contagem
    int count_size = max_value - padding + 1; //tamanho do histograma
    int[] aux = new int[vector_size]; //vetor utilizado para armazenar o resultado da ordenação
    int[] count = new int[count_size]; //vetor do hisograma

    if(aux == null) return false; //retorna falso se o vetor auxiliar não foi alocado, impossibilitando a ordenação
    if(count == null) return false;

    for(i = 0; i < vector_size; i++){
      count[vector[i] - padding]++;
    }

    for(i = 1; i < count_size; i++){
      count[i] += count[i - 1];
    }

    for(i = vector_size; i > 0; i--){
      int index = --count[vector[i-1] - padding];
      aux[index] = vector[i-1];
    }

    for(i = 0; i < vector_size; i++){
      vector[i] = aux[i];
    }
    return true; //retorna verdadeiro se o vetor foi ordenado
  }

  public static void main(String[] args){
    int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
    int vector[] = new int[] {2, 9, 3, -1, 2, -3, 10, 25, 500, -7, -800};
    int vector_size = vector.length;
    int i;

    for(i = 0; i < vector_size; i++){
      if(vector[i] < min) min = vector[i];
      if(vector[i] > max) max = vector[i];
    }

    boolean success = counting_sort(vector, vector_size, min, max);

    if(!success){
      System.out.println("Problem allocating memory");
      return;
    }
    for(i = 0; i < vector_size; i++){
      System.out.print(vector[i] + " ");
    }
    System.out.println("");
  }
}