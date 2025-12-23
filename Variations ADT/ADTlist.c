// ------------------------
// ARRAYLIST IMPLEMENTATION
// ------------------------
#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} ArrayList;

void insertArrayList(ArrayList *L, int pos, int value) {
    if (L->size >= MAX_SIZE || pos < 0 || pos > L->size) return;
    for (int i = L->size; i > pos; i--)
        L->data[i] = L->data[i-1];
    L->data[pos] = value;
    L->size++;
}

void deleteArrayList(ArrayList *L, int pos) {
    if (pos < 0 || pos >= L->size) return;
    for (int i = pos; i < L->size - 1; i++)
        L->data[i] = L->data[i+1];
    L->size--;
}

int getArrayList(ArrayList L, int pos) {
    if (pos < 0 || pos >= L.size) return -1;
    return L.data[pos];
}

int isArrayListEmpty(ArrayList L) {
    return L.size == 0;
}

int isArrayListFull(ArrayList L) {
    return L.size == MAX_SIZE;
}

// ------------------------
// LINKED LIST IMPLEMENTATION
// ------------------------
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

void insertLinkedList(LinkedList *L, int pos, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (pos == 0) {
        newNode->next = L->head;
        L->head = newNode;
        return;
    }

    Node* temp = L->head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) return;

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteLinkedList(LinkedList *L, int pos) {
    if (L->head == NULL) return;

    if (pos == 0) {
        Node* temp = L->head;
        L->head = L->head->next;
        free(temp);
        return;
    }

    Node* temp = L->head;
    for (int i = 0; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL) return;

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

int getLinkedList(LinkedList L, int pos) {
    Node* temp = L.head;
    for (int i = 0; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) return -1;
    return temp->data;
}

int isLinkedListEmpty(LinkedList L) {
    return L.head == NULL;
}

// Note: Linked list does not have a fixed max size, so no isFull check.
