#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h> // For INT_MIN error handling

typedef struct Node { 
    int data; 
    struct Node* next; 
} Node;

typedef struct Stack { 
    Node* top; 
} Stack;

// Initializes an empty stack
Stack* createStack() { 
    Stack* stack = (Stack*)malloc(sizeof(Stack)); 
    if (!stack) return NULL; 
    stack->top = NULL; 
    return stack; 
}   

// Returns true if stack has no elements
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Returns the top element without removing it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty (Peek ignored)\n");
        return INT_MIN; 
    }
    return stack->top->data;
}

// Pushes a new value onto the stack
void push(Stack* stack, int data) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    if (!newNode) {
        printf("Heap Overflow: Failed to push %d\n", data);
        return;
    }
    newNode->data = data; 
    newNode->next = stack->top; 
    stack->top = newNode; 
}

// Removes and returns the top value
int pop(Stack* stack) { 
    if (isEmpty(stack)) { 
        printf("Stack Underflow\n"); 
        return INT_MIN; 
    } 
    Node* temp = stack->top; 
    int poppedData = temp->data;
    stack->top = stack->top->next; 
    free(temp); 
    return poppedData;
}

void printStack(Stack* stack) { 
    Node* current = stack->top; 
    while (current != NULL) { 
        printf("%d -> ", current->data); 
        current = current->next; 
    } 
    printf("NULL\n"); 
}

void freeStack(Stack* stack) { 
    while (!isEmpty(stack)) { 
        pop(stack); 
    } 
    free(stack); 
}   

int main(void) { 
    Stack* stk = createStack(); 
    
    push(stk, 3);
    push(stk, 9);
    push(stk, 2); 
    push(stk, 5);
    push(stk, 1);
    
    printf("Current Top: %d\n", peek(stk)); 
    printStack(stk); 
    
    printf("Popped: %d\n", pop(stk));      
    printf("New Top: %d\n", peek(stk));    
    
    printStack(stk);
    freeStack(stk); 
    return 0; 
}
