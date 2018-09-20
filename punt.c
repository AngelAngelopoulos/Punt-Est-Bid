/*
 * Fecha: 30/Agosto/2018
 *
 * Autor: Luis Angel Alvarado
 *
 * VersiÛn: 1.0a
 *
 * Descripcion de la aplicaciÛn: Arreglos Bidimensionales mediante apuntadores dobles enlazados
 *
 * Fecha de Revision:
 *
 * Encargado de revisiÛn: Miguel Angel
 *
 * Materia: Estructuras de Datos II
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pideNum(void);
int asignaMem(int ***ptrArr, int n, int m);
void capturaDato(int **ptrArr, int n, int m);
void muestraDato(int **ptrArr, int n, int m, int sumatot, int promed);
void liberaMem(int **ptrArr, int n, int m);
int sumaDatos(int **ptrArr, int n, int m);
int promedioDatos(int n, int m, int sumatot);

int main()
{
    int **ptrArr, rest, ren, col, sumas, proms;
    ren = pideNum();
    col = pideNum();
    rest = asignaMem(&ptrArr, ren, col);
    
    if (rest == 1)
    {
        capturaDato(ptrArr, ren, col);
        sumas = sumaDatos(ptrArr, ren, col);
        proms = promedioDatos(ren, col, sumas);
        muestraDato(ptrArr, ren, col, sumas, proms);
        liberaMem(ptrArr, ren, col);
    }
    else
        printf("Lo siento, no hay memoria\n");
}

int pideNum()
{
    int n;
    printf("Escriba el numero de renglones/filas: \n");
    scanf("%d", &n);
    return(n);
}

int asignaMem(int ***ptrArr, int n, int m)
{
    int res = 0, i;
    
    *ptrArr = (int**)malloc(sizeof(int*)*n);
    
    if (*ptrArr != NULL)
    {
        res = 1;
        
        for (i = 0; i < m && res == 1; i++)
        {
            *(*ptrArr+i) = (int*)malloc(sizeof(int));
            
            if (*(*ptrArr) == NULL)
            {
                while (--i > 0)
                {
                    free(*(*ptrArr+i));
                }
                free(*ptrArr);
                res = 0;
            }
        }
    }
    return(res);
}

void capturaDato(int **ptrArr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            printf("Dame el dato no [%d][%d] => \n", i, j);
            scanf("%d", (*(ptrArr+i)+j));
        }
    }
    printf("\n\n");
}

void muestraDato(int **ptrArr, int n, int m, int sumatot, int promed)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            printf("El dato no [%d][%d] es => %d \n", i, j, *(*(ptrArr+i)+j));
        }
    }
    printf("La suma total de los datos es => %d\n", sumatot);
    printf("El promedio es => %d\n", promed);
}

void liberaMem(int **ptrArr, int n, int m)
{
    free(*ptrArr);
}

int sumaDatos(int **ptrArr, int n, int m)
{
    int suma = 0, i;
    for (i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; j++) {
             suma = *(*(ptrArr+i)+j) + suma;
        }
    }
    return(suma);
}

int promedioDatos(int n, int m, int sumatot)
{
    return(sumatot/n);
}
