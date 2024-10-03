#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct noLista  /* estrutura duplamente auto-referenciada */
{
    int valor;
    struct noLista *anterior, *proximo;
};

typedef struct noLista NOLISTA; /* defini��o do tipo NOLISTA a partir do tipo 'struct noLista' */
typedef NOLISTA *NOLISTAPTR; /* defini��o do tipo *NOLISTAPTR a partir do tipo NOLISTA */

/* insere um n� no in�cio da lista */
void insere_inicio(NOLISTAPTR *inicio, int valor)
{

    NOLISTAPTR novo;

    novo = (NOLISTAPTR) malloc(sizeof(NOLISTA)); /* aloca mem�ria para o novo n� */

    if(novo == NULL) /* se n�o houver mem�ria dispon�vel */
        return;      /* sai da fun��o */

    if(*inicio == NULL)     /* se a lista estivava vazia */
    {
        novo->valor = valor; /* insere o valor no novo n� */
        novo->proximo = novo->anterior = NULL; /* n�o h� pr�ximo n� nem n� anterior, pois s� h� um n� */
        *inicio = novo; /* o novo n� � o primeiro da lista */
    }
    else    /* se j� havia n� na lista */
    {
        novo->valor = valor; /* insere o valor no novo n� */
        novo->anterior = NULL; /* n�o h� n� anterior */
        novo->proximo = *inicio; /* o novo n� aponta para o que est� no in�cio */
        (*inicio)->anterior = novo; /* o n� atual do in�cio aponta para o novo n� */
        *inicio = novo; /* o novo n� passa a ser o primeiro da lista */
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
        atual = *inicio; /* atual aponta para o in�cio */
        while(atual->proximo != NULL) /* enquanto o n� atual n�o for o �ltimo */
            atual = atual->proximo;    /* vai para o n� seguinte */

        novo->valor = valor;
        novo->anterior = atual;  /*o n� anterior ao novo � o n� atual */
        novo->proximo = NULL; /* n�o h� pr�ximo n�, pois o novo ser� o �ltimo */
        atual->proximo = novo; /* o n� atual aponta para o novo n� e n�o � mais o �ltimo */
    }
}

/* remove um n� escolhido pelo usu�rio */
int retira(NOLISTAPTR *inicio, int valor)
{

    NOLISTAPTR aux, atual;

    if(*inicio == NULL)
        return 0; /* retorna 0 caso a lista esteja vazia */

    atual = *inicio; /* o n� atual � o do in�cio */

    if((*inicio)->valor == valor) /* caso o no a ser retirado seja o do inicio */
        *inicio = (*inicio)->proximo; /* o n� inicial passa a ser o pr�ximo da lista */

    while(atual != NULL && atual->valor != valor) /*se h� n� e o valor do mesmo n�o � o valor que se quer retirar*/
        atual = atual->proximo; /*passa para o pr�ximo*/

    if(atual == NULL)
        return 0; /* retorna 0 se n�o encontrou o valor */
    /* caso tenha encontrado */
    else
    {
        aux = atual; /* aux aponta para o n� encontrado */

        if(atual->anterior != NULL)/* caso haja um n� anterior ao enontrado*/
            atual->anterior->proximo = atual->proximo; /* faz o n� anterior apontar para o n� posterior ao encontrado */

        if(atual->proximo != NULL) /* caso haja um n� posterior ao enontrado*/
            atual->proximo->anterior = atual->anterior; /* faz o n� posterior apontar para o n� anterior ao encontrado */

        free(aux);/* remove o n� encontrado */
    }

    return 1;
}

/* deleta um n� apartir do in�cio da lista */
int elimina_no(NOLISTAPTR *inicio)
{

    NOLISTAPTR aux;
    int c;

    aux = *inicio; /* n� do in�cio passa a ser tempor�rio */
    c = (*inicio)->valor; /* pega o valor que estava no n� */
    *inicio = (*inicio)->proximo; /* o n� seguinte passa a ser o do in�cio */
    free(aux); /* deleta o n� tempor�rio */

    return c;
}

int lista_vazia(NOLISTAPTR lista)
{

    return lista == NULL;

}

void imprime_ordem_direta(NOLISTAPTR lista)
{

    if(lista_vazia(lista))
        printf("\n\nA lista est� vazia.\n\n");
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
        printf("\n\nA lista est� vazia.\n\n");
    else
    {
        while(lista->proximo != NULL) /* enquanto n�o chegar no �ltimo n� ...*/
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
            printf("\nDigite um valor para inserir no in�cio: ");
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
                printf("\nN�o foi poss�vel retirar este n�.\n");
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
            while(!lista_vazia(lista))  /* retira todos os n�s n�o apagados para liberar a mem�ria */
            {
                printf("No %d retirado\n", elimina_no(&lista));
            }
            printf("\nLista vazia\n");
            break;
        default:
            printf("\nComando Inv�lido.\n\n");
            break;
        }

    }
    while(op != 6);
}
