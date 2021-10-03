#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{

    setlocale(LC_ALL,"");

    int *array;
    array = malloc(10 * sizeof(int));
    if(array == NULL)
    {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }
    array[9] = 404;
    printf("\nImprime Array:");

    for(int i=0; i<10; i++)
    {
        if(array[i]!=404)
        {
            //imprime 0 caso não tenha nada
            //alocado igual ao valor 404
            array[i] = 0;
        }
        printf("\nArray[%d] = %d",i,array[i]);
    }

    free(array);
}
