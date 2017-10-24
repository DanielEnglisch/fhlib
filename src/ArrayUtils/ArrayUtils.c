#include "ArrayUtils.h"
#include <stdlib.h>
#include <stdio.h>

// allocate mulit array with 0 as default value
int** AllocateMultiarray(unsigned int RowNum)
{
    int **a = malloc(sizeof(*a) * RowNum);

    if (a)
    {
        for (unsigned int i = 0; i < RowNum; i++)
        {
            a[i] = malloc(sizeof(*(a[i])) * RowNum);
        }

        for (unsigned int i = 0; i < RowNum; i++)
        {
            for (unsigned int j = 0; j < RowNum; j++)
            {
                a[i][j] = 0;
            }
        }
    }
    else
    {
        printf("\n-ERROR-\nAllocateMultiArray: Failed to allocate ressources");
    }

    return a;
}

// allocate multi array from existing one dimensional array
int** AllocateMultiarrayConvert(unsigned int RowNum, int arr[])
{
    // only for static Arrays, not dynamic ones
    int length = sizeof(arr[0]);
    int count = 0;
    int **a = malloc(sizeof(*a) * RowNum);

    if (a)
    {
        for (unsigned int i = 0; i < RowNum; i++)
        {
            a[i] = malloc(sizeof(*(a[i])) * RowNum);
        }

        for (unsigned int i = 0; i < RowNum; i++)
        {
            for (unsigned int j = 0; j < RowNum; j++)
            {
                if (count < length)
                {
                    a[i][j] = arr[count];
                    count++;
                }
                else
                {
                    a[i][j] = arr[count];
                }
            }
        }
    }
    else
    {
        printf("\n-ERROR-\nAllocateMultiArrayConvert: Failed to allocate ressources");
    }

    return a;
}

// Free the allocated multi array
void FreeMultiArray(int **a, unsigned int RowNum)
{
    for (int i = 0; i < RowNum; i++)
    {
        free(a[i]);
    }
    free(a);
}

// fill the multi array with random numbers below the scope
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

// print the multi array to the console
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