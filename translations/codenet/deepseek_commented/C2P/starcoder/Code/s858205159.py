#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define nil 0  # Sentinel node (dummy node) for the doubly linked list

#define NodePointer NodePointer  # Type alias for a pointer to a node

#define listSearch(key) listSearch(key)  # Function to search for a node with a given key

#define init() init()  # Function to initialize the doubly linked list with a sentinel node

#define printList() printList()  # Function to print the entire list starting from the first node

#define deleteNode(t) deleteNode(t)  # Function to delete a specified node from the list

#define deleteFirst() deleteFirst()  # Function to delete the first node in the list

#define deleteLast() deleteLast()  # Function to delete the last node in the list

#define deleteKey(key) deleteKey(key)  # Function to delete the node with a specified key

#define insert(key) insert(key)  # Function to insert a new node with a specified key at the beginning of the list

#define main() int main(){int key, n, i;int size = 0;  # Variable to keep track of the size of the list
char com[20];  # Array to store the command
int np = 0, nd = 0;  # Counters for insertions and deletions
scanf("%d", &n);  # Read the number of commands
init();  # Initialize the list
for (i = 0; i < n; i++){
scanf("%s%d", com, &key);  # Read the command and the key
if (com[0] == 'i') { insert(key); np++; size++; }  # Insert a new node if the command is 'i'
else if (com[0] == 'd') {
if (strlen(com) > 6){  # Check if the command is to delete the first or last node
if (com[6] == 'F') deleteFirst();
else if (com[6] == 'L') deleteLast();
}
else {
deleteKey(key); nd++;  # Delete the node with the specified key
}
size--;  # Decrease the size of the list
}
}

printList();  # Print the final state of the list
return 0;  # Return 0 to indicate successful execution
}
