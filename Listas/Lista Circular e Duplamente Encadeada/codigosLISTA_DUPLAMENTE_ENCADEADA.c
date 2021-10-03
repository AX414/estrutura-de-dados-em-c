#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct noLista  /* estrutura duplamente auto-referenciada */
{
    int valor;
    struct noLista *anterior, *proximo;
};

typedef struct noLista NOLISTA; /* definição do tipo NOLISTA a partir do tipo 'struct noLista' */
typedef NOLISTA *NOLISTAPTR; /* definição do tipo *NOLISTAPTR a partir do tipo NOLISTA */

/* insere um nó no início da lista */
void insere_inicio(NOLISTAPTR *inicio, int valor)
{

    NOLISTAPTR novo;

    novo = (NOLISTAPTR) malloc(sizeof(NOLISTA)); /* aloca memória para o novo nó */

    if(novo == NULL) /* se não houver memória disponível */
        return;      /* sai da função */

    if(*inicio == NULL)     /* se a lista estivava vazia */
    {
        novo->valor = valor; /* insere o valor no novo nó */
        novo->proximo = novo->anterior = NULL; /* não há próximo nó nem nó anterior, pois só há um nó */
        *inicio = novo; /* o novo nó é o primeiro da lista */
    }
    else    /* se já havia nó na lista */
    {
        novo->valor = valor; /* insere o valor no novo nó */
        novo->anterior = NULL; /* não há nó anterior */
        novo->proximo = *inicio; /* o novo nó aponta para o que está no início */
        (*inicio)->anterior = novo; /* o nó atual do início aponta para o novo nó */
        *inicio = novo; /* o novo nó passa a ser o primeiro da lista */
    }
}

/* insere um valor no final da lista */
void insere_fim(NOLISTAPTR *inicio, int valor)
{

    NOLISTAPTR novo, atual;

    novo = malloc(sizeof(NOLISTA));

    if(novo == NULL)
        return;

    if(*inicio == NULL)
    {
        novo->valor = valor;
        novo->proximo = novo->anterior = NULL;
        *inicio = novo;
    }
    else
    {
        atual = *inicio; /* atual aponta para o início */
        while(atual->proximo != NULL) /* enquanto o nó atual não for o último */
            atual = atual->proximo;    /* vai para o nó seguinte */

        novo->valor = valor;
        novo->anterior = atual;  /*o nó anterior ao novo é o nó atual */
        novo->proximo = NULL; /* não há próximo nó, pois o novo será o último */
        atual->proximo = novo; /* o nó atual aponta para o novo nó e não é mais o último */
    }
}

/* remove um nó escolhido pelo usuário */
int retira(NOLISTAPTR *inicio, int valor)
{

    NOLISTAPTR aux, atual;

    if(*inicio == NULL)
        return 0; /* retorna 0 caso a lista esteja vazia */

    atual = *inicio; /* o nó atual é o do início */

    if((*inicio)->valor == valor) /* caso o no a ser retirado seja o do inicio */
        *inicio = (*inicio)->proximo; /* o nó inicial passa a ser o próximo da lista */

    while(atual != NULL && atual->valor != valor) /*se há nó e o valor do mesmo não é o valor que se quer retirar*/
        atual = atual->proximo; /*passa para o próximo*/

    if(atual == NULL)
        return 0; /* retorna 0 se não encontrou o valor */
    /* caso tenha encontrado */
    else
    {
        aux = atual; /* aux aponta para o nó encontrado */

        if(atual->anterior != NULL)/* caso haja um nó anterior ao enontrado*/
            atual->anterior->proximo = atual->proximo; /* faz o nó anterior apontar para o nó posterior ao encontrado */

        if(atual->proximo != NULL) /* caso haja um nó posterior ao enontrado*/
            atual->proximo->anterior = atual->anterior; /* faz o nó posterior apontar para o nó anterior ao encontrado */

        free(aux);/* remove o nó encontrado */
    }

    return 1;
}

/* deleta um nó apartir do início da lista */
int elimina_no(NOLISTAPTR *inicio)
{

    NOLISTAPTR aux;
    int c;

    aux = *inicio; /* nó do início passa a ser temporário */
    c = (*inicio)->valor; /* pega o valor que estava no nó */
    *inicio = (*inicio)->proximo; /* o nó seguinte passa a ser o do início */
    free(aux); /* deleta o nó temporário */

    return c;
}

int lista_vazia(NOLISTAPTR lista)
{

    return lista == NULL;

}

void imprime_ordem_direta(NOLISTAPTR lista)
{

    if(lista_vazia(lista))
        printf("\n\nA lista está vazia.\n\n");
    else
    {
        printf("\nLista Direta:\n\n");
        while(lista != NULL)
        {
            printf("|%d|", lista->valor);
            lista = lista->proximo;
        }
        printf("\n\n");
    }
}

void imprime_ordem_inversa(NOLISTAPTR lista)
{

    if(lista_vazia(lista))
        printf("\n\nA lista está vazia.\n\n");
    else
    {
        while(lista->proximo != NULL) /* enquanto não chegar no último nó ...*/
            lista = lista->proximo;   /* ... percorre a lista */

        printf("\nLista Inversa:\n\n");
        while(lista != NULL)
        {
            printf("|%d|", lista->valor);
            lista = lista->anterior;
        }
        printf("\n\n");
    }
}

void main()
{
    setlocale(LC_ALL,"");

    NOLISTAPTR lista = NULL;
    int op;
    int valor;

    do
    {
        printf("\n<Menu>");
        printf("\n1-Inserir no inicio");
        printf("\n2-Inserir no final");
        printf("\n3-Remover um elemento da lista");
        printf("\n4-Imprimir a lista na ordem direta");
        printf("\n5-Imprimir a lista na ordem inversa");
        printf("\n6-Limpar a lista e Encerrar");

        printf("\n\nEscolha uma das opcoes: ");
        scanf("%d", &op);
        switch(op)
        {
        case 1:
            printf("\nDigite um valor para inserir no início: ");
            scanf("%d", &valor);
            insere_inicio(&lista, valor);
            break;
        case 2:
            printf("\nDigite um valor para inserir no fim: ");
            scanf("%d", &valor);
            insere_fim(&lista, valor);
            break;
        case 3:
            printf("\nDigite o valor a ser retirado: ");
            scanf("%d", &valor);
            if(! retira(&lista, valor))
            {
                printf("\nNão foi possível retirar este nó.\n");
            }
            break;
        case 4:
            imprime_ordem_direta(lista);
            break;
        case 5:
            imprime_ordem_inversa(lista);
            break;
        case 6:
            printf("\nLimpando lista ...\n\n");
            while(!lista_vazia(lista))  /* retira todos os nós não apagados para liberar a memória */
            {
                printf("No %d retirado\n", elimina_no(&lista));
            }
            printf("\nLista vazia\n");
            break;
        default:
            printf("\nComando Inválido.\n\n");
            break;
        }

    }
    while(op != 6);
}
