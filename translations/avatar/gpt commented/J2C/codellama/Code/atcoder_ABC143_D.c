#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Structure to store the list of integers
struct List { 
    int *arr; 
    int size; 
    int capacity; 
}; 

// Function to create a new list
struct List* createList(int capacity) { 
    struct List *list = (struct List*)malloc(sizeof(struct List)); 
    list->arr = (int*)malloc(capacity * sizeof(int)); 
    list->size = 0; 
    list->capacity = capacity; 
    return list; 
} 

// Function to add an element to the list
void add(struct List *list, int element) { 
    if (list->size == list->capacity) { 
        list->capacity *= 2; 
        list->arr = (int*)realloc(list->arr, list->capacity * sizeof(int)); 
    } 
    list->arr[list->size++] = element; 
} 

// Function to sort the list
void sort(struct List *list) { 
    int i, j, temp; 
    for (i = 0; i < list->size - 1; i++) { 
        for (j = i + 1; j < list->size; j++) { 
            if (list->arr[i] > list->arr[j]) { 
                temp = list->arr[i]; 
                list->arr[i] = list->arr[j]; 
                list->arr[j] = temp; 
            } 
        } 
    } 
} 

// Function to find the count of integers in the list that can form a valid triplet
int find(struct List *list, int from, int target) { 
    int low = from; 
    int upp = list->size - 1; 
    int mid = (upp - low + 1) % 2 == 0 ? (low + upp) / 2 + 1 : (low + upp) / 2; 
    if (upp - low < 0) { 
        return 0; 
    } else if (list->arr[from] >= target) { 
        return 0; 
    } else if (list->arr[upp] < target) { 
        return upp - low + 1; 
    } 
    while (upp - low > 1) { 
        if (list->arr[mid] >= target) { 
            upp = mid; 
        } else { 
            low = mid; 
        } 
        mid = (upp - low + 1) % 2 == 0 ? (low + upp) / 2 + 1 : (low + upp) / 2; 
    } 
    return low - from + 1; 
} 

// Main function
int main() { 
    // Create a scanner object to read input from the console
    int N; 
    scanf("%d", &N); 
    
    // Initialize a list to store the integers
    struct List *L = createList(N); 
    
    // Read N integers from input and add them to the list
    for (int i = 0; i < N; i++) { 
        int element; 
        scanf("%d", &element); 
        add(L, element); 
    } 
    
    // Sort the list of integers in ascending order
    sort(L); 
    
    // Initialize a counter to keep track of valid pairs
    int count = 0; 
    
    // Iterate through each pair of integers in the sorted list
    for (int i = 0; i < N; i++) { 
        for (int j = i + 1; j < N; j++) { 
            // Get the current pair of integers
            int a = L->arr[i]; 
            int b = L->arr[j]; 
            
            // Find the number of integers that can form a valid triplet with a and b
            int res = find(L, j + 1, a + b); 
            
            // Increment the count by the number of valid triplets found
            count = count + res; 
        } 
    } 
    
    // Output the total count of valid triplets
    printf("%d\n", count); 
    return 0; 
} 

