#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef
    struct sll {
    int data;
    struct sll *next;
} node;

node* newNode(int element) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = element;
    temp->next = NULL;
    return temp;
}

typedef 
    struct {
        node *first;
        node *last;
    } List;

bool isEmpty(List *L) {
    return L->first == NULL;
}

int atFirst(List *L) {
    return L->first->data;
}

int atLast(List *L) {
    return L->last->data;
}

int onTop(List *L) {
    return atFirst(L);
}

void display(List *L) {

    if (L->first == NULL) {
        printf("List empty\n");
    } else {
        for (node *f = L->first; f != NULL; f = f->next) {
            printf("%d ->", f->data);
        }
        printf("\n");
    }
}

node *findNode(List *L, int e) {

    for (node *f = L->first; f != NULL; f = f->next) {
        if (f->data == e) {
            return f;
        }
    }
    return NULL;
}

void insertBegin(List *L, int element) {
    node *temp = newNode(element);

    if (L->first == NULL) {
        L->first = L->last = temp;
    } else {
        temp->next = L->first;
        L->first = temp;
    }
}

void insertEnd(List *L, int element) {
    node *temp = newNode(element);

    if (L->last == NULL) {
        L->first = L->last = temp;
    } else {
        L->last->next = temp;
        L->last = temp;
    }
}

bool insertAfter(List *L, int after_element, int element) {
    node *current = findNode(L, after_element);

    if (current == NULL) {
        return false;
    } else if (current == L->last) {
        insertEnd(L, element);
        return true;
    } else {
        node *temp;
        temp = newNode(element);
        temp->next = current->next;
        current->next = temp;
        return true;
    }
}

bool deleteBegin(List *L) {

    if (L->first == NULL) {
        return false;
    } else {
        node *temp = L->first;
        L->first = temp->next;
        free(temp);
        if (L->first == NULL) {
            L->last = NULL;
        }
        return true;
    }
}

bool deleteAfter(List *L, int after_element) {
    node *current = findNode(L, after_element);

    if (current == NULL || current->next == NULL) {
        return false;
    } else {
        node *temp = current->next;
        current->next = temp->next;
        free(temp);
        if (current -> next == NULL) {
            L->last = current;
        }
        return true;
    }
}

bool deleteEnd(List *L) {

    if (L->last == NULL) {
        return false;
    } else if (L->last == L->first) {
        free(L->first);
        L->first = L->last = NULL;
        return true;
    } else {
        node *f = L->first;
        while (f->next != L->last) {
            f = f->next;
        }
        deleteAfter(L, f->data);
        return true;
    }
}

int main() {
    List L1 = {NULL,NULL};

    insertEnd(&L1, 30);
    insertBegin(&L1, 10);
    insertAfter(&L1, 30, 40);
    insertAfter(&L1, 10, 20);
    insertEnd(&L1, 50);
    insertBegin(&L1, 5);
    display(&L1);

    deleteEnd(&L1);
    deleteBegin(&L1);
    deleteAfter(&L1, 30);
    deleteAfter(&L1, 10);
    deleteAfter(&L1, 30);
    display(&L1);
    return 0;
}
