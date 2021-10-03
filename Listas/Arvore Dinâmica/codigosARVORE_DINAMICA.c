#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No
{
    int numero;
    struct No *esquerda;
    struct No *direita;
} No;

void inicializaArvore(No **pRaiz)
{
    *pRaiz = NULL;
}

void insercao(No **pRaiz, int numero2)
{
    if (*pRaiz == NULL)
    {
        *pRaiz=(No *)malloc(sizeof (No));
        (*pRaiz)->esquerda=NULL;
        (*pRaiz)->direita=NULL;
        (*pRaiz)->numero=numero2;
    }
    else
    {
        if (numero2 < ((*pRaiz)->numero))
        {
            insercao(&((*pRaiz)->esquerda), numero2);
        }
        else
        {
            insercao(&((*pRaiz)->direita), numero2);
        }
    }
}

No *MaiorDireita(No **no)
{
    if((*no)->direita != NULL)
    {
       return MaiorDireita(&(*no)->direita);
    }
    else
    {
       No *aux = *no;

       if((*no)->esquerda != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
        {
          *no = (*no)->esquerda;
        }
        else
        {
            *no = NULL;
            return aux;
        }
    }

}

No *MenorEsquerda(No **no)
{
    if((*no)->esquerda != NULL)
    {
       return MenorEsquerda(&(*no)->esquerda);
    }
    else
    {
        No *aux = *no;
        if((*no)->direita != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
        {
          *no = (*no)->direita;
        }
        else
        {
          *no = NULL;
        }
        return aux;
    }
}

void remover(No **pRaiz, int numero){
    if(*pRaiz == NULL){   // esta verificacao serve para caso o numero nao exista na arvore.
       printf("Numero nao existe na arvore!");
       getch();
       return;
    }
    if(numero < (*pRaiz)->numero)
       remover(&(*pRaiz)->esquerda, numero);
    else
       if(numero > (*pRaiz)->numero)
          remover(&(*pRaiz)->direita, numero);
       else{    // se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
          No *pAux = *pRaiz;     // quem programar no Embarcadero vai ter que declarar o pAux no inicio do void! :[
          if (((*pRaiz)->esquerda == NULL) && ((*pRaiz)->direita == NULL)){         // se nao houver filhos...
                free(pAux);
                (*pRaiz) = NULL;
               }
          else{     // so tem o filho da direita
             if ((*pRaiz)->esquerda == NULL){
                (*pRaiz) = (*pRaiz)->direita;
                pAux->direita = NULL;
                free(pAux); pAux = NULL;
                }
             else{            //so tem filho da esquerda
                if ((*pRaiz)->direita == NULL){
                    (*pRaiz) = (*pRaiz)->esquerda;
                    pAux->esquerda = NULL;
                    free(pAux); pAux = NULL;
                    }
                else{       //Escolhi fazer o maior filho direito da subarvore esquerda.
                   pAux = MaiorDireita(&(*pRaiz)->esquerda); //se vc quiser usar o Menor da esquerda, so o que mudaria seria isso:
                   pAux->esquerda = (*pRaiz)->esquerda;          //        pAux = MenorEsquerda(&(*pRaiz)->direita);
                   pAux->direita = (*pRaiz)->direita;
                   (*pRaiz)->esquerda = (*pRaiz)->direita = NULL;
                   free((*pRaiz));  *pRaiz = pAux;  pAux = NULL;
                   }
                }
             }
          }
}

void emOrdem(No *pRaiz){
    if(pRaiz != NULL){
        emOrdem(pRaiz->esquerda);
        printf("|%d|", pRaiz->numero);
        emOrdem(pRaiz->direita);
    }
}

void preOrdem(No *pRaiz){
    if(pRaiz != NULL){
        printf("|%d|", pRaiz->numero);
        preOrdem(pRaiz->esquerda);
        preOrdem(pRaiz->direita);
    }
}

void posOrdem(No *pRaiz){
    if(pRaiz != NULL){
        posOrdem(pRaiz->esquerda);
        posOrdem(pRaiz->direita);
        printf("|%d|", pRaiz->numero);
    }
}

int contarNos(No *pRaiz){
   if(pRaiz == NULL)
        return 0;
   else
        return 1 + contarNos(pRaiz->esquerda) + contarNos(pRaiz->direita);
}

int contarFolhas(No *pRaiz){
   if(pRaiz == NULL)
        return 0;
   if(pRaiz->esquerda == NULL && pRaiz->direita == NULL)
        return 1;
   return contarFolhas(pRaiz->esquerda) + contarFolhas(pRaiz->direita);
}

int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}//maior

int altura(No *pRaiz){
   if((pRaiz == NULL) || (pRaiz->esquerda == NULL && pRaiz->direita == NULL))
       return 0;
   else
       return 1 + maior(altura(pRaiz->esquerda), altura(pRaiz->direita));
}

void main()
{

    setlocale(LC_ALL,"");

    No* n;
    inicializaArvore(&n);

    int op,num, retorno;

    do
    {

        printf("\n<Menu>\n");
        printf("\n1-Inserir.");
        printf("\n2-Apresentar em Pós-Ordem.");
        printf("\n3-Apresentar em Ordem.");
        printf("\n4-Apresentar em Pré-Ordem.");
        printf("\n5-Contar Folhas.");
        printf("\n6-Contar Nós.");
        printf("\n7-Altura.");
        printf("\n8-Remover um número.");
        printf("\n0-Encerrar Programa.");
        printf("\n\nSelecione uma das opções:");
        scanf("%d",&op);

        switch(op)
        {

        case 1:
            printf("\nInsira o número que deseja:");
            scanf("%d",&num);
            insercao(&n,num);
            break;
        case 2:
            posOrdem(n);
            break;
        case 3:
            emOrdem(n);
            break;
        case 4:
            preOrdem(n);
            break;
        case 5:
            retorno = contarFolhas(n);
            printf("\nNúmero de folhas: %d\n",retorno);
            break;
        case 6:
            retorno = contarNos(n);
            printf("\nNúmero de Nós: %d\n",retorno);
            break;
        case 7:
            retorno = altura(n);
            printf("\nAltura: %d\n",retorno);
            break;
        case 8:
            printf("\nInsira o número que deseja remover:");
            scanf("%d",&num);
            remover(&n,num);
            emOrdem(n);
            break;
        case 0:
            printf("\nFim do Programa.\n");
            break;
        default:
            printf("\nComando Inválido.\n");
            break;

        }
    }
    while(op!=0);

}
