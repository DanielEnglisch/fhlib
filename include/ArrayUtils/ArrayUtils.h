/*H**********************************************************************
* FILENAME :        ArrayUtils.c
*
* DESCRIPTION :
*       Converts 1D Array into 2D Array +
*       utility functions
*
* NOTES :
*       
*
* 
* AUTHOR :    Andreas Roither        START DATE :    27.10.17
*
* CHANGES :
*
*H*/

#if !defined ArrayUtils_H
#define ArrayUtils_H

#include <stdlib.h>
#include <stdio.h>
int** AllocateMultiarray(unsigned int NumRows);
int** AllocateMultiarrayConvert(unsigned int RowNum, int *arr);
void FreeMultiArray(int **a, unsigned int RowNum);
void PrintMultiArray(int **a, unsigned int NumRows);
void FillMultiArrayRandom(int **a, unsigned int RowNum, int scope);


#endif