#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_N 1000000
#define MOD 1000000007

typedef struct {
    int val;
    int freq;
} Element;

typedef struct {
    Element *arr;
    int size;
    int capacity;
} Array;

typedef struct {
    Array *arr;
    int size;
    int capacity;
} HashMap;

// Function to create a new Array
Array *newArray() {
    Array *arr = (Array *) malloc(sizeof(Array));
    arr->arr = (Element *) malloc(sizeof(Element) * 10);
    arr->size = 0;
    arr->capacity = 10;
    return arr;
}

// Function to create a new HashMap
HashMap *newHashMap() {
    HashMap *map = (HashMap *) malloc(sizeof(HashMap));
    map->arr = (Array **) malloc(sizeof(Array *) * 10);
    map->size = 0;
    map->capacity = 10;
    for (int i = 0; i < 10; i++) {
        map->arr[i] = newArray();
    }
    return map;
}

// Function to add an element to the Array
void addElement(Array *arr, int val) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->arr = (Element *) realloc(arr->arr, sizeof(Element) * arr->capacity);
    }
    arr->arr[arr->size].val = val;
    arr->arr[arr->size].freq = 1;
    arr->size++;
}

// Function to add an element to the HashMap
void addElementToHashMap(HashMap *map, int val) {
    int index = val % map->capacity;
    addElement(map->arr[index], val);
}

// Function to get the frequency of an element in the HashMap
int getFrequency(HashMap *map, int val) {
    int index = val % map->capacity;
    for (int i = 0; i < map->arr[index]->size; i++) {
        if (map->arr[index]->arr[i].val == val) {
            return map->arr[index]->arr[i].freq;
        }
    }
    return 0;
}

// Function to add an element to the HashMap
void addElementToHashMap(HashMap *map, int val) {
    int index = val % map->capacity;
    addElement(map->arr[index], val);
}

// Function to get the frequency of an element in the HashMap
int getFrequency(HashMap *map, int val) {
    int index = val % map->capacity;
    for (int i = 0; i < map->arr[index]->size; i++) {
        if (map->arr[index]->arr[i].val == val) {
            return map->arr[index]->arr[i].freq;
        }
    }
    return 0;
}

// Function to solve the problem
void solve(int testNumber, FILE *inputFile, FILE *outputFile) {
    // Read the number of elements and the modulo value
    int n = fscanf(inputFile, "%d %d", &n, &m);
    
    // Read the array of elements
    int *a = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &a[i]);
    }
    
    // HashMap to store the frequency of remainders
    HashMap *dp = newHashMap();
    
    // Initialize the answer and base variable
    long ans = 0;
    int base = 0;
    
    // Iterate through the array to calculate the answer
    for (int i = 0; i < n; i++) {
        // Update the base variable
        base = (base - a[i] % m + m) % m;
        
        // Update the frequency of remainders in the HashMap
        addElementToHashMap(dp, (base + a[i]) % m);
        
        // Add the frequency of the current remainder to the answer
        ans += getFrequency(dp, base);
    }
    
    // Print the final answer
    fprintf(outputFile, "%ld\n", ans);
}

// Driver Code
int main() {
    FILE *inputFile = fopen("D-large.in", "r");
    FILE *outputFile = fopen("D-large.out", "w");
    int tests;
    fscanf(inputFile, "%d", &tests);
    for (int i = 1; i <= tests; i++) {
        solve(i, inputFile, outputFile);
    }
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}

