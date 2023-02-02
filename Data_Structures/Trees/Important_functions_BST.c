#include <stdio.h>
#include <stdlib.h>

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

/* Adiciona um nó à esquerda ou à direita do no raiz. Retorna a raiz da árvore
 * resultante ou NULL caso (i) a raiz ou o nó sejam NULL e (ii) caso o nó possua
 * mesma chave que outro nó previamente inserido na árvore. */
No *abb_insere_no(No *raiz, No *no)
{

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

/* Retorna a chave do nó ou -1 caso o nó seja NULL.  */
int abb_chave_no(No *no) {

return no->chave;



}


/*Retorna a concatenação do conteúdo da árvore fazendo percurso em pré-ordem à
 * partir do nó ou '#' caso o nó seja NULL. */
char *abb_pre_ordem(No *no)
{

    if (no == NULL)
        return NULL;

    printf("%c", no->conteudo);
    abb_pre_ordem(no->esq);
    abb_pre_ordem(no->dir);
    
}



int main()
{

    int inicial_size = 9, chave;
    char conteudo;
    No *raiz;

    for (short i = 0; i < inicial_size; i++)
    {

        printf("Digite a chave e o conteudo!\n");
        scanf("%d", &chave);
        scanf(" %c", &conteudo);

        if (i == 0)
        {
            raiz = abb_cria_no(chave, conteudo);
            continue;
        }

        No *tmp = abb_cria_no(chave, conteudo);
        raiz = abb_insere_no(raiz, tmp);
    }

    abb_pre_ordem(raiz);
    printf("\n");
    
    
    return 0;
}