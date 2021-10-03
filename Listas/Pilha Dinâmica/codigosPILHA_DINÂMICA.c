#include<stdio.h>
#include <stdlib.h>
#include<locale.h>


typedef struct cell
{
    int info;
    struct cell *next;
} cell;

typedef struct pilha
{
    struct cell *topo;
} pilha;

pilha *inicializar()
{
    pilha *p = (pilha*)malloc(sizeof(pilha));
    p->topo = NULL;
}

int pilha_vazia(pilha *p)
{
    if (p->topo == NULL)
        return 1;
    return 0;
}

int tamanho(pilha *p)
{
    cell *aux = p->topo;
    int tam = 0;

    if(pilha_vazia(p)==1)
    {
        return -1;
    }
    while(aux!= NULL)
    {
        // enquanto o elemento da pilha não estiver nulo
        // o tamanho irá aumentar
        tam++;
        aux = aux->next; // e irá avançar para o próximo elemento
    }
    return tam;
}

int retornaTopo(pilha *p)
{
    if(pilha_vazia(p))
    {
        return -1;
    }
    return p->topo->info;
}

int pesquisa(pilha *p, int info)
{
    cell *aux = p->topo;

    if(pilha_vazia(p)==1)
    {
        printf("\n|Pilha vazia|\n");
        return;
    }

    while(aux!=NULL)
    {
        if(aux->info==info)
        {
            return 1;
        }
        aux = aux->next;
    }
    return 0;
}

void imprime(pilha *p)
{
    cell *aux = p->topo;
    printf("\nPilha:\n");

    if(pilha_vazia(p)==1)
    {
        printf("\n|Pilha vazia|\n");
        return;
    }

    while(aux!= NULL)
    {
        printf("\n|%d|",aux->info);
        aux = aux->next;
    }
    printf("\n");
}

void empilhar(pilha *p, cell *info)
{

    cell *nova = (cell*)malloc(sizeof(cell));
    nova->info = info;
    nova->next = p->topo;
    p->topo = nova;
}

void desempilhar(pilha *p, cell *dado)
{
    cell *auxiliar;

    if(pilha_vazia(p) == 1)
    {
        printf("\nNão é possível desempilhar de uma pilha vazia.\n");
        return;
    }

    auxiliar = p->topo;
    p->topo = auxiliar->next;
    dado = auxiliar->next->info;
    free(auxiliar);
}

void main()
{
    setlocale(LC_ALL,"");

    pilha *p = inicializar();

    int op,num,retorno;

    do
    {
        printf("\n<Menu>\n");
        printf("\n1-Empilhar na Pilha");
        printf("\n2-Desempilhar da Pilha");
        printf("\n3-Verificar o Tamanho da Pilha");
        printf("\n4-Retornar o Topo da Pilha");
        printf("\n5-Verificar se a Pilha está Vazia");
        printf("\n6-Imprimir a Pilha");
        printf("\n7-Pesquisar na Pilha");
        printf("\n0-Encerrar");
        printf("\n\nSelecione uma Opção: ");
        scanf("%d",&op);

        switch(op)
        {

        case 1:
            printf("\nDigite um numero: ");
            scanf("%d",&num);
            empilhar(p,num);
            imprime(p);
            break;
        case 2:
            desempilhar(p,num);
            printf("\n");
            imprime(p);
            break;
        case 3:
            if(tamanho(p) == -1)
            {
                printf("\nA pilha está vazia.\n");
            }
            else
            {
                printf("\nO tamanho da pilha é: %d\n",tamanho(p));
            }
            break;
        case 4:
            if(retornaTopo(p) == -1)
            {
                printf("\nA pilha está vazia.\n");
            }
            else
            {
                printf("\nTopo: %d\n",retornaTopo(p));
            }
            break;
        case 5:
            if(pilha_vazia(p) == 1)
            {
                printf("\nA pilha está vazia.\n");
            }
            else
            {
                printf("\nA pilha não está vazia.\n\n");
                imprime(p);
            }
            break;
        case 6:
            imprime(p);
            break;
        case 7:
            printf("\nInsira o número que deseja pesquisar:");
            scanf("%d",&num);
            retorno = pesquisa(p,num);
            if(retorno!= 0)
            {
                printf("\nO Valor foi encontrado.\n",retorno);
            }
            else
            {
                printf("\nO Valor pesquisado, não foi encontrado.\n");
            }
            break;
        case 0:
            printf("\nEncerrando o Programa");
            break;
        default:
            printf("\nComando Inválido\n");
            break;
        }
    }
    while(op!= 0);
}

