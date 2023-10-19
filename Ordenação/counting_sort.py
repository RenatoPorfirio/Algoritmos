"""
Argoritmo de ordenação em tempo linear

- Complexidade de espaço: O(n + k), onde n é o tamanho do vetor a ser ordenado 
  e k é dado pelos limites de valores do vetor (k = tam_max - tam_min + 1);

- Complexidade de tempo: O(n + k);
"""

from math import inf

def counting_sort(list, min_value, max_value):
  padding = min_value                  # utilizado para indexar o vetor do histograma de 0 à count_size-1, de modo que tenha o menor tamanho possível e possa adimitir valores negativos
  count_size = max_value - padding + 1 #tamanho do histograma
  list_size = len(list)
  aux = [0] *  list_size               # lista utilizada para armazenar o resultado da ordenação
  count = [0] * count_size             # lista do hisograma

  for i in range(list_size):
    count[list[i] - padding] += 1

  for i in range(1, count_size):
    count[i] += count[i - 1]

  for i in range(list_size - 1, -1, -1):
    count[list[i] - padding] -= 1
    aux[count[list[i] - padding]] = list[i]

  for i in range(list_size):
    list[i] = aux[i]


min, max = inf, -inf
list = [2, 9, 3, -1, 2, -3, 10, 25, 500, -7, -800]

for elem in list:
  if elem < min:
    min = elem
  if elem > max:
    max = elem

counting_sort(list, min, max)

print(list)
