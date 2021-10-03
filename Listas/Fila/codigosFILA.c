#include<stdio.h>
#include<locale.h>

#define TAMMAX 10
typedef struct sFila
{
    int items[TAMMAX]; //define uma fila de 10 slots
    int inicio, fim; //variável que determina o início e o fim dessa fila
} Fila;

void inicializa (Fila *f)
{
    f->inicio = TAMMAX -1;
    f->fim = TAMMAX -1;
}

int vazia (Fila *f)
{
    if(f->fim == f->inicio)
        return 1;
    return 0;
}

int cheia (Fila *f)
{
    if(f->fim == f->inicio)
        return 1;
    return 0;
}

void enfileirar (Fila *f, int x)
{
    if(f->fim == (TAMMAX-1))
    {
        f->fim = 0;
    }
    else
    {
        (f->fim)++;
    }
    if(cheia(f))
    {
        printf("\nErro - fila cheia.\n");
        (f->fim)--;
        if(f->fim == -1)
            f->fim = TAMMAX -1;
        return;
    }
    f->items[f->fim] = x;
}

int desenfileirar (Fila *f)
{

    int aux = 0;
    if(!vazia(f))
    {
        if(f->inicio == TAMMAX-1)
        {
            f->inicio = 0;
        }
        else
        {
            f->inicio++;
        }
        aux = f->items[f->inicio];
    }
    else
    {
        printf("\nErro - fila vazia.\n");
    }
    return (aux);
}

void imprimir (Fila *f)
{
    int i = (f->inicio+1) %TAMMAX;
    if(!vazia(f))
    {
        printf("\nFila: ");
        while(i!=((f->fim+1)%TAMMAX))
        {
            printf("|%d|",f->items[i]);
            i = (i+1)%TAMMAX;
        }
    }
    else
        printf("\nFila vazia.");
}

int comprimento (Fila *f)
{
    int i = (f->inicio+1) %TAMMAX;
    int comp = 0;
    if(!vazia(f))
    {
        while(i!=((f->fim+1)%TAMMAX))
        {
            comp++;
            i = (i+1)%TAMMAX;
        }
    }
    else
        printf("\nFila vazia.");

    return comp;
}


int main(){

Fila ptrFila;
inicializa(&ptrFila);
enfileirar(&ptrFila,2);
enfileirar(&ptrFila,3);
enfileirar(&ptrFila,4);
enfileirar(&ptrFila,5);
printf("Fila Completa:");
imprimir(&ptrFila);
printf("\nComprimento: %d",comprimento(&ptrFila));
printf("\n\nFila desenfileirando 1 item da fila:");
desenfileirar(&ptrFila);
imprimir(&ptrFila);
printf("\nComprimento: %d",comprimento(&ptrFila));



printf("\n\n\n");
}
