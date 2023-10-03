#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*fiz os testes e está rodando tudo direitinho,creio que tenha sido isso que foi
 * pedido */
#define tamanho 12
// tamanho da string sempre com dois a mais
#define brc ((tamanho-2) / 2) 
// tamanho buraco
int main() {
  int linha = 0, linhaf = 0, linhapa = 0;
  int coluna = 0, colunaf = 0, colunapa = 0;
  char mapa[tamanho][tamanho];
  char pa[linhapa][colunapa];
  char buraco[brc][brc];
  int cont = 0, conta = 0;

  do {
    printf("Digite ponto inicial(linha):");
    scanf("%i", &linhapa);
    printf("\nDigite ponto inicial(coluna):");
    scanf("%i", &colunapa);
    printf("\nDigite ponto final(linha):");
    scanf("%i", &linhaf);
    printf("\nDigite ponto final(coluna):");
    scanf("%i", &colunaf);
    if ((linhapa == brc) && (colunapa == brc) ||
        (linhapa == linhaf) && (colunapa == colunaf) ||
        (linhaf == brc) && (colunaf == brc) && (linhapa > tamanho) &&
            (colunapa > tamanho) ||
        (linhaf > tamanho) && (colunaf > tamanho)) {
      printf("\nlinha e coluna nao podem ser utilizadas pois tem o buraco ou "
             "numero digitado ta maior que o tamanho ou "
             "ponto inicial é igual ao ponto final,digite outros "
             "numeros.\nburaco esta na linha e coluna %i \n",
             brc);
    } else {
      conta = conta + 1;
    }
  } while (conta != 1);

  for (linha = 0; linha <= tamanho; linha++) {
    for (coluna = 0; coluna <= tamanho; coluna++) {
      mapa[linha][coluna] = 'O';
    }
  }
  
  mapa[linhapa][colunapa] = 'I';//inicio
  mapa[linhaf][colunaf] = 'F';//fim
  mapa[brc][brc] = ' ';//buraco

  printf("\nMapa inicial: \n");
  for (linha = 0; linha <= (tamanho-2); linha++) {
    for (coluna = 0; coluna <= (tamanho-2); coluna++) {
      if (coluna == (tamanho-2)) {
        printf("%c \n", mapa[linha][coluna]);
      } else {
        printf("%c | ", mapa[linha][coluna]);
      }
    }
  }

  do {

    if ((linhapa == linhaf) && (colunapa == colunaf)) {
      cont = cont + 1;
      printf("\nchegou \n");

    } else if ((linhapa < linhaf) && (colunapa < colunaf)) {
      linhapa = linhapa + 1; // diagonal pra baixo a direita
      colunapa = colunapa + 1;
      if (mapa[linhapa][colunapa] == mapa[brc][brc]) {
        linhapa = linhapa - 1;
      }

    } else if ((linhapa > linhaf) && (colunapa > colunaf)) {
      linhapa = linhapa - 1; // diagonal pra cima a esquerda
      colunapa = colunapa - 1;
      if (mapa[linhapa][colunapa] == mapa[brc][brc]) {
        linhapa = linhapa + 1;
      }

    } else if ((linhapa > linhaf) && (colunapa < colunaf)) {
      linhapa = linhapa - 1; // diagonal pra cima a direita
      colunapa = colunapa + 1;
      if (mapa[linhapa][colunapa] == mapa[brc][brc]) {
        linhapa = linhapa + 1;
      }

    } else if ((linhapa < linhaf) && (colunapa > colunaf)) {
      linhapa = linhapa + 1; // diagonal pra baixo a esquerda
      colunapa = colunapa - 1;
      if (mapa[linhapa][colunapa] == mapa[brc][brc]) {
        linhapa = linhapa - 1;
      }

    } else if ((linhapa < linhaf) && (colunapa == colunaf)) {
      linhapa = linhapa + 1; // pra baixo
      if (mapa[linhapa][colunapa] == mapa[brc][brc]) {
        colunapa = colunapa - 1;
      }

    } else if ((linhapa > linhaf) && (colunapa == colunaf)) {
      linhapa = linhapa - 1; // pra cima
      if (mapa[linhapa][colunapa] == mapa[brc][brc]) {
        colunapa = colunapa - 1;
      }

    } else if ((linhapa == linhaf) && (colunapa > colunaf)) {
      colunapa = colunapa - 1; // pra esquerda
      if (mapa[linhapa][colunapa] == mapa[brc][brc]) {
        linhapa = linhapa - 1;
      }

    } else if ((linhapa == linhaf) && (colunapa < colunaf)) {
      colunapa = colunapa + 1; // pra direita
      if (mapa[linhapa][colunapa] == mapa[brc][brc]) {
        linhapa = linhapa - 1;
      }
    }

    if ((mapa[linhapa][colunapa] != mapa[linhaf][colunaf]) &&
        (mapa[linhapa][colunapa] != mapa[brc][brc])) {
      mapa[linhapa][colunapa] = 'X';//escreve x
    }

  } while (cont != 1);//laço para andar

  printf("\nMapa final: \n");
  for (linha = 0; linha <=(tamanho-2); linha++) {
    for (coluna = 0; coluna <= (tamanho-2); coluna++) {
      if (coluna == (tamanho-2)) {
        printf("%c \n", mapa[linha][coluna]);
      } else {
        printf("%c | ", mapa[linha][coluna]);
      }
    }
  }
}