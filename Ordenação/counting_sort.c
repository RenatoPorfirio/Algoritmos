/*
Argoritmo de ordenação em tempo linear

- Complexidade de espaço: O(n + k), onde n é o tamanho do vetor a ser ordenado 
  e k é dado pelos limites de valores do vetor (k = tam_max - tam_min + 1);
  
- Complexidade de tempo: O(n + k);
*/

#include <stdio.h>  //para o uso das funções de saída
#include <stdlib.h> //para uso das funções malloc, calloc e free
#include <limits.h> //para obtenção dos limites de um inteiro

#define Bool unsigned char
#define False 0
#define True 1

Bool counting_sort(int *vector, size_t vector_size, int min_value, int max_value){
  int padding = min_value; //utilizado para indexar o vetor do histograma de 0 à count_size-1, de modo que tenha o menor tamanho possível e possa adimitir valores negativos
  size_t i; //variável auxiliar de contagem
  size_t count_size = max_value - padding + 1; //tamanho do histograma
  int *aux = (int *) malloc(vector_size * sizeof(int)); //vetor utilizado para armazenar o resultado da ordenação
  int *count = (int *) calloc(count_size, sizeof(int)); //vetor do hisograma

  if(!aux) return False; //retorna falso se o vetor auxiliar não foi alocado, impossibilitando a ordenação
  if(!count) return False;
  
  for(i = 0; i < vector_size; i++){
    count[vector[i] - padding]++;
  }

  for(i = 1; i < count_size; i++){
    count[i] += count[i - 1];
  }

  for(i = vector_size; i > 0; i--){
    size_t index = --count[vector[i-1] - padding];
    aux[index] = vector[i-1];
  }

  for(i = 0; i < vector_size; i++){
    vector[i] = aux[i];
  }

  free(aux);
  free(count);

  return True; //retorna verdadeiro se o vetor foi ordenado
}

int main(){
  int menor = INT_MAX, maior = INT_MIN;
  int vector[] = {2, 9, 3, -1, 2, -3, 10, 25, 500, -7};
  size_t vector_size = sizeof(vector) / sizeof(vector[0]);
  size_t i;

  for(i = 0; i < vector_size; i++){
    if(vector[i] < menor) menor = vector[i];
    if(vector[i] > maior) maior = vector[i];
  }
  
  Bool success = counting_sort(vector, vector_size, menor, maior);

  if(!success){
    puts("Problem allocating memory");
    exit(EXIT_FAILURE);
  }
  
  for(i = 0; i < vector_size; i++){
    printf("%d ", vector[i]);
  }
  puts("");
  
  return 0;
}