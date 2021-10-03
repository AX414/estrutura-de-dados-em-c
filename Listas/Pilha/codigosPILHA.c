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
        printf("\n|%s|",s->itens[i]);
    }

}


int main()
{

    Pilha s;
    Pilha z;


    inicializar(&s);
    inicializar(&z);

    printf("Imprime Pilha S vazia:");
    imprime(&s);

    empilhar(&s,1);
    empilhar(&s,2);
    empilhar(&s,3);
    empilhar(&s,4);


    printf("\n\nPilha:\n");
    imprime(&s);
    int top1 = retorna_topo(&s);
    printf("\n\nTopo da pilha: %d\n",top1);
    imprime(&s);
    printf("\n\nPilha desempilhando: \n");
    desempilhar(&s);
    int top2 = retorna_topo(&s);
    printf("\nTopo da pilha: %d\n",top2);
    imprime(&s);

    //inserindo apenas pares

    int valor;
    int j;

    for(j=0; j<3; j++)
    {
        printf("\n\nEscreva um valor para inserir na pilha z:");
        scanf("%d",&valor);

        if(valor%2==0)//par
        {
            printf("\nPar - Empilhar");
            empilhar(&z,valor);
        }
        else//impar
        {
            printf("\nImpar - Desempilhar");
            desempilhar(&z);
        }
    }

    printf("\n\nPilha z:\n");
    imprime(&z);

    printf("\n\n\n");
}
