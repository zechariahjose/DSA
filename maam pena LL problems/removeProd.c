#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct node {
    char name[24];
    struct node* next;
}*LL;
 
void removeProductFromCart(LL *List, char name[]);
void insertLast(LL *List, char name[]);
 
void insertLast(LL *List, char name[]){
	LL *trav;
	for(trav = List ; *trav != NULL ; trav = &(*trav)->next){}
	LL temp = (LL)malloc(sizeof(struct node));
	if(temp != NULL){
	    strcpy(temp->name, name);
		temp->next = NULL;
		*trav = temp;
	}
}
 
void removeProductFromCart(LL *List, char name[]){
    LL* trav;
    for(trav = List ; *trav != NULL && strcmp((*trav)->name, name) != 0 ; trav = &(*trav)->next){}
    if(*trav != NULL){
        LL temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}
int main(){
    LL head = NULL;
    insertLast(&head, "Banana");
    insertLast(&head, "Orange");
    insertLast(&head, "Apple");
 
    printf("Before:\n");
    LL temp = head;
    while(temp != NULL){
        printf("%s->", temp->name);
        temp = temp->next;
    }
    printf("NULL");
 
    removeProductFromCart(&head, "Orange");
    printf("\nAfter:\n");
    while(head != NULL){
        printf("%s->", head->name);
        head = head->next;
    }
    printf("NULL");
}
