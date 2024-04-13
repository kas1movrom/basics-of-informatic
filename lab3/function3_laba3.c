#include <stdio.h>
#include <stdlib.h>
#include "function1_laba3.h"

void add1_element_series(int *cnt, double **arr, int amount)
{
    int index;
    double value;
    for (int i = 0; i < amount; i++)
    {
        printf("Введите индекс:\n");
        check_index(&index);

        printf("Введите значение обязательно через запятую\n");
        check_value_array(&value);

        arr[0] = (double*)realloc(arr[0], sizeof(double) * (*cnt + 1));
        if (index >= *cnt)
        {
            arr[0][*cnt] = value;
        }
        else
        {
            for (int i = *cnt; i > index; i--)
            {
                arr[0][i] = arr[0][i - 1];
            }
            arr[0][index] = value;
        }
        *cnt = *cnt + 1;
    }
}

void add1_element(int index, int *cnt, double **arr, double value)
{
    arr[0] = (double*)realloc(arr[0], sizeof(double) * (*cnt + 1));
    if (index >= *cnt)
    {
        arr[0][*cnt] = value;
    }
    else
    {
        for (int i = *cnt; i > index; i--)
        {
            arr[0][i] = arr[0][i - 1];
        }
        arr[0][index] = value;
    }
    *cnt = *cnt + 1;
}

void delete1_element(double **arr, int index2, int *cnt)
{
    for (int i = index2; i < (*cnt) - 1; i++)
    {
        arr[0][i] = arr[0][i + 1];
    }
    *cnt = *cnt - 1;
    arr[0] = (double*)realloc(arr[0], sizeof(double) * (*cnt));
}

double *scan1_array(int cnt)
{
    double *arr = (double*)malloc(sizeof(double) * cnt);
    for (int i = 0; i < cnt; i++)
    {
        check_value_array(arr + i);
    }
    return arr;
}
