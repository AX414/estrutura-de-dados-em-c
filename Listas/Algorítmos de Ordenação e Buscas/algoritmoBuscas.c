#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int buscaExaustiva (int elem,int vetor[])
{
    int i=0;
    while (vetor[i] != NULL)
    {
        if (vetor[i] == elem)
        {
            return i; // achou na posição i
        }
        else if(vetor[i] != elem && vetor[i] != NULL)
        {
            i++;
        }

        if(vetor[i]!= elem && vetor[i] == NULL)
        {
            return -1;   // não achou
        }

    }
}

int buscaSequencial(int elem, int vetor[])
{
    int i=0;
    while (vetor[i] != NULL)
    {

        if (vetor[i] == elem)
        {
            return i; // achou na posição i
        }
        else if(elem != vetor[i] && elem >vetor [i])
        {
            i++;
        }

        if(vetor[i]>elem)
        {
            return -1; // não achou
        }

    }

}

int buscaBinaria ( int vetor[], int elem)
{
    int inicio = 0;
    int fim = 9;
    int meio;
    while (inicio <= fim)
    {
        meio = (inicio + fim)/2;
        printf("\nMeio: %d\n",meio);
        if (elem == vetor[meio])
            return meio;
        if (elem < vetor[meio])
            fim = meio-1;
        else
            inicio = meio+1;
    }
    return -1; // não encontrado
}

void apresentarVetor(int vet[10])
{

    int i;

    printf("\nApresentando o Vetor:\n");
    for(i=0; i<10; i++)
    {
        printf("\nVet[%d] = %d",i,vet[i]);
    }

    printf("\n\n");

}


void main()
{
    setlocale(LC_ALL,"");
    int vetDesordenado[10] = {10,12,20,30,1,4,7,9,90,45};
    int vetOrdenado[10]    = {1,4,7,9,10,12,20,30,45,90};
    int op,retorno,num;

    do
    {
        printf("<Menu>");
        printf("\n1-Apresentar Vetor.");
        printf("\n2-Executar Busca Exaustiva no Vetor Desordenado");
        printf("\n3-Executar Busca Sequencial no Vetor Ordenado.");
        printf("\n4-Executar Busca Binária no Vetor Ordenado.");
        printf("\n0-Encerrando Programa.");
        printf("\n\nSelecione uma Opção: ");
        scanf("%d",&op);

        switch(op)
        {

        case 1:

            printf("\nVetores:\n1-Desordenado.\n2-Ordenado.\n\nSelecione qual vetor deseja apresentar:");
            scanf("%d",&op);

            if(op==1)
                apresentarVetor(vetDesordenado);
            else
                apresentarVetor(vetOrdenado);

            break;
        case 2:
            printf("\nInsira a chave da pesquisa: ");
            scanf("%d",&num);
            retorno = buscaExaustiva(num,vetDesordenado);
            if(retorno != -1)
                printf("\nA chave foi encontrada na posição %d.\n\n",retorno);
            else
                printf("\nA chave não foi encontrada no vetor.\n\n");
            break;
        case 3:
            printf("\nInsira a chave da pesquisa: ");
            scanf("%d",&num);
            retorno = buscaSequencial(num,vetOrdenado);
            if(retorno != -1)
                printf("\nA chave foi encontrada na posição %d.\n\n",retorno);
            else
                printf("\nA chave não foi encontrada no vetor.\n\n");
            break;
        case 4:
            printf("\nInsira a chave da pesquisa: ");
            scanf("%d",&num);
            retorno = buscaBinaria(vetOrdenado,num);
            if(retorno != -1)
                printf("\nA chave foi encontrada na posição %d.\n\n",retorno);
            else
                printf("\nA chave não foi encontrada no vetor.\n\n");
            break;
        case 0:
            printf("\nPrograma Finalizado.\n");
            break;
        default:
            printf("\nComando Inválido.\n");
            break;


        }
    }
    while(op!=0);

}
