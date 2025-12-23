void swap(int *A, int *B){
    int temp = *A;
    *A = *B;
    *B = temp;
}

void bubbleSortLinkedList(Node* head){
    Node *trav1;
    Node *trav2;
    int sw;
    for(trav1 = head; trav1 != NULL; trav1 = trav1->next){
        sw = 0;
        for(trav2 = head; trav2->next != NULL; trav2 = trav2->next){
            if(trav2->data > trav2->next->data){
                swap(&trav2->data, &trav2->next->data);
                sw = 1;
            }
        }
        if(!sw){
            break;
        }
        
    }
    
    
}