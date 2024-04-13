#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define goldNumber 1.247
#define separator "|"

struct subscriber {
    char* number;
    int lastCall;
    char* FIO;
};

typedef struct subscriber users;
typedef int (*operation)(users, users);

users* arrGenerate(int cnt, int max, int strlength) {
    users *arr = (users*)malloc(sizeof(users) * cnt);
    for (int i = 0; i < cnt; i++) {
        arr[i].lastCall = (rand() % max);
        arr[i].FIO = (char*)malloc(sizeof(char) * (strlength + 1));
        for (int j = 0; j < strlength; j++) {
            arr[i].FIO[j] = (char)(rand() % 26) + 'a';
        }
        arr[i].FIO[strlength] = '\0';
        arr[i].number = (char*)malloc(sizeof(char) * 18);
        for (int j = 0; j < 17; j++) {
            arr[i].number[j] = (char)(rand() % 9) + '0';
        }
        arr[i].number[17] = '\0';
    }
    return arr;
}

char *enterString(FILE *filename) {
    int result;
    int len = 0;
    char *ptr = (char*)malloc(sizeof(char));
    *ptr = '\0';
    char buf[81] = { 0 };
    int length;
    int chunkLen;
    result = fscanf(filename, "%80[^\n]", buf);
    if (result < 0) {
        free(ptr);
        return NULL;
    } else {
        if (result == 0) {
            fscanf(filename, "%*c");
        } else {
            chunkLen = strlen(buf);
            length = len + chunkLen;
            ptr = (char*)realloc(ptr, sizeof(char) * (length + 1));
            memcpy((ptr + len), buf, chunkLen);
            len = length;
        }
    }
    if (len > 0) {
        ptr[len] = '\0';
    } else {
        ptr = (char*)calloc(1, sizeof(char));
    }
    return ptr;
}

void swap(users* a, users* b) {
    users prm = *b;
    *b = *a;
    *a = prm;
}

int users_cmp_lastCallR(users man1, users man2) {
    return man1.lastCall - man2.lastCall;
}

int users_cmp_lastCallL(users man1, users man2) {
    return man2.lastCall - man1.lastCall;
}

int users_cmp_numberR(users man1, users man2) {
    return strcmp(man1.number, man2.number);
}

int users_cmp_numberL(users man1, users man2) {
    return strcmp(man2.number, man1.number);
}

int users_cmp_FIOR(users man1, users man2) {
    return strcmp(man1.FIO, man2.FIO);
}

int users_cmp_FIOL(users man1, users man2) {
    return strcmp(man2.FIO, man1.FIO);
}

int users_cmp_FIOLQ(const users *p1, const users *p2) {
    return strcmp(p1->FIO, p2->FIO);
}

int users_cmp_FIORQ(const users *p1, const users *p2) {
    return strcmp(p2->FIO, p1->FIO);
}

int users_cmp_numberLQ(const users *p1, const users *p2) {
    return strcmp(p1->number, p2->number);
}

int users_cmp_numberRQ(const users *p1, const users *p2) {
    return strcmp(p2->number, p1->number);
}

int users_cmp_lastCallLQ(const users *p1, const users *p2) {
    return (p1->lastCall - p2->lastCall);
}

int users_cmp_lastCallRQ(const users *p1, const users *p2) {
    return (p2->lastCall - p1->lastCall);
}

void combSort(users *arr, int cnt, operation func) {
	if (!arr || cnt < 1) {
		return;
	} 
	int span = cnt / goldNumber;
	users buff;
	while (span > 0) {
		for (int i = 0; i + span < cnt; i++) {
			if (func(arr[i + span], arr[i]) > 0) {
				buff = arr[i + span];
				arr[i + span] = arr[i];
				arr[i] = buff;
			}
		}
		span /= goldNumber;
	}
}


void heap_sort(users *arr, int cnt, operation func) {
	
}


void siftDown(users* arr, int root, int branches, operation func) {
    int maxBranch;
    char flagDone = 1;
    while ((root * 2 <= branches) && (flagDone)) {
        if (root * 2 == branches) {
            maxBranch = root * 2;
        }
        else if (func(arr[root * 2], arr[root * 2 + 1]) > 0) {
            maxBranch = root * 2;
        }
        else {
            maxBranch = root * 2 + 1;
        }
        if (func(arr[root], arr[maxBranch]) < 0) {
            swap((arr + root), (arr + maxBranch));
            root = maxBranch;
        }
        else {
            flagDone = 0;
        }
    }
}

void heapSort(users* arr, int cnt, operation func) {
    int i = cnt / 2;
    while (i >= 0) {
    	siftDown(arr, i, cnt - 1, func);
    	i--;
    }
    i = cnt - 1;
    char a = 1;
    while (a) {
    	swap((arr + 0), (arr + i));
    	siftDown(arr, 0, i - 1, func);
    	i--;
    	if (i < 1) {
    		break;
    	}
    }
}

users makeStruct(char *line, users object) {
        int cnt = 0;
        char *portion = strtok(line, separator);
        while (portion != NULL) {
                if (cnt == 0) {
                        object.FIO = portion;
                }
                if (cnt == 1) {
                        object.number = portion;
                }
                if (cnt == 2) {
                        int errorsCnt = 0;
                        for (int i = 0; i < (int)strlen(portion); i++) {
                                if (((int)portion[i] < 48) || ((int)portion[i] > 57)) {
                                        errorsCnt++;
                                }
                        }
                        if (errorsCnt > 0) {
                                object.lastCall = 0;
                        } else {
                                object.lastCall = atoi(portion);
                        }
                }
                cnt++;
                portion = strtok(NULL, separator);
        }
        return object;
}

void deleteInArr(users *arr, int i, int *cnt) {
        for (int j = i; j < *cnt - 1; j++) {
                arr[j].FIO = arr[j + 1].FIO;
                arr[j].number = arr[j + 1].number;
                arr[j].lastCall = arr[j + 1].lastCall;
        }
        *cnt = *cnt - 1;
}
