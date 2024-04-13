#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

typedef struct myList Lst;
void printList(Lst *list);
Lst *createItem(char symbol);
void deleteList(Lst *list);
void pushFront(Lst **list, char symbol);
void puchBack(Lst **list, char symbol);
char popList(Lst **list);
int removeList(Lst *a);
Lst *getList();
void procedure(Lst **list);

#endif
