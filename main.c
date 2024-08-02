#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
  int valor;
  struct no *proximo;
}No;

typedef struct{
  No *inicio;
  No * fim;
  int tam;
}Lista;

void criar_lista(Lista *lista){
  lista->inicio = NULL;
  lista->fim = NULL;
  lista->tam = 0;
}

int main(void) {
  
  int quantClientes = 0;
  srand(time(0));
  int randNum = rand();
  char nome[41];
  
  printf("Bem vindo ao sorteio do nosso cruzeiro!!\n");
  printf("Quantos participantes vão participar?");
  scanf("%d", &quantClientes);

  
  
  //loop para inserir o nome de todos os participantes na lista circular 
  for(int i = 0; i < quantClientes; i++){
    printf("\nDigite o nome do %dº participante:", i + 1);
    scanf("%s", nome);
  }
  
  return 0;
}