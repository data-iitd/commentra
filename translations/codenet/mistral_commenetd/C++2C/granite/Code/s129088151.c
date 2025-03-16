

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// Define a structure to represent a node in the hash table
typedef struct Node {
	char* key; // Key of the node
	bool value; // Value of the node
	struct Node* next; // Pointer to the next node in the hash table
} Node;

// Function to calculate the hash value of a string
int hash(char* str) {
	int hashValue = 0;
	for (int i = 0; str[i]!= '\0'; i++) {
		hashValue = (hashValue * 31 + (int)str[i]) % 1000; // Calculate the hash value using a simple hash function
	}
	return hashValue;
}

// Function to insert a key-value pair into the hash table
void insert(char* key, bool value) {
	int hashValue = hash(key); // Calculate the hash value of the key
	Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for a new node
	newNode->key = strdup(key); // Duplicate the key string
	newNode->value = value; // Set the value of the node
	newNode->next = NULL; // Set the next pointer of the node to NULL
	// Insert the new node into the hash table
	if (T[hashValue] == NULL) {
		T[hashValue] = newNode; // If the bucket is empty, insert the new node
	}
	else {
		Node* temp = T[hashValue]; // Otherwise, traverse the bucket to find the appropriate position for insertion
		while (temp->next!= NULL) {
			temp = temp->next;
		}
		temp->next = newNode; // Insert the new node at the end of the bucket
	}
}

// Function to search for a key in the hash table
bool search(char* key) {
	int hashValue = hash(key); // Calculate the hash value of the key
	Node* temp = T[hashValue]; // Traverse the bucket to find the node with the matching key
	while (temp!= NULL) {
		if (strcmp(temp->key, key) == 0) { // If a matching key is found, return true
			return true;
		}
		temp = temp->next; // Otherwise, move to the next node in the bucket
	}
	return false; // If no matching key is found, return false
}

int main() {
	// Read the number of input pairs from the standard input
	int n;
	scanf("%d", &n);

	// Initialize the hash table
	for (int i = 0; i < 1000; i++) {
		T[i] = NULL; // Set all buckets in the hash table to NULL
	}

	// Iterate through each input pair
	for (int i = 0; i < n; i++) {
		char com[13]; // Command string
		char str[10]; // String to be inserted or searched
		scanf("%s%s", com, str); // Read the command and the string from the standard input

		// If the command is 'i', insert the string into the hash table
		if (com[0] == 'i') {
			insert(str, true); // Insert the string into the hash table with a value of true
		}
		// If the command is not 'i', search for the string in the hash table and print the result accordingly
		else {
			if (search(str)) { // If the string is found in the hash table
				printf("yes\n"); // Print 'yes'
			}
			else {
				printf("no\n"); // If the string is not found in the hash table, print 'no'
			}
		}
	}
	// Return 0 to indicate successful execution of the program
	return 0;
}

