#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"
struct node
{
  int chave;
  char conteudo;
  struct node *esq;
  struct node *dir;
};
typedef struct node No;

/* Aloca e retorna um No com os dados passados por parâmetro. Retorna no nó
 * criado ou NULL caso não seja posivel criar o nó. */
No *abb_cria_no(int chave, char conteudo)
{

  No *tmp = (No *)malloc(sizeof(No));
  tmp->chave = chave;
  tmp->conteudo = conteudo;

  tmp->esq = NULL;
  tmp->dir = NULL;

  return tmp;
}

void abb_libera_no_helper(No *no)
{

  if (no != NULL)
  {
    abb_libera_no_helper(no->esq);
    abb_libera_no_helper(no->dir);
    free(no);
  }
}

/* Libera a memória de um nó e toda as suas sub-árvores. Retorna 1 se for
 * possivel fazer a liberação ou 0 caso o nó seja NULL. */
int abb_libera_no(No *no)
{
  if (no == NULL)
    return 0;

  abb_libera_no_helper(no);
  return 1;
}
/* Procura o nó pela chave. Retorna o nó caso a busca obtenha sucesso ou NULL
 * em caso contrário. */
No *abb_busca_no(No *raiz, int chave)
{
  if (raiz == NULL)
    return NULL;

  if (chave == raiz->chave)
    return raiz;
  else if (chave < raiz->chave)
    abb_busca_no(raiz->esq, chave);
  else if (chave > raiz->chave)
    abb_busca_no(raiz->dir, chave);
}

/* Adiciona um nó à esquerda ou à direita do no raiz. Retorna a raiz da árvore
 * resultante ou NULL caso (i) a raiz ou o nó sejam NULL e (ii) caso o nó possua
 * mesma chave que outro nó previamente inserido na árvore. */
No *abb_insere_no(No *raiz, No *no)
{
  if (no == NULL || raiz == NULL)
    return NULL;

  if (abb_busca_no(raiz, no->chave) != NULL)
    return NULL;

  No *tmp = raiz;
  do
  {

    if (tmp->chave > no->chave)
    {
      if (tmp->esq == NULL)
      {
        tmp->esq = no;
        break;
      }
      tmp = tmp->esq;
    }

    else if (tmp->chave < no->chave)
    {
      if (tmp->dir == NULL)
      {
        tmp->dir = no;
        break;
      }
      tmp = tmp->dir;
    }

  } while (1);

  return raiz;
}

No *abb_remove_no_helper(No *no)
{

  No *tmp = no;
  while (tmp && tmp->esq != NULL)
  {
    tmp = tmp->esq;
  }
  return tmp;
}

/* Remove o nó com a chave fornecida. Retorna a raiz da arvore atualizada ou
 * NULL em caso a raiz fornecida seja NULL. */
No *abb_remove_no(No *raiz, int chave)
{

  if (raiz == NULL)
    return NULL;

  if (chave > raiz->chave)
    raiz->dir = abb_remove_no(raiz->dir, chave);

  else if (chave < raiz->chave)
    raiz->esq = abb_remove_no(raiz->esq, chave);

  else
  {

    if (raiz->esq == NULL)
    {
      No *tmp = raiz->dir;
      free(raiz);
      return tmp;
    }
    else if (raiz->dir == NULL)
    {
      No *tmp = raiz->esq;
      free(raiz);
      return tmp;
    }

    struct node *tmp = abb_remove_no_helper(raiz->dir);

    raiz->chave = tmp->chave;
    raiz->dir = abb_remove_no(raiz->dir, tmp->chave);
  }
  return raiz;
}

/* Retorna a chave do nó ou -1 caso o nó seja NULL.  */
int abb_chave_no(No *no)
{
  if (no == NULL)
    return -1;
  return no->chave;
}
/* Retorna o conteúdo do no ou '#' caso o nó seja NULL. */
char abb_conteudo_no(No *no)
{
  if (no == NULL)
    return '#';
  return no->conteudo;
}

/* Retorna a altura da árvore ou -1 caso araiz seja NULL. */
int abb_altura(struct node *no)
{
  if (no == NULL)
    return 0;
  else
  {
    int esquerda = 0;
    int direita = 0;
    esquerda = abb_altura(no->esq);
    direita = abb_altura(no->dir);
    if (esquerda > direita)
    {
      return esquerda + 1;
    }
    else
      return direita + 1;
  }
}

/* Retorna o número de nós da árvore ou -1 caso a raiz seja NULL. */
int abb_numero(No *raiz)
{
  int counter = 1;

  if (raiz == NULL)
  {
    return 0;
  }

  else
  {
    counter += abb_numero(raiz->esq);
    counter += abb_numero(raiz->dir);
    return counter;
  }
}

char *abb_pre_ordem_helper(No *no)
{

  if (no == NULL)
    return NULL;

  printf("%c", no->conteudo);
  abb_pre_ordem_helper(no->esq);
  abb_pre_ordem_helper(no->dir);
}

/*Retorna a concatenação do conteúdo da árvore fazendo percurso em pré-ordem à
 * partir do nó ou '#' caso o nó seja NULL. */
char *abb_pre_ordem(No *no)
{
  if (no == NULL)
    return "#";
  abb_pre_ordem_helper(no);
}

char *abb_ordem_helper(No *no)
{

  if (no == NULL)
    return NULL;
  abb_ordem_helper(no->esq);
  printf("%c", no->conteudo);
  abb_ordem_helper(no->dir);
}

/*Retorna a concatenação do conteúdo da árvore fazendo percurso em ordem à
 * partir do nó ou '#' caso o nó seja NULL. */
char *abb_ordem(No *no)
{
  if (no == NULL)
    return "#";
  abb_ordem_helper(no);
}

char *abb_pos_ordem_helper(No *no)
{
  if (no == NULL)
    return NULL;
  abb_pos_ordem_helper(no->esq);
  abb_pos_ordem_helper(no->dir);
  printf("%c", no->conteudo);
}

/*Retorna a concatenação do conteúdo da árvore fazendo percurso em pós-ordem à
 * partir do nó ou '#' caso o nó seja NULL. */
char *abb_pos_ordem(No *no)
{
  if (no == NULL)
    return "#";
  abb_pos_ordem_helper(no);
}

int main()
{

  No *raiz;
  raiz = abb_cria_no(5, 'A');
  No *no1 = abb_cria_no(3, 'B');
  No *no2 = abb_cria_no(7, 'C');
  No *no3 = abb_cria_no(1, 'D');
  No *no4 = abb_cria_no(4, 'E');
  No *no5 = abb_cria_no(6, 'F');
  No *no6 = abb_cria_no(9, 'G');
  No *no7 = abb_cria_no(8, 'H');
  No *no8 = abb_cria_no(10, 'I');

  raiz = abb_insere_no(raiz, no1);
  raiz = abb_insere_no(raiz, no2);
  raiz = abb_insere_no(raiz, no3);
  raiz = abb_insere_no(raiz, no4);
  raiz = abb_insere_no(raiz, no5);
  raiz = abb_insere_no(raiz, no6);
  raiz = abb_insere_no(raiz, no7);
  raiz = abb_insere_no(raiz, no8);

  abb_pre_ordem(raiz);
  printf("\n");
  abb_ordem(raiz);
  printf("\n");
  abb_pos_ordem(raiz);
  printf("\n");
  printf("O numero de nos da ABB é: %d\n", abb_numero(raiz));
  printf("A altura da ABB é: %d\n", abb_altura(raiz));
  printf("A remoção do numero 3\n");
  abb_remove_no(raiz, 3);
  abb_pre_ordem(raiz);
  printf("\n");
  printf("Busca do numero 3! 1 caso exista e 0 caso nao exista\n");
  if (abb_busca_no(raiz, 3) == NULL)
    printf("0");
  else
    printf("1");
  printf("\n");
  printf("Busca do numero 9! 1 caso exista e 0 caso nao exista\n");
  if (abb_busca_no(raiz, 9) == NULL)
    printf("0");
  else
    printf("1");
  printf("\n");
  abb_libera_no(raiz);
  return 0;
}