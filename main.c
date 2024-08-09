#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct no{
  char valor[41];
  struct no *proximo;
} No;

typedef struct{
  No *inicio;
  No *fim;
  int tam;
} Lista;

void criar_lista(Lista *lista){
  lista->inicio = NULL;
  lista->fim = NULL;
  lista->tam = 0;
}

int exibeLista(Lista *lista) {
  if (lista->inicio == NULL) return 0;

  No *noAtual = lista->inicio;
  printf("Elementos da lista: \n");
  do {
    printf("%s\n", noAtual->valor);
    noAtual = noAtual->proximo;
  } while (noAtual != lista->inicio);

  return 1;
}

int insereListaVazia(Lista *lista, char nome[41]) {
  No *novoNo = (No*) malloc(sizeof(No));
  if (novoNo == NULL) return 0;
  strcpy(novoNo->valor, nome);
  lista->inicio = novoNo;
  lista->fim = novoNo;
  novoNo->proximo = lista->inicio;
  lista->tam++;
  return 1;
}

int insereLista(Lista *lista, char nome[41]) {
  if (lista->inicio == NULL) return insereListaVazia(lista, nome);

  No *novoNo = (No*) malloc(sizeof(No));
  if (novoNo == NULL) return 0;
  strcpy(novoNo->valor, nome);
  novoNo->proximo = lista->inicio;
  lista->fim->proximo = novoNo;
  lista->fim = novoNo;
  lista->tam++;
  return 1;
}

int removeDaLista(Lista *lista, int pos) {
  if (lista->tam == 0) return 0;

  No *noAtual = lista->inicio;
  No *noAnterior = NULL;

  for(int i = 0; i < pos; i++) {
    noAnterior = noAtual;
    noAtual = noAtual->proximo;
  }

  if (noAtual == lista->inicio) {
    lista->inicio = noAtual->proximo;
    lista->fim->proximo = lista->inicio;
  } else {
    noAnterior->proximo = noAtual->proximo;
  }

  if (noAtual == lista->fim) {
    lista->fim = noAnterior;
  }

  printf("%s perdeu o sorteio\n", noAtual->valor);
  free(noAtual);
  lista->tam--;

  return 1;
}

int main(void) {
  Lista lista;
  criar_lista(&lista);
  int quantClientes = 0;
  srand(time(0));
  int randNum;
  char nome[41];
  
  printf("Bem vindo ao sorteio do nosso cruzeiro!!\n");
  printf("Quantos participantes vão participar?\n");
  scanf("%d", &quantClientes);

  // loop para inserir o nome de todos os participantes na lista circular 
  for(int i = 0; i < quantClientes; i++){
    printf("\nDigite o nome do %dº participante: \n", i + 1);
    scanf("%s", nome);
    if (lista.tam == 0) {
      insereListaVazia(&lista, nome);
    } else {
      insereLista(&lista, nome);
    }
  }
  
  // loop do sorteio
  while (lista.tam > 1) {
    randNum = rand() % lista.tam;
    removeDaLista(&lista, randNum);
  }
  
  printf("O ganhador do sorteio foi %s\n", lista.inicio->valor);
  
  return 0;
}
