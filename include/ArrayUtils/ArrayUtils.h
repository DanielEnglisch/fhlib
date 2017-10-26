#if !defined ARRAYUTILS_H
#define      ARRAYUTILS_H

int** AllocateMultiarray(unsigned int NumRows);
int** AllocateMultiarrayConvert(unsigned int RowNum, int *arr);
void PrintMultiArray(int **a, int NumRows);
void FillMultiArrayRandom(int **a, int RowNum, int scope);

#endif