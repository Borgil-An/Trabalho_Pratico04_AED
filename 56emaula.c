#include <stdio.h>
#include <stdlib.h>

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes);
int trueMerge(int **ret , int right, int left);

int main(void){
    int** intervals[4][2] = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };
    int *retornada = merge(intervals, 4 , 2, 3, 2);

    return 0;

}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
  if (intervals == NULL){
    return 0;
  }
  // Teste para verificar se o array nao está vazio
  
  int ** ret = (int **)malloc(sizeof(returnSize));
  *ret = (int *)malloc(sizeof(int)*2);

  ret[0][0] = intervals[0][0]; //Menor numero em teoria
  ret[0][1] = intervals[0][1]; // Maior numero atual em teoria

  for (int i = 1; i < intervalsSize; i++){
    for (int j = 0; j < 2; j++){
      if(ret[i-1][j] == intervals[i][j]){
      ret[i-1][j] = trueMerge(ret[i-1][j], intervals[i][j]); // Aqui estaria a função recursiva de Merge Sort caso eu soubesse implementala no código, salvando a mesma em ret
    }
  }
  

  return ret;
}

// Minha intenção com o código era malocar um array de array com o espaçamento requesitado pelo enunciado e entao alocar os primeiros dois valores do array (Pressupondo que eles seriam os menores possiveis de todos array)
// e então rodar um for sempre comparando os valores, e caso encontrasse algum valor equivalente iria chamar a função trueMerge para concatenar os mesmos.

int trueMerge(int ** ret, int right, int left)
{
   // Função que juntaria os dois elementos validos em um array só
}
