#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define sep " "

typedef struct myList {
    	char symbol;
        struct myList *next;
} Lst;

bool emptyList(Lst *list) {
    if (list == NULL) {
        return true;
    } else {
        return false;
    }
}

void printList(Lst *list) {
    for (Lst *p = list; p != NULL; p = p->next) {
        printf("%c", p->symbol);
    }
    printf("\n");
}

Lst *createItem(char symbol) {
    Lst *item = (Lst*)malloc(sizeof(Lst));
    item->symbol = symbol;
    item->next = NULL;
    return item;
}

void deleteList(Lst *list) {
    if (!list) return;
    Lst* t = list, *next;
    while (t) {
        next = t->next;
        free(t);
        t = next;
    }
}

void pushFront(Lst **list, char symbol) {
    Lst *newItem = createItem(symbol);
    newItem->next = *list;
    *list = newItem;
}
void pushBack(Lst **list, char symbol) {
    Lst *newItem = createItem(symbol);
    Lst *ptr = *list;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newItem;
}

char popList(Lst **list) {
    if (!*list) return 0;
    Lst *p = *list;
    char result = p->symbol;
    *list = p->next;
    free(p);
    return result;
}

int removeList(Lst* a) {     // удаляет элемент, следующий за данным
    if (!a) return 1;
    Lst* temp = a->next;
    if (!temp) return 1;
    a->next = temp->next;
    free(temp);
    return 0;
}

Lst *getList() {        // string by list
    char ch = getchar();
    if (ch == EOF) {
        return NULL;
    }
    if (ch == '\n') {
        return createItem('\n');
    }
    Lst *list = createItem(ch);
    Lst *head = list;
    while ((ch = getchar()) != '\n') {
        list->next = createItem(ch);
        list = list->next;
    }
    return head;
}

void procedure(Lst **list) {

    while ((*list) && ((*list)->symbol == ' ' || (*list)->symbol == '\t')) {
        popList(list);
    }
    if (!(*list)) return;

    Lst *p = *list;
    while (p->next) {
        if (p->symbol == '\t') {
            p->symbol = ' ';
        }
        if (p->symbol == ' ' && (p->next->symbol == ' ' || p->next->symbol == '\t')) {
            removeList(p);
        } else {
            p = p->next;
        }
    }
    if (p->symbol == ' ') {
        Lst *l = *list;
        while (l->next != p) {
            l = l->next;
        }
        removeList(l);
    }

    p = *list;
    while (p) {
        char first  = p->symbol;
        while (p->next) {
            if (p->next->symbol == ' ') break;
            if (p->next->symbol == first) {
                removeList(p);
            } else {
                p = p->next;
            }
        }
        if (p) {
            p = p->next;
        }
        if (p) {
            p = p->next;
        }
    }
}
