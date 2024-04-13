#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define goldNumber 1.247
#define separator "|" 
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

    users *subs = (users*)malloc(sizeof(users));
    char *line = (char*)malloc(sizeof(char));
    int cnt = 0;
    users *subsArr = (users*)malloc(sizeof(users));

    

    FILE *filename;
    filename = fopen("002.txt", "r");

    do {
    
    	line = enterString(filename);
    	*subs = makeStruct(line, *subs);
		subsArr = (users*)realloc(subsArr, sizeof(users) * (cnt + 1));
		subsArr[cnt] = *subs;
		cnt++;

    	
    } while (line);
    fclose(filename);
    
    const int amount = cnt;
    cnt /= 2;
    users *arr = (users*)malloc(sizeof(users) * cnt);
    for (int j = 0; j < amount; j++) {
    	if (j % 2 != 0) {
    		arr[j / 2].FIO = subsArr[j].FIO;
    		arr[j / 2].number = subsArr[j].number;
    		arr[j / 2].lastCall = subsArr[j].lastCall;
    	}
    }

	for (int i = 0; i < cnt; i++) {
		if (strlen(arr[i].number) > 16) {			
			deleteInArr(arr, i, &cnt);
			arr = (users*)realloc(arr, sizeof(users) * cnt);
			i--;
		} else {
			int errorCnt = 0;
			int plusCnt = 0;
			for (int j = 0; j < (int)strlen(arr[i].number); j++) {
				if (((int)arr[i].number[j] != 43) && ((int)arr[i].number[j] != 32) && (((int)arr[i].number[j] < 48) || ((int)arr[i].number[j] > 57))) {
					errorCnt++;
				} 
				if ((int)arr[i].number[j] == 43) {
					plusCnt++;
				}
			}
			if ((errorCnt > 0) || (plusCnt > 1)) {
				deleteInArr(arr, i, &cnt);
				arr = (users*)realloc(arr, sizeof(users) * cnt);
				i--;
			}
		}
	}


	for (int i = 0; i < cnt; i++) {
		if (arr[i].lastCall == 0) {
			for (int j = i; j < cnt - 1; j++) {
				arr[j].FIO = arr[j + 1].FIO;
				arr[j].number = arr[j + 1].number;
				arr[j].lastCall = arr[j + 1].lastCall;
			}
			cnt--;
			arr = (users*)realloc(arr, sizeof(users) * cnt);
			i--;
		}
		
	}

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
    
	if (cnt < amount) {
		printf("\tWARNING\nsome lines were not written to the 001.txt!");
	}
	
    FILE *fileout;
    fileout = fopen("001.txt", "w");
    for (int j = 0; j < cnt; j++) {
    	fprintf(fileout, "%d. %s\n%s\n%d\n", j + 1, arr[j].FIO, arr[j].number, arr[j].lastCall);
    }
    fclose(fileout);
    free(subsArr);
    free(arr);
    
    return 0;
    

    
}
