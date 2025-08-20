#include <stdio.h>

#define max 10

typedef struct {
    int elem[max];
    int count;
}List;


List insertPos (List L, int data, int position){
    
    // if(position < 0 || position > L.count){
    //     printf("Invalid position");
    //     return L;
    // }
    
    L.elem[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position){

    for (int i = position; i < L.count - 1; i++) {
        L.elem[i] = L.elem[i + 1];
    }

    L.count--;
    return L;
}


int locate (List L, int data){
    int pos;
    
    for(int i = 0; i<L.count; i++){
        if(L.elem[i] == data){
            pos = i;
        }
    }

    return pos;
}


List insertSorted(List L, int data){
    


    return L;
}


void display(List L){
    printf("List:\n");

    for(int i = 0; i<L.count; i++){
        printf("%d\n", L.elem[i]);
    }
}

int main(){
    List L;
    L.count = 0;


    L = insertPos(L, 90, 0);
    L = insertPos(L, 20, 1);
    L = insertPos(L, 60, 2);
    L = insertPos(L, 10, 3);
    L = insertPos(L, 50, 4);
    L = deletePos(L, 1);
    int loc = locate(L, 10);
    display(L);


    printf("\n\nData at position %d\n", loc);

    return 0;
}