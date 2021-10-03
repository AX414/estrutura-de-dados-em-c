/*
Exercício 2:  Desenvolva um programa em Linguagem C que permita ao usuário inserir e remover 
elementos nos extremos de uma sequência de itens, ou seja, no início e no final de uma 
lista linear estática.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct contato
{

    char nomeContato[50];
    char nr_UM[30];
    char nr_DOIS[30];
    char nome_Ringtone[50];

} CONTATO;

typedef struct cell
{
    CONTATO c; //conteúdo da célula
    struct cell *next; //endereço da próxima célula
} CELULA;

CELULA *init(CELULA *lista)
{
    //inicializa o ponteiro externo à lista com o valor NULL
    lista = NULL;
    return lista;
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

CELULA *insere_inicio(CELULA *lista, CONTATO contato)
{

    CELULA *q;

    q = getnode();
    if(q!=NULL)
    {
        q->c = contato;
        q->next = lista;
        lista = q;
        return lista;
    }
    else
    {
        printf("\nERRO na alocação do nó.\n");
        return NULL;
    }

}

CELULA *insere_fim(CELULA *lista, CONTATO contato)
{

    CELULA *q;
    CELULA *aux;

    q = getnode();
    if(q!=NULL)
    {
        q->c = contato;
        q->next = NULL;

        if(empty(lista))
        {
            lista = q;
        }
        else
        {
            aux = lista;
            while(aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = q;
        }
        return lista;
    } //fim do if (q!=NULL)
    else
    {
        printf("\nERRO na alocação do nó.\n");
        return NULL;

    }

}

CELULA *remove_inicio(CELULA *lista)
{

    CELULA *q;

    q = lista;
    if(!empty(lista))  // há itens na lista
    {
        lista = q->next;
        freenode(q);
        return lista;
    }
    else
    {
        printf("\nERRO: lista vazia.");
        return NULL;
    }

}

CELULA *pesquisa (CELULA *lista,char nome[50])
{

    CELULA *q;

    if(!empty(lista))
    {
        q = lista;
        while(q!=NULL)
        {
            if(q->c.nomeContato == nome)
            {
                return q; // encontrou o nó
            }
            q = q-> next; //avança para o próximo
        }
    }
    return NULL; // caso não encontre
}

CELULA *remove_valor(CELULA *lista, CONTATO contato)
{

    CELULA *q, *aux;

    if((q=pesquisa(lista,contato.nomeContato)) != NULL)
    {
        aux = lista;
        if(aux == q)  //nó está no inicio da lista
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
        return lista; //removeu
    }
    return NULL; //não removeu
}


void exibe_lista(CELULA *lista)
{

    CELULA *aux;
    aux = lista;
    printf("\nLista de Contatos: ");
    if(aux == NULL)
    {
        printf("\nLista vazia.");
    }
    while(aux != NULL)
    {
        printf("\n|Nome: %s - Número1: %s - Número2: %s - Ringtone: %s| ",
               aux->c.nomeContato,aux->c.nr_UM,aux->c.nr_DOIS,aux->c.nome_Ringtone);
        aux = aux ->next;
    }
    printf("\n\n");
}

CONTATO lerDados(CELULA *lista)
{

    CONTATO c;

    char nome[50],nrUM[30],nrDOIS[30],ringtone[50];

    printf("\nInsira o nome do contato: ");
    scanf("%s",&nome);
    strcpy(c.nomeContato,nome);
    fflush(stdin);
    printf("\nInsira o primeiro número do contato: ");
    scanf("%s",&nrUM);
    strcpy(c.nr_UM,nrUM);
    printf("\nInsira o número alternativo: ");
    scanf("%s",&nrDOIS);
    strcpy(c.nr_DOIS,nrDOIS);
    printf("\nEscreva o nome da música que deseja como ringtone: ");
    scanf("%s",&ringtone);
    strcpy(c.nome_Ringtone,ringtone);

    printf("\n\n");

    return c;
}

CONTATO lerContato(CELULA *lista)
{

    CONTATO c;

    char nome[50];

    printf("\nInsira o nome do contato a ser excluido: ");
    scanf("%s",&nome);
    strcpy(c.nomeContato,nome);
    fflush(stdin);

    printf("\n\n");

    return c;
}

void main()
{

    setlocale(LC_ALL,"");

    CELULA *ptrlista;
    ptrlista = init(ptrlista);
    CONTATO c;

    int op;

    do
    {
        printf("<MENU>");
        printf("\n1-Inserir um Contato.");
        printf("\n2-Remover um Contato.");
        printf("\n3-Listar todos os Contatos.");
        printf("\n4-Pesquisar Contato.");
        printf("\n0-Sair da aba de Contatos.");

        printf("\n\nSelecione uma das Opções: ");
        scanf("%d",&op);

        switch(op)
        {
        case 1:
            c = lerDados(ptrlista);
            ptrlista = insere_inicio(ptrlista,c);
            break;
        case 2:
            c = lerContato(ptrlista);
            ptrlista = remove_valor(ptrlista,c);
            break;
        case 3:
            exibe_lista(ptrlista);
            break;
        case 4:
            break;
        case 0:
            printf("\nO usuário saiu da aba de Contatos.\n\n\n");
            break;
        }
    }
    while(op!=0);
}
