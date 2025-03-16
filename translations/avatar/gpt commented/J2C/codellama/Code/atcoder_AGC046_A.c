#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 

// Structure to store a linked list node 
struct Node { 
    int data; 
    struct Node* next; 
}; 

// Function to create a new node 
struct Node* newNode(int data) 
{ 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = data; 
    temp->next = NULL; 
    return temp; 
} 

// Function to insert a node at the beginning of a linked list 
void push(struct Node** head_ref, int data) 
{ 
    struct Node* new_node = newNode(data); 
    new_node->next = *head_ref; 
    *head_ref = new_node; 
} 

// Function to print a linked list 
void printList(struct Node* head) 
{ 
    while (head != NULL) { 
        printf("%d ", head->data); 
        head = head->next; 
    } 
    printf("\n"); 
} 

// Function to rotate a linked list by k nodes 
void rotate(struct Node** head_ref, int k) 
{ 
    // If list is empty or k is 0, nothing to do 
    if (*head_ref == NULL || k == 0) 
        return; 
  
    // Get the length of the linked list 
    int len = 0; 
    struct Node* current = *head_ref; 
    while (current != NULL) { 
        len++; 
        current = current->next; 
    } 
  
    // If k is greater than the length of the linked list, 
    // then k = k % len 
    k = k % len; 
  
    // If k is 0, nothing to do 
    if (k == 0) 
        return; 
  
    // Find the new head of the list 
    current = *head_ref; 
    for (int i = 0; i < len - k; i++) 
        current = current->next; 
  
    // Change the head of the list 
    *head_ref = current->next; 
    current->next = NULL; 
} 

// Driver program to test above functions 
int main() 
{ 
    // Start with the empty list 
    struct Node* head = NULL; 
  
    // Insert 10 nodes 
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 3); 
    push(&head, 4); 
    push(&head, 5); 
    push(&head, 6); 
    push(&head, 7); 
    push(&head, 8); 
    push(&head, 9); 
    push(&head, 10); 
  
    // Print the original list 
    printf("Original Linked List: "); 
    printList(head); 
  
    // Rotate the list by 2 
    rotate(&head, 2); 
  
    // Print the rotated list 
    printf("Rotated Linked List: "); 
    printList(head); 
  
    return 0; 
} 

