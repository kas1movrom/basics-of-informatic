#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "function1_laba3.h"
#include "function2_laba3.h"
#include "function3_laba3.h"

/*void check_index_delete(int *index, int cnt);
void add1_element_series(int *cnt, double **arr, int amount);
void array_processing(int i, double *arr, double *drobnaya_chast, double *double_celaya_chast);
void check_value_array(double *value);
void check_index(int *index);
void check_case_key_direction(int *key);
 void check_cnt(int *value);
double *scan1_array(int cnt);
void delete1_element(double **arr, int index2, int *cnt);
void add1_element(int index, int *cnt, double **arr, double value);
void print_menu();
void continue_work();
void print_array(double *arr, int cnt);*/

int main()
{
    setlocale(LC_ALL, "Russian");

    int direction;
    int direction2;
    int case_direction1 = 2;
    int case_direction21 = 2;
    int case_direction22 = 2;
    int case_direction3 = 2;
    int index_delete;
    int index_add;
    double value_add;
    double *arr = NULL;
    int CNT = 0;

    do {
        print_menu();
        while ((scanf("%d", &direction) != 1) || (direction <= 0) || (direction > 6))
        {
            scanf("%*c");
            printf("Введите одно из предложенных чисел!\n");
        }
        for(int i =0; i < 200; i++)
        {
            printf("\n");
        }
        switch(direction)
        {
            case 1:

                do
                {

                    free(arr);

                    printf("Для начала инициализации введите количество членов массива:\n");
                    check_cnt(&CNT);
                    
                    printf("Пожалуйста, для корректной работы программы вводите числа.\n");
                    printf("Числа обязательно должны быть введены через запятую, а не через точку!\n");
                    printf("Каждое с новой строки\n");
                    printf("Подряд введите элементв массива\n");
                    arr = scan1_array(CNT);

                    printf("Массив инициализирован\n");
                    continue_work();
                    check_case_key_direction(&case_direction1);
                    printf("\n\n");

                    system("cls");

                } while (case_direction1 != 2);
                break;

            case 2:

                printf("1. Добавить сразу несколько элементов\n");
                printf("2. Добавить один элемент\n");

                while ((scanf("%d", &direction2) != 1) || (direction2 <= 0) || (direction > 2))
                {
                    scanf("%*c");
                    printf("Введите одно из предложенных чисел!\n");
                }

                switch(direction2)
                {
                    case 1:

                        do
                        {

                            printf("Для добавления нескольких элементов вводите подряд их индекс и значение\n");

                            int amount;
                            printf("Введите количество элементов, которое вы хотите добавить\n");
                            check_cnt(&amount);
                            add1_element_series(&CNT, &arr, amount);

                            printf("Элементы добавлены\n");
                            continue_work();
                            check_case_key_direction(&case_direction21);
                            printf("\n\n");

                            system("cls");

                        } while (case_direction21 != 2);

                        break;

                    case 2:

                        do
                        {

                            printf("Для добавления одного элемента введите его индекс, а также значение\n");

                            printf("Индекс:\n");
                            check_index(&index_add);

                            printf("Значение:\n");
                            check_value_array(&value_add);

                            add1_element(index_add, &CNT, &arr, value_add);
                            //add1_element(index_add, &CNT, &arr, value_add);

                            printf("Элемент добавлен\n");
                            continue_work();
                            check_case_key_direction(&case_direction22);
                            printf("\n\n");

                            system("cls");

                        } while (case_direction22 != 2);

                        break;

                }

                break;

            case 3:

                do
                {
                    if (CNT == 0)
                    {
                        printf("Массив пуст! Для удаления элементов заполните его!\n");
                        case_direction3 = 2;
                    }
                    else
                    {
                        printf("Для удаления элемента введите его индекс:\n");
                        check_index_delete(&index_delete, CNT);

                        delete1_element(&arr, index_delete, &CNT);

                        printf("Элемент удален\n");
                        continue_work();
                        check_case_key_direction(&case_direction3);
                        printf("\n\n");

                        system("cls");
                    }

                } while (case_direction3 != 2);
                break;

            case 4:

                    if (CNT == 0)
                    {
                        printf("Массив пуст! Для обработки элементов заполните его!\n");
                    }
                    else
                    {
                        int amount = 0;
                        double drbn_chst;
                        double dbl_cl_chst;
                        for (int i = 0; i < CNT; i++)
                        {
                            array_processing(i, arr, &drbn_chst, &dbl_cl_chst);
                            if (drbn_chst > dbl_cl_chst)
                            {
                                amount++;
                            }
                        }
                        double *arr1 = NULL;
                        arr1 = (double*)malloc(sizeof(double) * amount);
                        int amount1 = 0;
                        for (int i = 0; i < CNT; i++)
                        {
                            array_processing(i, arr, &drbn_chst, &dbl_cl_chst);
                            if (drbn_chst > dbl_cl_chst)
                            {
                                arr1[amount1] = arr[i];
                                amount1++;
                            }
                        }
                        CNT = amount1;
                        free(arr);
                        arr = arr1;
                        printf("Массив обработан!\n");
                    }

                break;

            case 5:
                if (CNT == 0)
                {
                    printf("Массив пуст! Для вывода сначала заполните его!\n");
                }
                else
                {
                   print_array(arr, CNT);
                }
                break;

        }
    } while (direction != 6);
    free(arr);
    return 0;
}

/*void check_value_array(double *value)
{
    while ((scanf("%lf", value) != 1))
    {
        scanf("%*c");
        printf("Ошибка, Введите вещественное число, обязательно через запятую!\n");
    }
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

void delete1_element(double **arr, int index2, int *cnt)
{
    for (int i = index2; i < (*cnt) - 1; i++)
    {
        arr[0][i] = arr[0][i + 1];
    }
    *cnt = *cnt - 1;
    arr[0] = (double*)realloc(arr[0], sizeof(double) * (*cnt));
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

void array_processing(int i, double *arr, double *drobnaya_chast, double *double_celaya_chast)
{
    double arri = arr[i];
    if (arri < 0)
    {
        arri *= (-1);
    }
    int celaya_chast = (int)arri;
    *double_celaya_chast = celaya_chast;
    *drobnaya_chast = arr[i] - celaya_chast;
    *double_celaya_chast /= 1000;
}

void print_array(double *arr, int cnt)
{
    printf("Количество элементов: %d\n", cnt);
    printf("Элементы: \n");

    for (int i = 0; i < cnt; i++)
    {
        printf("%lg ", arr[i]);
    }
    printf("\n");
}

void add1_element_series(int *cnt, double **arr, int amount)
{
    int index;
    double value;
    for (int i = 0; i < amount; i++)
    {
        printf("Введите индекс:\n");
        check_index(&index);

        printf("Введите значение вида nnn,mmm  nn,mmm  n,mmm обязательно через запятую!\n");
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

void print_menu()
{
    printf("1. Инициализация массива\n");
    printf("2. Вставка элемента в массива\n");
    printf("3. Удаление элемента из массива\n");
    printf("4. Обработка данных по условию\n");
    printf("5. Вывести состояние массива\n");
    printf("6. Заврешить работу программы\n\n\n");
}

void continue_work()
{
    printf("1. Продолжить работу\n");
    printf("2. Выйти в главное меню\n");
}

void check_cnt(int *value)
{
    while ((scanf("%d", value) != 1) || (*value <= 0))
    {
        scanf("%*c");
        printf("Ошибка, Введите целое, положительно число!\n");
        printf("(При вводе дробного числа считывается его целая часть)\n");
    }
}

void check_case_key_direction(int *key)
{
    while ((scanf("%d", key) != 1) || (*key <= 0) || (*key > 2))
    {
        scanf("%*c");
        printf("Ошибка, Введите одно из предложенных чисел!\n");
        printf("(При вводе дробного числа считывается его целая часть)\n");
    }
}

void check_index(int *index)
{
    while ((scanf("%d", index) != 1) || (*index < 0))
    {
        scanf("%*c");
        printf("Ошибка, Введите целое число большее или равное нулю!\n");
        printf("(При вводе дробного числа считывается его целая часть)\n");
    }
}

void check_index_delete(int *index, int cnt)
{
    while((scanf("%d", index) != 1) || (*index < 0) || (*index >= cnt))
    {
        scanf("%*c");
        printf("Ошибка, Введите целое число большее или равное нулю, не большее, чем количство элементов в массиве!\n");
        printf("(При вводе дробного числа считывается его целая часть)\n");
    }
}*/

