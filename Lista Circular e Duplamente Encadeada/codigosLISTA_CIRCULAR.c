#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct cell
{
    int info;
    struct cell *next;
} CELULA;

void *init(CELULA **lista)
{
    //Inicia o ponteiro externo para uma lista encadeada
    *lista = NULL;
}

int empty (CELULA *lista)  //verifica se a lista encadeada est� vazia
{
    if(lista == NULL) //lista � o endere�o do primeiro n� da lista
        return 1;
    return 0;
}

CELULA *getnode()
{
    //essa fun��o aloca/cria um n� para uma lista encadeada
    return (CELULA*) malloc(sizeof(CELULA));
}

void freenode(CELULA *q)
{
    //liberar o espa�o de mem�ria ocupado por um n�
    //q seria o endere�o a ser liberado
    free(q);
}

void insere_fim(CELULA**lista,int x)
{

    CELULA *q;

    q = getnode();
    if(q != NULL)
    {
        q->info = x;

        if(empty(*lista))
        {
            q->next = q;
        }
        else
        {
            q->next = (*lista)->next;
            (*lista)->next = q;
        }
        *lista = q;
    }// fim do if (q!=NULL)
    else
    {
        printf("\nERRO: N�o foi poss�vel alocar o n�.");
        exit(1);
    }

}

void remove_inicio(CELULA ** lista)
{

    CELULA *aux;

    if(!empty(*lista))
    {
        if((*lista) == (*lista)->next)
        {
            freenode(*lista);
            *lista = NULL;
        }
        else
        {
            aux = (*lista)->next;
            (*lista)->next = aux->next;
            freenode(aux);
        }
    }
    else
    {
        printf("\nERRO: A lista est� vazia.\n");
        exit(1);
    }
}

void listar (CELULA *lista)
{

    CELULA *aux;

    aux = lista->next;

    printf("\nLista Circular: ");
    if(aux != NULL)
    {
        do
        {
            printf("|%d|",aux->info);
            aux = aux->next;
        }
        while(aux!=lista->next);
    }
    else
    {
        printf("\nN�o h� elemento na lista.");
    }
    printf("\n\n");
}


void main()
{
    setlocale(LC_ALL,"");

    CELULA *ptrlista;
    init(&ptrlista);
    int x;

    printf("INSERE NO FIM:\n");
    do
    {
        printf("\nInsira o valor de x para inserir na lista circular:");
        scanf("%d",&x);

        if(x!=0)
            insere_fim(&ptrlista,x);
    }
    while(x!=0);
    listar(ptrlista);

    printf("\n\nREMOVE O IN�CIO:\n");
    printf("Insira quantos n�s voc� deseja remover:");
    scanf("%d",&x);

    for(int i = 0; i<x; i++)
    {
        printf("\n%d� n�(s) removido(s).",i+1);
        remove_inicio(&ptrlista);
    }
    printf("\n");
    listar(ptrlista);

}
