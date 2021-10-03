#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct cell
{
    int info; //conteúdo da célula
    struct cell *next; //endereço da próxima célula
} CELULA;

void *init(CELULA **lista)
{
    //Inicia o ponteiro externo para uma lista encadeada
    *lista = NULL;
}

int empty (CELULA *lista)  //verifica se a lista encadeada está vazia
{
    if(lista == NULL) //lista é o endereço do primeiro nó da lista
        return 1;
    return 0;
}

CELULA *getnode()
{
    //essa função aloca/cria um nó para uma lista encadeada
    return (CELULA*) malloc(sizeof(CELULA));
}

void freenode(CELULA *q)
{
    //liberar o espaço de memória ocupado por um nó
    //q seria o endereço a ser liberado
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
        printf("\nERRO: Falha na alocação do nó.\n");
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
            //percorre lista até chegar ao ultimo nó
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
        printf("\nERRO: Não foi possível alocar o nó.\n");
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
                return q; // encontrou o nó
            }
            q = q-> next; //avança para o próximo
        }
    }
    return NULL; // caso não encontre
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
        printf("\nERRO: A lista está vazia.\n");
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
        if(aux == q)  //nó está no início da lista
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
    return 0; //se não removeu
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

    printf("INSERE NO INÍCIO:\n");
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

    printf("\n\nREMOVE O INÍCIO:\n");
    printf("\nPrimeiro nó removido.");
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
        //procura posição para inserir
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
        printf("\nERRO: Não foi possível alocar o nó.\n");
        return NULL;
    }
}*/
