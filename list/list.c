#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node { 
    int data; 
    struct Node* next; 
} Node;

typedef struct List { 
    Node* head; 
    Node* tail; // FIXED: Changed 'strct' to 'struct'
} List;

// Initializes an empty List
List* createList() { 
    List* list = (List*)malloc(sizeof(List)); 
    if (!list) return NULL; 
    list->head = NULL; 
    list->tail = NULL; // FIXED: Explicitly initialize tail
    return list; 
}   

bool isEmpty(List* list) {
    return list->head == NULL;
}

// FIXED: Updates tail if it's the first element added
void cons(List* list, int data) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    if (!newNode) {
        printf("Heap Overflow\n");
        return;
    }
    newNode->data = data; 
    newNode->next = list->head; 
    
    if (isEmpty(list)) {
        list->tail = newNode; // Tail points to first node added
    }
    list->head = newNode; 
}

int removeByValue(List* list, int data) { 
    if (isEmpty(list)) { 
        printf("List Underflow\n"); 
        return INT_MIN; 
    } 

    Node* current = list->head; 
    Node* prev = NULL; 

    while (current != NULL) {
        if (current->data == data) {
            // Case 1: Removing the Head
            if (prev == NULL) {
                list->head = current->next;
                // If it was the only node, update tail
                if (list->head == NULL) {
                    list->tail = NULL;
                }
            } 
            // Case 2: Removing Middle or Tail
            else {
                prev->next = current->next;
                // If we removed the tail, update the tail pointer
                if (current->next == NULL) {
                    list->tail = prev;
                }
            }

            int foundData = current->data;
            free(current);
            return foundData; // Exit after first match
        }
        
        // Move pointers forward
        prev = current;
        current = current->next;
    }

    //printf("Value %d not found in list.\n", data);
    return INT_MIN; 
}


void printList(List* list) { 
    Node* current = list->head; 
    while (current != NULL) { 
        printf("%d -> ", current->data); 
        current = current->next; 
    } 
    printf("\n"); 
}

void freeList(List* list) { 
    if (list == NULL) return;

    Node* current = list->head;
    Node* nextNode;

    while (current != NULL) { 
        // 1. Save the next node's address
        nextNode = current->next; 
        
        // 2. Safely free the current node
        free(current); 
        
        // 3. Move to the next node
        current = nextNode; 
    } 

    // 4. Finally, free the list container itself
    free(list); 
}
 

int main(void) { 
    List* Lst = createList();
    if (Lst == NULL) {
        printf("Failed to create list\n");
        return 1;
    }
    
    cons(Lst, 3);
    cons(Lst, 8);
    cons(Lst, 2); 
    cons(Lst, 4);
    cons(Lst, 9);
    cons(Lst, 12); 
    
    printList(Lst); 
    removeByValue(Lst, 9); 
    printList(Lst);
    
    freeList(Lst); 
    return 0; 
}
