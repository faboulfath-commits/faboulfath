#include <stdio.h>
#include "recursion.h"

// Function to calculate the factorial of a number recursively
int factorial(int n) {
    if (n < 0) {
        return -1; // Error case for negative numbers
    }
    if (n == 0) {
        return 1; // Base case
    }
    return n * factorial(n - 1); // Recursive case
}

// Function to calculate the nth Fibonacci number recursively
int fibonacci(int n) {
    if (n < 0) {
        return -1; // Error case for negative numbers
    }
    if (n == 0) {
        return 0; // Base case
    }
    if (n == 1) {
        return 1; // Base case
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

// Function to traverse a linked list recursively
void traverseLinkedList(Node* head) {
    if (head == NULL) {
        return; // Base case
    }
    // Process the current node (e.g., print data)
    printf("%d ", head->data);
    // Recursive call for the next node
    traverseLinkedList(head->next);
}