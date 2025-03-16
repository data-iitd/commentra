#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long *data;
    int size;
    int capacity;
} HashSet;

void initHashSet(HashSet *set, int capacity) {
    set->data = (long *)malloc(capacity * sizeof(long));
    set->size = 0;
    set->capacity = capacity;
}

int contains(HashSet *set, long value) {
    for (int i = 0; i < set->size; i++) {
        if (set->data[i] == value) {
            return 1; // Found
        }
    }
    return 0; // Not found
}

void add(HashSet *set, long value) {
    if (!contains(set, value)) {
        if (set->size >= set->capacity) {
            set->capacity *= 2;
            set->data = (long *)realloc(set->data, set->capacity * sizeof(long));
        }
        set->data[set->size++] = value;
    }
}

int compare(const void *a, const void *b) {
    return (*(long *)a - *(long *)b);
}

int main() {
    // Create a HashSet to store unique elements that meet the criteria
    HashSet set;
    initHashSet(&set, 10); // Initial capacity of 10

    // Read the number of elements in the array
    int n;
    scanf("%d", &n);

    // Read the value of k
    long k;
    scanf("%ld", &k);

    // Initialize an array to hold the input numbers
    long *arr = (long *)malloc(n * sizeof(long));

    // Read n long integers into the array
    for (int i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }

    // Sort the array to facilitate the processing of elements
    qsort(arr, n, sizeof(long), compare);

    // Initialize a counter to keep track of valid elements
    int count = 0;

    // Iterate through the sorted array to apply the conditions
    for (int i = 0; i < n; i++) {
        // Check if the current element is not divisible by k
        if (arr[i] % k != 0) {
            count++; // Increment count for valid element
            add(&set, arr[i]); // Add the element to the set
        }
        // Check if the current element is divisible by k and its corresponding k-factor is not in the set
        else if (!contains(&set, arr[i] / k)) {
            count++; // Increment count for valid element
            add(&set, arr[i]); // Add the element to the set
        }
    }

    // Output the final count of valid elements
    printf("%d\n", count);

    // Free allocated memory
    free(arr);
    free(set.data);

    return 0;
}

// <END-OF-CODE>
