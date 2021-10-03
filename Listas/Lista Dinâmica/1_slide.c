#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct sProduto
{
    int codigo;
    char nome[50];
    int qtd;
    float preco;
};

void inserirProduto(int tamanho,struct sProduto *produto)
{
    for(int i=0; i<tamanho; i++)
    {
        printf("\n|Produto %d|---------->",i+1);
        fflush(stdin);
        printf("\nInsira o nome: ");
        gets(produto[i].nome);
        printf("\nInsira o codigo: ");
        scanf("%d",&produto[i].codigo);
        printf("\nInsira o quantidade: ");
        scanf("%d",&produto[i].qtd);
        printf("\nInsira o preço: ");
        scanf("%f",&produto[i].preco);
    }
}

void retornaMaiorPreco(int tamanho,struct sProduto *produto)
{

    int i;
    float precoMaior = 0;
    int codigo = -1;

    for(i=0; i<tamanho; i++)
    {
        if(precoMaior<produto[i].preco)
        {
            precoMaior = produto[i].preco;
            codigo = produto[i].codigo;
        }
    }

    printf("\nO Produto de código %d é quem possui o maior preço, tendo o valor de R$%.2f",codigo, precoMaior);
    printf("\n");
}

void retornaMaiorQtd(int tamanho,struct sProduto *produto)
{

    int i;
    int qtd = 0;
    int codigo = -1;

    for(i=0; i<tamanho; i++)
    {
        if(qtd<produto[i].qtd)
        {
            qtd = produto[i].qtd;
            codigo = produto[i].codigo;
        }
    }

    printf("\nO Produto de código %d é quem possui o maior quantia em estoque, tendo atualmente %d em estoque.",codigo, qtd);
    printf("\n");
}

void main()
{

    setlocale(LC_ALL,"");
    struct sProduto *produto;

    int op,tamanho,qtd;

    do
    {
        printf("\n<Menu>\n1-Definir tamanho da memória que será alocada\n2-Inserir a quantidade de produtos que definiu na memoria.\n3-Apresenta Produto de maior valor.\n4-Apresenta Produto com maior quantia em estoque.\n0-Encerrar Programa\n\nSelecione uma Opção: ");
        scanf("%d",&op);

        switch(op)
        {
        case 1:
            printf("\nDefina o tamanho a ser alocado: ");
            scanf("%d",&tamanho);
            produto = malloc (tamanho * sizeof(struct sProduto));
            break;
        case 2:
            inserirProduto(tamanho,produto);
            printf("---------------------->");
            break;
        case 3:
            retornaMaiorPreco(tamanho,produto);
            break;
        case 4:
            retornaMaiorQtd(tamanho,produto);
            break;
        case 0:
            printf("\n\nEncerrando Programa.");
            break;
        }
    }
    while(op!=0);


}
