#include<stdio.h>
#include<locale.h>

#define TAMMAX 10
typedef struct sDeque
{
    int items[TAMMAX];
    int inicio,fim;
} Deque;

void inicializaDeque(Deque *d)
{
    d->inicio = TAMMAX -1;
    d->fim = TAMMAX -1;
}

int cheio(Deque *d)
{
    if(d->fim == d->inicio)
        return 1;
    return 0;
}

int vazio(Deque *d)
{
    if(d->fim == d->inicio)
        return 1;
    return 0;
}

void insereInicio(Deque *d, int x)
{

    if(d->inicio==0)
    {
        d->inicio = TAMMAX -1;
    }
    else
    {
        (d->inicio)--;
    }

    if(cheio(d))
    {
        printf("\nERRO - Deque cheio\n");
        d->inicio = (d->inicio+1)%TAMMAX;
        return;
    }
    d->items[(d->inicio+1)%TAMMAX] = x;
}

void insereFim(Deque *d, int x)
{

    if(d->fim==0)
    {
        d->fim = TAMMAX -1;
    }
    else
    {
        (d->fim)++;
    }

    if(cheio(d))
    {
        printf("\nERRO - Deque cheio\n");
        d->inicio = (d->fim)%TAMMAX;
        return;
    }
    d->items[(d->fim)%TAMMAX] = x;
}

int removerFim(Deque *d)
{
    int aux = 0;

    if(!vazio(d))
    {
        if(d->fim==0)
        {
            d->fim = TAMMAX -1;
        }
        else
        {
            d->fim--;
        }
        aux = d->items[d->fim];
    }
    else
    {
        printf("\nErro - Deque vazio\n");
    }

    return (aux);

}

int removerInicio(Deque *d)
{
    int aux = 0;

    if(!vazio(d))
    {
        if(d->inicio==0)
        {
            d->inicio = TAMMAX -1;
        }
        else
        {
            d->inicio++;
        }
        aux = d->items[d->inicio];
    }
    else
    {
        printf("\nErro - Deque vazio\n");
    }

    return (aux);

}

void imprimirDeque(Deque *d)
{
    int i = (d->inicio+1) %TAMMAX;
    if(!vazio(d))
    {
        printf("\nDeque: ");
        while(i!=((d->fim+1)%TAMMAX))
        {
            printf("|%d|",d->items[i]);
            i = (i+1)%TAMMAX;
        }
    }
    else
        printf("\nDeque vazio.");
}

int comprimentoDeque(Deque *d)
{
    int i = (d->inicio+1) %TAMMAX;
    int comp = 0;
    if(!vazio(d))
    {
        while(i!=((d->fim+1)%TAMMAX))
        {
            comp++;
            i = (i+1)%TAMMAX;
        }
    }
    else
        printf("\nDeque vazio.");

    return comp;
}

/*
void imprimirDequeClassica(Deque *d)
{
    int i,valor;
    int comp = comprimentoDeque(d);
    int vetor[comp];

    for(i=0; i<5; i++)
    {
        valor = removerInicio(d);
        vetor[i] = valor;
    }

    printf("\n\nImprime deque sem items: ");
    imprimirDeque(d);

    for(i=0; i<5; i++)
    {
        printf("|%d|",vetor[i]);
    }

    for(i=0; i<5; i++)
    {
        insereInicio(d,vetor[i]);
    }
    printf("\n\nImprime deque de volta: ");
    imprimirDeque(d);
}
*/

int main()
{

    Deque d;
    inicializaDeque(&d);
    printf("Imprime Deque vazio: ");
    imprimirDeque(&d);
    insereInicio(&d,1);
    insereInicio(&d,2);
    insereInicio(&d,3);
    insereInicio(&d,4);
    printf("\n\nImprime deque com items (1,2,3 e 4):");
    imprimirDeque(&d);
    printf("\n\nImprime removendo o inicio:");
    removerInicio(&d);
    imprimirDeque(&d);
    printf("\n\nImprime removendo o fim:");
    removerFim(&d);
    imprimirDeque(&d);
    printf("\n\nImprime inserindo no fim (5,6 e 7):");
    insereFim(&d,5);
    insereFim(&d,6);
    insereFim(&d,7);
    imprimirDeque(&d);
    printf("\n\nComprimento do Deque: %d",comprimentoDeque(&d));
    //imprimirDequeClassica(&d);

    printf("\n\n\n");

}
