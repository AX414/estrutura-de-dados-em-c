#include<stdio.h>
#include<locale.h>

#define TAMF 10
typedef struct lista
{
    /*definindo estrutura da lista
    com tamanho de 10 e indice n*/
    char valor[TAMF];
    int n;
} LISTA;

void inicializar(LISTA *L)  //inicializa a lista com -1, pois o vetor inicia com 0
{
    L->n = -1;
}

char acessar_elemento(LISTA *L, int k)
{
    /*
    Essa fun��o retorna o elemento que est� localizado no indice k
    */

    if((k<0) || (k> (L->n)))
        printf("\nErro - elemento fora do limite permitido.");
    else
        return L->valor[k];


}

int buscar_elemento(LISTA *L, char val_b)
{
    /*
    Essa fun��o recebe um valor e
    deve retornar o indice de onde o elemento se encontra
    */

    int elemento = -1;
    int i =0;

    while(i<=(L->n))
    {
        if(val_b == L->valor[i])
        {
            elemento = i;

            break;
        }
        i++;
    }

    return elemento;

}

int determina_tamanho(LISTA *L)
{
    return L->n+1;
}

int lista_cheia(LISTA *L)
{
    if(L -> n+1 == TAMF)
        /*se o indice for igual ao tamanho m�ximo, retorna 1,
         ou seja verdade que est� cheia*/
        return 1;
    else
        return 0;

}

int lista_vazia(LISTA *L)
{
    if(L -> n == -1)
        /*se o indice for igual ao -1(nada), retorna 1,
         ou seja verdade que est� vazia*/
        return 1;
    else
        return 0;

}

int inserirNoInicio(LISTA *L, char elemento)
{

    if(lista_cheia(L))
    {
        printf("\nErro - A lista est� cheia.");
        return 1;
    }

    int i;

    for(i=(L->n+1); i>0; i--)
    {
        L->valor[i] = L->valor[i-1];
    }

    L-> valor[0] = elemento;

    return 0;

}

int inserirNaPosicao(LISTA *L, int k, char elemento)
{

    if(lista_cheia(L))
    {
        printf("\nErro - lista cheia.");
        return 1;
    }
    if(k<0||k>(L->n+1))
    {
        printf("\nErro - o elemento est� fora dos limites.");
        return 1;
    }

    int i;

    for(i=(L->n+1); i>k; i--)
    {
        L->valor[i] = L->valor[i-1];
    }

    L->valor[k] = elemento;
    L->n = L->n+1;
    return 0;
}

int inserirNoFim(LISTA *L, char elemento)
{

    if(lista_cheia(L))
    {
        printf("\nErro - lista cheia.");
        return 1;
    }

    int i;

    for(i=(L->n+1); i>L->n+1; i--)
    {
        L->valor[i] = L->valor[i-1];
    }

    L->valor[L->n+1] = elemento;
    L->n = L->n+1;
    return 0;
}

int modificar_elemento(LISTA *L, int k, char elemento)
{

    if(k<0||k>L->n)
    {
        printf("\nErro - elemento fora dos limite.");
        return 1;
    }

    L->valor[k] = elemento;
    return 0;


}

int remover_elemento(LISTA *L, int k)
{

    int i;

    if(k<0||k>L->n)
    {
        printf("\nErro - elemento fora dos limites.");
        return 1;
    }

    for(i=k; i<(L->n); i++)
    {
        L->valor[i] = L-> valor[i+1];
    }

    L->n = L-> n-1;
    return 0;
}

int removerInicio(LISTA *L)
{

    int i;

    for(i=0; i<(L->n); i++)
    {
        L->valor[i] = L-> valor[i+1];
    }

    L->n = L-> n-1;
    return 0;
}

void imprimir_lista(LISTA *L)
{

    int i;

    for(i=0; i<(L->n+1); i++)
        printf("|%d|",L->valor[i]);


}

int main()
{
    setlocale(LC_ALL,"");
    LISTA L; //declara lista do tipo LISTA
    inicializar(&L); // inicializa a lista passando o endere�o da mesma como par�metro
    inserirNoFim(&L,4);
    inserirNoFim(&L,3);
    inserirNoFim(&L,70);
    inserirNoFim(&L,50);
    printf("Lista completa: ");
    imprimir_lista(&L);

    inserirNaPosicao(&L,2,12);
    printf("\nLista inserindo o elemento 2(n�mero 12): ");
    imprimir_lista(&L);

    inserirNaPosicao(&L,2,13);
    printf("\nLista inserindo o elemento 2(n�mero 13): ");
    imprimir_lista(&L);

    modificar_elemento(&L,2,41);
    printf("\nLista modificando o elemento 2(n�mero 13) para o n�mero 41: ");
    imprimir_lista(&L);

    int tamanho = determina_tamanho(&L);
    printf("\n\nTamanho da lista: %d",tamanho);

    int retornaElemento = buscar_elemento(&L,4);
    printf("\nO elemento 50 est� na lista? (-1 indica que n�o, 0 indica que sim): %d",retornaElemento);

    int retornaIndice = acessar_elemento(&L,3);
    printf("\nO indice 3 guarda o elemento: %d",retornaIndice);

    inserirNoInicio(&L,121);
    printf("\n\nLista inserindo no inicio (n�mero 121):\t ");
    imprimir_lista(&L);

    removerInicio(&L);
    printf("\nLista removendo no inicio:\t\t ");
    imprimir_lista(&L);

    inserirNoFim(&L,33);
    printf("\nLista inserindo no fim (n�mero 33):\t ");
    imprimir_lista(&L);

    remover_elemento(&L,2);
    printf("\nLista removendo o elemento 2(n�mero 41): ");
    imprimir_lista(&L);

    int f;
    printf("\n\nInsira o indice para remover:");
    scanf("%d",&f);
    remover_elemento(&L,f);

    printf("\nLista removendo o elemento %d: ",f);
    imprimir_lista(&L);

    printf("\n\n\n");
}
