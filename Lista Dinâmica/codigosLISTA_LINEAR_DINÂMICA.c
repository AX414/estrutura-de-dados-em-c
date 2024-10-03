#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct cell
{
    int info; //conte�do da c�lula
    struct cell *next; //endere�o da pr�xima c�lula
} CELULA;

CELULA *init(CELULA *lista)
{
    //inicializa o ponteiro externo � lista com o valor NULL
    lista = NULL;
    return lista;
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

CELULA *insere_inicio(CELULA *lista, int x)
{

    CELULA *q;

    q = getnode();
    if(q!=NULL)
    {
        q->info = x;
        q->next = lista;
        lista = q;
        return lista;
    }
    else
    {
        printf("\nERRO na aloca��o do n�.\n");
        return NULL;
    }

}

CELULA *insere_fim(CELULA *lista, int x)
{

    CELULA *q;
    CELULA *aux;

    q = getnode();
    if(q!=NULL)
    {
        q->info = x;
        q->next = NULL;

        if(empty(lista))
        {
            lista = q;
        }
        else
        {
            aux = lista;
            while(aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = q;
        }
        return lista;
    } //fim do if (q!=NULL)
    else
    {
        printf("\nERRO na aloca��o do n�.\n");
        return NULL;

    }

}

CELULA *remove_inicio(CELULA *lista)
{

    CELULA *q;

    q = lista;
    if(!empty(lista))  // h� itens na lista
    {
        lista = q->next;
        freenode(q);
        return lista;
    }
    else
    {
        printf("\nERRO: lista vazia.");
        return NULL;
    }

}

CELULA *pesquisa (CELULA *lista,int x)
{

    CELULA *q;

    if(!empty(lista))
    {
        q = lista;
        while(q!=NULL)
        {
            if(q->info == x)
            {
                return q; // encontrou o n�
            }
            q = q-> next; //avan�a para o pr�ximo
        }
    }
    return NULL; // caso n�o encontre
}

CELULA *remove_valor(CELULA *lista, int x)
{

    CELULA *q, *aux;

    if((q=pesquisa(lista,x)) != NULL)
    {
        aux = lista;
        if(aux == q)  //n� est� no inicio da lista
        {
            remove_inicio(lista);
        }
        else
        {
            while(aux->next != q)
            {
                aux = aux->next;
            }
            aux->next = q->next;
            freenode(q);
        }
        return lista; //removeu
    }
    return NULL; //n�o removeu
}


void exibe_lista(CELULA *lista)
{

    CELULA *aux;
    aux = lista;
    printf("\nLista Encadeada: ");
    while(aux != NULL)
    {
        printf("|%d| ",aux->info);
        aux = aux ->next;
    }
    printf("\n");
}

//Lista auto-organizada

CELULA* moveFrente (CELULA *lista,int x)
{
    CELULA *q;

    if(!empty(lista))
    {
        q = lista;
        while(q!=NULL)
        {
            if(q->info == x)
            {
                q = remove_valor(lista,x);
                q = insere_inicio(lista,x);
                return q; // encontrou o n�
            }
            q = q-> next; //avan�a para o pr�ximo
        }
    }
    return NULL; // caso n�o encontre
}

/*CELULA* transposicao (CELULA *lista,int x)
{
    CELULA *q;

    if(!empty(lista))
    {
        q = lista;
        while(q!=NULL)
        {
            if(q->info == x)
            {
                int auxA, auxB;

                auxA = x;
                q = remove_valor(lista,x);

                q = insere_fim(lista,auxB);
                return q; // encontrou o n�
            }
            q = q-> next; //avan�a para o pr�ximo
        }
    }
    return NULL; // caso n�o encontre
}
*/

void main()
{
    setlocale(LC_ALL,"");

    //instanciando um ponteiro externo que
    //aponta para o primeiro n� da lista.
    CELULA *ptrlista;
    ptrlista = init(ptrlista);

    int x;

    printf("INSERE NO IN�CIO:\n");
    do
    {
        printf("\nInsira o valor de x para inserir na lista encadeada:");
        scanf("%d",&x);

        if(x!=0)
            ptrlista = insere_inicio(ptrlista,x);
    }
    while(x!=0);
    exibe_lista(ptrlista);

    printf("\n\nINSERE NO FIM:\n");
    do
    {
        printf("\nInsira o valor de x para inserir na lista encadeada:");
        scanf("%d",&x);

        if(x!=0)
            ptrlista = insere_fim(ptrlista,x);
    }
    while(x!=0);
    exibe_lista(ptrlista);

    printf("\n\nLISTA AUTO-ORGANIZADA: Mover-para-frente\n");
    do
    {
        printf("\nInsira o valor de x para inserir na lista encadeada:");
        scanf("%d",&x);
        if(x!=0)
            ptrlista = moveFrente(ptrlista,x);
    }
    while(x!=0);
    exibe_lista(ptrlista);

    printf("\n\nREMOVE O VALOR:\n");
    printf("\nInsira o valor a ser removido: ");
    scanf("%d",&x);

    ptrlista = remove_valor(ptrlista,x);
    exibe_lista(ptrlista);

    printf("\n\nREMOVE O IN�CIO:\n");
    printf("\nPrimeiro n� removido.");
    ptrlista = remove_inicio(ptrlista);
    exibe_lista(ptrlista);
}
