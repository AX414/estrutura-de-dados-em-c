#include<stdio.h>

#define TAMMAX 10

typedef struct sFila{
    int itens[TAMMAX];
    int inicio,fim;

}Fila;

void inicializa(Fila *f){
f->inicio = TAMMAX -1;
f->fim = TAMMAX -1;
}

int vazia(Fila *f){
    if(f->fim == f->inicio)
        return 1;
    return 0;
}

int cheia(Fila *f){
    if(f->fim == f->inicio)
        return 1;
    return 0;
}

void enfileirar(Fila *f,int x){
    if(f->fim==(TAMMAX-1)){
        f->fim = 0;
    }else{
        (f->fim)++;
    }
    if(cheia(f)){
        printf("\nERRO: fila cheia.\n");
        (f->fim)--;
        if(f->fim==1)
            f->fim = TAMMAX - 1;
        return;
    }
    f->itens[f->fim] = x;
}

int desenfileirar (Fila *f){
    int aux = 0;

    if(!vazia(f)){
        if(f->inicio == TAMMAX-1){
            f->inicio=0;
        }else{
            f->inicio++;
        }
        aux = f->itens[f->inicio];
    }else{
        printf("\nERRO D: fila vazia.\n");
    }
    return (aux);
}

void imprimir(Fila *f){

    int i = (f->inicio + 1) % TAMMAX;
    if(!vazia(f)){
        printf("\nFila: ");
    while(i != ((f->fim + 1)%TAMMAX)){
        printf("| %d | ", f->itens[i]);
        i = (i + 1) % TAMMAX;
    }
}else
    printf("\nFila Vazia");

}

int comprimento (Fila *f){
    int i = (f->inicio+1) %TAMMAX;
    int comp = 0;
    if(!vazia(f)){
        while(i!=((f->fim+1)%TAMMAX)){
            comp++;
            i = (i+1)%TAMMAX;
        }
    } else
    printf("\nFila vazia.");

    return comp;
}

int main(){

    Fila ptrFila;
    inicializa(&ptrFila);
    enfileirar(&ptrFila,16);
    enfileirar(&ptrFila,17);
    enfileirar(&ptrFila,18);
    enfileirar(&ptrFila,19);
    enfileirar(&ptrFila,20);
    enfileirar(&ptrFila,11);
    enfileirar(&ptrFila,12);
    enfileirar(&ptrFila,13);
    enfileirar(&ptrFila,14);
    imprimir(&ptrFila);
    printf("\nComprimento: %d\n\n",comprimento(&ptrFila));

    desenfileirar(&ptrFila);
    imprimir(&ptrFila);
    printf("\nComprimento: %d\n\n",comprimento(&ptrFila));

}
