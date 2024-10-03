#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct cell
{
    int info; //conte�do da c�lula
    struct cell *next; //endere�o da pr�xima c�lula
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

void insere_inicio(CELULA **lista,int x)
{

    CELULA *q;

    q = getnode();
    if(q != NULL)
    {
        q->info = x;
        q->next = *lista;
        *lista = q;
    }
    else
    {
        printf("\nERRO: Falha na aloca��o do n�.\n");
        exit(1);
    }
}

void insere_fim(CELULA **lista, int x)
{

    CELULA *q;
    CELULA *aux;

    q = getnode();
    if(q!=NULL)
    {
        q->info = x;
        q->next = NULL;

        if(empty(*lista))
        {
            *lista = q;
        }
        else
        {
            //percorre lista at� chegar ao ultimo n�
            aux = *lista;
            while(aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = q;
        }
    }//fim do if q!=NULL
    else
    {
        printf("\nERRO: N�o foi poss�vel alocar o n�.\n");
        exit(1);
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

void remove_inicio(CELULA **lista)
{

    CELULA *q;

    q = *lista;
    if(!empty(*lista))
    {
        *lista = q->next;
        freenode(q);
    }
    else
    {
        printf("\nERRO: A lista est� vazia.\n");
        exit(1);
    }
}

int remove_valor(CELULA **lista, int x)
{

    CELULA *q;
    CELULA *aux;

    if((q = pesquisa(*lista, x)) != NULL)
    {
        aux = *lista;
        if(aux == q)  //n� est� no in�cio da lista
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
        return 1; //caso removeu
    }
    return 0; //se n�o removeu
}


void exibe_lista(CELULA *lista)
{

    CELULA *aux;
    aux = lista;
    printf("\nLista Ordenada: ");
    while(aux != NULL)
    {
        printf("|%d| ",aux->info);
        aux = aux ->next;
    }
    printf("\n");
}


void main()
{

    CELULA *ptrlista;
    int del,x;
    init(&ptrlista);

    setlocale(LC_ALL,"");

    printf("INSERE NO IN�CIO:\n");
    do
    {
        printf("\nInsira o valor de x para inserir na lista ordenada:");
        scanf("%d",&x);

        if(x!=0)
            insere_inicio(&ptrlista,x);
    }
    while(x!=0);
    exibe_lista(ptrlista);

    printf("\n\nINSERE NO FIM:\n");
    do
    {
        printf("\nInsira o valor de x para inserir na lista encadeada:");
        scanf("%d",&x);

        if(x!=0)
            insere_fim(&ptrlista,x);
    }
    while(x!=0);
    exibe_lista(ptrlista);

    printf("\n\nREMOVE O VALOR:\n");
    printf("\nInsira o valor a ser removido: ");
    scanf("%d",&x);

    del = remove_valor (&ptrlista, x);
    if(del == 0)
        printf("\nErro!");
    exibe_lista(ptrlista);

    printf("\n\nREMOVE O IN�CIO:\n");
    printf("\nPrimeiro n� removido.");
    remove_inicio(&ptrlista);
    exibe_lista(ptrlista);

    getch();

}

/*CELULA* inserirListaOrdem (CELULA* lista, int x){

    CELULA* atual = lista;
    CELULA* anterior = NULL;
    CELULA* q;

    q = getnode();
    if(q != NULL){
        q->info = x;
        q->next = NULL;
        //procura posi��o para inserir
        while(atual != NULL && atual->info < x){
            anterior = atual;
            atual = atual = atual->next;
        }


        //insere elemento
        if(atual == lista){
            //insere no inicio
            q->next = lista;
            lista = q;
        } else {
        //insere no meio ou fim
        anterior->next = q;
        q->next = atual;
        }
        return lista;
    } // fim do if de q!=NULL
    else{
        printf("\nERRO: N�o foi poss�vel alocar o n�.\n");
        return NULL;
    }
}*/
