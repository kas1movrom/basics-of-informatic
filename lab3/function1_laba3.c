#include <stdio.h>
#include <stdlib.h>

void check_index_delete(int *index, int cnt)
{
    while((scanf("%d", index) != 1) || (*index < 0) || (*index >= cnt))
    {
        scanf("%*c");
        printf("Ошибка, Введите целое число большее или равное нулю, не большее, чем количство элементов в массиве!\n");
    }
}

void check_index(int *index)
{
    while ((scanf("%d", index) != 1) || (*index < 0))
    {
        scanf("%*c");
        printf("Ошибка, Введите целое число большее или равное нулю!\n");
    }
}

void check_case_key_direction(int *key)
{
    while ((scanf("%d", key) != 1) || (*key <= 0) || (*key > 2))
    {
        scanf("%*c");
        printf("Ошибка, Введите одно из предложенных чисел!\n");
    }
}

void check_cnt(int *value)
{
    while ((scanf("%d", value) != 1) || (*value <= 0))
    {
        scanf("%*c");
        printf("Ошибка, Введите целое, положительно число!\n");
    }
}

void check_value_array(double *value)
{
    while ((scanf("%lf", value) != 1))
    {
        scanf("%*c");
        printf("Ошибка, Введите вещественное число, обязательно через запятую!\n");
    }
}
