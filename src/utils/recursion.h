#ifndef RECURSION_H
#define RECURSION_H

// Structure for linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to calculate the factorial of a number
int factorial(int n);

// Function to calculate the nth Fibonacci number
int fibonacci(int n);

// Function to traverse a linked list recursively
void traverseLinkedList(Node* head);

#endif // RECURSION_H