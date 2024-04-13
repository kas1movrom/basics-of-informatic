#include <stdio.h>
#include <stdlib.h>

void continue_work()
{
    printf("1. Продолжить работу\n");
    printf("2. Выйти в главное меню\n");
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
