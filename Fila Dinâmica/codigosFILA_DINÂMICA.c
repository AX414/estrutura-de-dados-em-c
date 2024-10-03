#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


typedef struct  NOFILA
{
    int valor;
    struct NOFILA *next;
} NOFILA;
//
typedef struct FILA
{
    struct NOFILA *inicio;
    struct NOFILA *fim;
} FILA;

FILA *inicializa()
{
    FILA *aux = (FILA*)malloc(sizeof(FILA));

    if(!aux)
    {
        printf("\nNão foi possível inicializar a fila.\n");
        exit(0);
    }
    else
    {
        aux->inicio = NULL;
        aux->fim = NULL;
    }


    return aux;
}

int fila_vazia(FILA *fila)
{
    if(fila==NULL)
    {
        return 1;
    }

    if(fila->inicio==NULL)
    {
        return 1;
    }
    return 0;
}


NOFILA *allocate(int valor)
{
    NOFILA* no = (NOFILA*)malloc(sizeof(NOFILA));
    if(!no)
    {
        printf("\nNão foi possível alocar o nó.\n");
    }
    else
    {
        no->valor = valor;
        no->next = NULL;
        return no;
    }
}

int lerValor()
{
    int valor;
    printf ("\nInsira o valor que deseja alocar na Fila: ");
    scanf("%d",&valor);
    return valor;
}

void enfileirar(FILA *fila)
{
    NOFILA *no = allocate(lerValor());
    if(!no)
    {
        printf("\nNão foi possível alocar o nó.\n");
        return;
    }

    if(fila->fim == NULL)
    {
        fila->inicio = no;
    }

    if(fila->fim != NULL)
    {
        fila->fim->next = no;
    }

    fila->fim = no;
}

int desenfileirar(FILA *fila)
{
    if(fila_vazia(fila))
    {
        printf("\nA fila está vazia.");
        return 0;
    }

    NOFILA *no = fila->inicio;
    fila->inicio = fila->inicio->next;
    if(fila->inicio!=NULL)
    {
        fila->fim = NULL;
    }

    free(no);
    return 1;
}

void imprimir(FILA *fila)
{
    if(fila_vazia(fila))
    {
        printf ("\nA Fila está vazia.");
        return ;
    }

    NOFILA *aux = fila->inicio;
    printf ("\nFila: ");
    while(aux!=NULL)
    {
        printf ("|%d|",aux->valor);
        aux = aux->next;
    }
    printf ("\n\n");
}

int comprimento(FILA *fila)
{

    int qtd = 0;

    if(fila_vazia(fila)==1)
    {
        printf("\nA fila está vazia.\n");
        return -1;
    }
    else
    {
        NOFILA *aux = fila->inicio;
        while(aux!=NULL)
        {
            qtd++;
            aux = aux->next;
        }
    }
    return qtd;
}

void main()
{

    setlocale(LC_ALL,"");

    FILA *fila = inicializa();

    int op;
    int qtd;

    do
    {
        printf ("\n<Menu>\n");
        printf ("\n1-Enfileirar");
        printf ("\n2-Desenfileirar");
        printf ("\n3-Apresentar");
        printf ("\n4-Apresentar o Comprimento");
        printf("\n0-Encerrar");
        printf ("\n\nSelecione uma Opção:");
        scanf("%d",&op);

        switch(op)
        {

        case 1:
            enfileirar(fila);
            break;
        case 2:
            desenfileirar(fila);
            break;
        case 3:
            imprimir(fila);
            break;
        case 4:
            qtd = comprimento(fila);

            if(qtd == -1)
            {
                qtd = 0;
            }
            printf("\nO comprimento da fila é de: %d\n",qtd);
            break;
        case 0:
            printf("\nPrograma Encerrado.\n");
            break;
        default:
            printf("\nComando Inválido.\n");
            break;
        }
    }
    while(op!=0);
}
