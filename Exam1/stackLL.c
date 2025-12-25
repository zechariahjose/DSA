#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int data;
} Element;

typedef struct node {
    Element elem;
    struct node *next;
} *LinkedList;

void init(LinkedList *Stack) {
    *Stack = NULL;
}

void read(LinkedList *Stack) {
    LinkedList temp;
    init(&temp);
    printf("Stack: ");

    if(isEmpty(*Stack)) {
        printf("EMPTY");
    }
    
    while(!isEmpty(*Stack)) {
        Element d = top(*Stack);
        pop(Stack);
        printf("%d ", d.data);
        push(&temp, d.data);
    }

    while(!isEmpty(temp)) {
        Element d = top(temp);
        pop(&temp);
        push(Stack, d.data);
    }

    printf("\n");
}

bool isEmpty(LinkedList Stack) {
    return (Stack == NULL) ? true : false;
}

Element top(LinkedList Stack) {
    Element d = {-1};

    return (isEmpty(Stack)) ? d : Stack->elem;
}

void pop(LinkedList *Stack) {
    if(!isEmpty(*Stack)) {
        LinkedList temp = (*Stack);
        (*Stack) = temp->next;
        free(temp);
    }
}

void push(LinkedList *Stack, int data) {
    LinkedList temp = (LinkedList)malloc(sizeof(struct node));
    if(temp != NULL) {
        temp->elem.data = data;
        temp->next = *Stack;
        (*Stack) = temp;
    }
}

void freeAll(LinkedList Stack) {
    LinkedList temp;

    while(Stack != NULL) {
        temp = Stack;
        Stack = Stack->next;
        free(temp);
    }
}

int main() {
    LinkedList Stack;

    printf("\033[H\033[J"); // clear screen
    
    init(&Stack);
    read(&Stack);

    push(&Stack, 1);
    read(&Stack);

    push(&Stack, 2);
    push(&Stack, 3);
    read(&Stack);

    Element temp = top(Stack);
    printf("Top: %d\n", temp.data);

    pop(&Stack);
    read(&Stack);

    freeAll(Stack);

    return 0;
}

