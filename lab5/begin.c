#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define goldNumber 1.247
#include "func.h"

int main() {


	printf("1. qsort\t1.number\t1.Right\n");
    printf("2.heapSort\t2.lastCall\t2.Left\n");
    printf("3.combSort\t3.FIO\n");

	int sortAl;
	printf("Enter your sort\n");
   	scanf("%d", &sortAl);
    int subsPoint;
    printf("Enter struct's point\n");
    scanf("%d", &subsPoint);
    int direction;
    printf("right or left\n");
    scanf("%d", &direction);



    srand(time(NULL));
    int n;
    printf("Enter the number of repetitions\n");
    scanf("%d", &n);
    int cnt;
    printf("Enter array size\n");
    scanf("%d", &cnt);
    int max;
    printf("Enter max value for lastCall\n");
    scanf("%d", &max);
    int strlength;
    printf("Enter max FIO length\n");
    scanf("%d", &strlength);
    double timeTotal = 0;
    for (int i = 0; i < n; i++) {
        users *arr = arrGenerate(cnt, max, strlength);
        clock_t t = clock();
        switch(sortAl) {
	        case 1:
	            switch(subsPoint) {
	                case 1:
	                    switch(direction) {
	                        case 1:
	                            qsort(arr, cnt, sizeof(users), (int (*)(const void *, const void *))users_cmp_numberRQ);
	                            break;
	                        case 2:
	                            qsort(arr, cnt, sizeof(users), (int (*)(const void *, const void *))users_cmp_numberLQ);
	                            break;
	                    }
	                    break;
	                case 2:
	                    switch(direction) {
	                        case 1:
	                            qsort(arr, cnt, sizeof(users), (int (*)(const void *, const void *))users_cmp_lastCallRQ);
	                            break;
	                        case 2:
	                            qsort(arr, cnt, sizeof(users), (int (*)(const void *, const void *))users_cmp_lastCallLQ);
	                            break;
	                    }
	                    break;
	                case 3:
	                    switch(direction) {
	                        case 1:
	                            qsort(arr, cnt, sizeof(users), (int (*)(const void *, const void *))users_cmp_FIORQ);
	                            break;
	                        case 2:
	                            qsort(arr, cnt, sizeof(users), (int (*)(const void *, const void *))users_cmp_FIOLQ);
	                            break;
	                    }
	                    break;
	            }
	            break;
	        case 2:
	            switch(subsPoint) {
	                case 1:
	                    switch(direction) {
	                        case 1:
	                            heapSort(arr, cnt, users_cmp_numberR);
	                            break;
	                        case 2:
	                            heapSort(arr, cnt, users_cmp_numberL);
	                            break;
	                    }
	                    break;
	                case 2:
	                    switch(direction) {
	                        case 1:
	                            heapSort(arr, cnt, users_cmp_lastCallR);
	                            break;
	                        case 2:
	                            heapSort(arr, cnt, users_cmp_lastCallL);
	                            break;
	                    }
	                    break;
	                case 3:
	                    switch(direction) {
	                        case 1:
	                            heapSort(arr, cnt, users_cmp_FIOR);
	                            break;
	                        case 2:
	                            heapSort(arr, cnt, users_cmp_FIOL);
	                            break;
	                    }
	                    break;
	            }
	            break;
	        case 3:
	            switch(subsPoint) {
	                case 1:
	                    switch(direction) {
	                        case 1:
	                            combSort(arr, cnt, users_cmp_numberR);
	                            break;
	                        case 2:
	                            combSort(arr, cnt, users_cmp_numberL);
	                            break;
	                    }
	                    break;
	                case 2:
	                    switch(direction) {
	                        case 1:
	                            combSort(arr, cnt, users_cmp_lastCallR);
	                            break;
	                        case 2:
	                            combSort(arr, cnt, users_cmp_lastCallL);
	                            break;
	                    }
	                    break;
	                case 3:
	                    switch(direction) {
	                        case 1:
	                            combSort(arr, cnt, users_cmp_FIOR);
	                            break;
	                        case 2:
	                            combSort(arr, cnt, users_cmp_FIOL);
	                            break;
	                    }
	                    break;
	            }
	            break;
        }
        t = clock() - t;
        double time1 = (double)t / CLOCKS_PER_SEC;
        free(arr);
        timeTotal += time1;
    }
    double result = timeTotal / n;
    printf("%lf", result);
    return 0;

}

