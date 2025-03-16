
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Create a struct to store the integers
struct ArrayList {
    int *arr;
    int size;
    int capacity;
};

// Create a function to initialize an ArrayList
struct ArrayList *initArrayList(int capacity) {
    struct ArrayList *a = malloc(sizeof(struct ArrayList));
    a->arr = malloc(capacity * sizeof(int));
    a->size = 0;
    a->capacity = capacity;
    return a;
}

// Create a function to add an integer to the ArrayList
void add(struct ArrayList *a, int x) {
    if (a->size == a->capacity) {
        a->capacity *= 2;
        a->arr = realloc(a->arr, a->capacity * sizeof(int));
    }
    a->arr[a->size++] = x;
}

// Create a function to sort the ArrayList in ascending order
void sort(struct ArrayList *a) {
    for (int i = 0; i < a->size - 1; i++) {
        for (int j = i + 1; j < a->size; j++) {
            if (a->arr[i] > a->arr[j]) {
                int temp = a->arr[i];
                a->arr[i] = a->arr[j];
                a->arr[j] = temp;
            }
        }
    }
}

// Create a function to apply the logic to the ArrayList
struct ArrayList *func(struct ArrayList *a) {
    struct ArrayList *b = initArrayList(a->capacity);
    int min = 0;

    // Iterate through the ArrayList and apply the logic to each integer
    for (int i = 0; i < a->size; i++) {
        if (a->arr[i] == 0) { // If the current integer is 0, remove it and decrease the index of the for loop
            a->size--;
            i--;
        } else {
            if (min != 0) { // If there is already a minimum value, apply the modulo operation and check if the result is 1
                a->arr[i] = a->arr[i] % min;
                if (a->arr[i] == 1) { // If the result is 1, print 1 and exit the program
                    printf("1\n");
                    exit(0);
                }
            } else { // If there is no minimum value yet, assign the current integer as the minimum value
                min = a->arr[i];
            }
        }
    }

    // Sort the ArrayList in ascending order and return it
    sort(a);
    return a;
}

// Create a function to read the input from the console
void readInput(struct ArrayList *a) {
    int n;
    scanf("%d", &n);

    // Check if the input is 1, if so, print the only integer and exit the program
    if (n == 1) {
        int x;
        scanf("%d", &x);
        printf("%d\n", x);
        exit(0);
    }

    // Read the rest of the integers and add them to the ArrayList
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        add(a, x);
    }
}

// Create a function to print the answer
void printAnswer(struct ArrayList *a) {
    int ans = 0;

    // Use a while loop to keep applying the function to the ArrayList until it contains only one element
    while (true) {
        if (a->size == 1) {
            ans = a->arr[0]; // Assign the only remaining integer to the answer variable
            break; // Exit the loop
        }
        a = func(a); // Apply the function to the ArrayList and assign the result back to it
    }

    // Print the answer
    printf("%d\n", ans);
}

// Create a function to free the memory allocated by the ArrayList
void freeArrayList(struct ArrayList *a) {
    free(a->arr);
    free(a);
}

int main() {
    struct ArrayList *a = initArrayList(1);
    readInput(a);
    printAnswer(a);
    freeArrayList(a);
    return 0;
}

