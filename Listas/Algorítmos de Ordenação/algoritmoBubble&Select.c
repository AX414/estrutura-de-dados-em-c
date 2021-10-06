/*
O programa a seguir tem o intuito de demonstrar a diferença entre os modos de 
ordenação de um vetor por Bubble-Sort e Select-Sort, além disso, há nele presente 
os dois tipos de buscas em que se pode ser realizada: Busca Exaustiva e Busca Sequencial 
(que é necessário um vetor ordenado para executar de forma correta).

Com relação ao exercício, eu deveria permitir que o usuário preenchesse um vetor de tamanho 15 
e fosse capaz de executar as duas buscas e ordená-lo das duas formas.
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define TAM  15

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

void apresentarVetor(int vet[])
{

    int i;

    printf("\nApresentando o Vetor:\n");
    for(i=0; i<TAM; i++)
    {
        printf("\nVet[%d] = %d",i,vet[i]);
    }

    printf("\n\n");

}

void selection_sort (int vetor[])
{
    int i, j, min, aux,trocas = 0;
    for (i = 0; i < (TAM - 1); i++)
    {
        /* O minimo é o primeiro número não ordenado ainda */
        min = i;
        for (j = i+1; j < TAM; j++)
        {
            /* Caso tenha algum numero menor ele faz a troca do minimo*/
            if (vetor[j] < vetor[min])
            {
                min = j;
            }
        }
        /* Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
        if (i != min)
        {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
            trocas++;
            printf("\n|Troca %d -> %d por %d|",trocas,vetor[min],vetor[i]);
        }
    }
    printf("\n");
    apresentarVetor(vetor);
    printf("\nFora(m) Realizada(s) %d Troca(s).\n\n", trocas);
}


void bubble_sort(int vetor[])
{
    int i,j,aux,trocas;
    for(i=0; i<TAM; i++)
    {
        for(j=i; j<TAM; j++)
        {
            if(vetor[j]<vetor[i])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
                trocas++;
                printf("\n|Troca %d -> %d por %d|",trocas,vetor[j],vetor[i]);
            }
        }
    }
    printf("\n");
    apresentarVetor(vetor);
    printf("\nFora(m) Realizada(s) %d Troca(s).\n\n", trocas);
}

void main()
{
    setlocale(LC_ALL,"");
    int vet[TAM],i = 0;
    int op,retorno,num;

    do
    {
        printf("<Menu>");
        printf("\n1-Inserir valores no Vetor.");
        printf("\n2-Apresentar Vetor.");
        printf("\n3-Ordenar vetor por Buble-Sort");
        printf("\n4-Ordenar vetor por Select-Sort");
        printf("\n5-Executar Busca Exaustiva no Vetor Desordenado");
        printf("\n6-Executar Busca Sequencial no Vetor Ordenado.");
        printf("\n0-Encerrando Programa.");
        printf("\n\nSelecione uma Opção: ");
        scanf("%d",&op);

        switch(op)
        {
        case 1:
            printf("\nInserindo valores no vetor:\n\n");
            i = 0;
            do
            {
                printf("Insira o valor que deseja inserir na posição %d: ",i);
                scanf("%d",&vet[i]);
                i++;
            }
            while(i!=TAM);
            printf("\n");
            break;
        case 2:
            apresentarVetor(vet);
            break;
        case 3:
            bubble_sort(vet);
            break;
        case 4:
            selection_sort(vet);
            break;
        case 5:
            printf("\nInsira a chave da pesquisa: ");
            scanf("%d",&num);
            retorno = buscaExaustiva(num,vet);
            if(retorno != -1)
                printf("\nA chave foi encontrada na posição %d.\n\n",retorno);
            else
                printf("\nA chave não foi encontrada no vetor.\n\n");
            break;
        case 6:
            printf("\nInsira a chave da pesquisa: ");
            scanf("%d",&num);
            retorno = buscaSequencial(num,vet);
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
