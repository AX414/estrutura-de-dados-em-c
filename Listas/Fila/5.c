#include<stdio.h>
#include<locale.h>

#define TAMMAX 100
typedef struct sPilha
{
    int itens[TAMMAX];
    int topo;

} Pilha;

void inicializar (Pilha *s)
{
    s->topo = -1;
}

int pilha_vazia(Pilha *s)
{
    if(s->topo == -1)
        return 1;
    return 0;
}

int pilha_cheia(Pilha *s)
{
    if(s->topo == TAMMAX-1)
        return 1;
    return 0;
}

void empilhar(Pilha *s, int val)
{
    if(pilha_cheia(s))
    {
        printf("\nErro - pilha cheia");
        return -1;
    }
    else
    {
        s->topo++;
        s->itens[s->topo]=val;
    }
}

int desempilhar(Pilha *s)
{
    char auxiliar;
    if(pilha_vazia(s))
    {
        printf("\nErro - pilha vazia");
        return -1;
    }
    else
    {
        auxiliar = s->itens[s->topo];
        s->topo--;
        return auxiliar;
    }
}

int retorna_topo(Pilha *s)
{
    if(pilha_vazia(s))
    {
        printf("\nErro - pilha vazia");
        return -1;
    }
    return s->itens[s->topo];
}

void imprime(Pilha *s)
{
    int i;

    if(pilha_vazia(s))
    {
        printf("\nErro - pilha vazia");
    }

    for(i=(s->topo); i>=0; i--)
    {
        printf("\n|%d|",s->itens[i]);
    }

}

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

void inverterFila(Fila *f)
{

    Pilha s;
    inicializar(&s);

    int aux,i = ((f->inicio+1)%TAMMAX);

    if(!vazia(f))
    {
        while(i!=((f->fim+1)%TAMMAX))//enquanto a fila não estiver vazia, empilhe na pilha
        {
            aux = desenfileirar(f);// tira da fila
            empilhar(&s,aux);//empilhando na pilha
            i = (i+1)%TAMMAX;
        }
    }
    printf("\n\nFila depois:");
    imprimir(&f);

    printf("\n\nPilha depois de receber a fila:");
    imprime(&s);

    int valor;
    if(!pilha_vazia(&s))
    {
        while(!pilha_vazia(&s))//enquanto a pilha não estiver vazia, enfileira na fila
        {
            valor = desempilhar(&s);
            enfileirar(f,valor);
        }
    }
    printf("\n\nPilha depois:");
    imprime(&s);
    printf("\n\nFila após receber a transferência: ");
    imprimir(f);


}


int main()
{
    setlocale(LC_ALL,"");
    Fila ptrFila;
    inicializa(&ptrFila);
    enfileirar(&ptrFila,2);
    enfileirar(&ptrFila,3);
    enfileirar(&ptrFila,4);
    enfileirar(&ptrFila,5);
    printf("\n\nFila antes de transferir itens para Pilha:");
    imprimir(&ptrFila);
    inverterFila(&ptrFila);
    printf("\n\n\n");
}
