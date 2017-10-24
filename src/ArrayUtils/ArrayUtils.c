#include "ArrayUtils.h"
#include <stdlib.h>
#include <stdio.h>

int** AllocateMultiarray(unsigned int RowNum)
{
    int **a = malloc(sizeof *a * RowNum);

    if (a)
    {
        for (unsigned int i = 0; i < RowNum; i++)
        {
            a[i] = malloc(sizeof(*a[i]) * RowNum);
        }

        for (unsigned int i = 0; i < RowNum; i++)
        {
            for (unsigned int j = 0; j < RowNum; j++)
            {
                a[i][j] = 0;
            }
        }
    }

    return a;
}

int** AllocateMultiarrayConvert(unsigned int RowNum, int *arr)
{
    int **a = malloc(sizeof *a * RowNum);
    int count = 0;

    if (a)
    {
        for (unsigned int i = 0; i < RowNum; i++)
        {
            a[i] = malloc(sizeof(*a[i]) * RowNum);
        }

        for (unsigned int i = 0; i < RowNum; i++)
        {
            for (unsigned int j = 0; j < RowNum; j++)
            {
                a[i][j] = arr[count];
                count++;
            }
        }
    }

    return a;
}

void FillMultiArrayRandom(int **a, int RowNum, int scope)
{
    for (int i = 0; i < RowNum; i++)
    {
        for (int j = 0; j < RowNum; j++)
        {
            a[i][j] = rand() % scope;
        }
    }
}

void PrintMultiArray(int **a, int RowNum)
{
    for (int i = 0; i < RowNum; i++)
    {
        for (int j = 0; j < RowNum; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}