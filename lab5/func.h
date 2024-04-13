#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED


char *enterString(FILE *filename);
struct subscriber {
    char* number;
    int lastCall;
    char* FIO;
};
typedef struct subscriber users;
typedef int (*operation)(users, users);
users* arrGenerate(int cnt, int max, int strlength);
void swap(users* a, users* b);
int users_cmp_lastCallR(users man1, users man2);
int users_cmp_lastCallL(users man1, users man2);
int users_cmp_numberR(users man1, users man2);
int users_cmp_numberL(users man1, users man2);
int users_cmp_FIOR(users man1, users man2);
int users_cmp_FIOL(users man1, users man2);
int users_cmp_FIOLQ(const users *p1, const users *p2);
int users_cmp_FIORQ(const users *p1, const users *p2);
int users_cmp_numberLQ(const users *p1, const users *p2);
int users_cmp_numberRQ(const users *p1, const users *p2);
int users_cmp_lastCallLQ(const users *p1, const users *p2);
int users_cmp_lastCallRQ(const users *p1, const users *p2);
void combSort(users* arr, int cnt, operation func);
void siftDown(users* arr, int root, int branches, operation func);
void heapSort(users* arr, int cnt, operation func);
users makeStruct(char *line, users object);
void deleteInArr(users *arr, int i, int *cnt);

#endif
