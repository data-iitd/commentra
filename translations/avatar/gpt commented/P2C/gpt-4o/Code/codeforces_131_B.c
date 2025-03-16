#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int count;
} Element;

int compare(const void *a, const void *b) {
    return ((Element *)a)->key - ((Element *)b)->key;
}

int main() {
    int n;
    scanf("%d", &n);

    Element *elements = malloc(n * sizeof(Element));
    int unique_count = 0;

    // Read the elements and count their occurrences
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        // Check if the number is already in the elements array
        int found = 0;
        for (int j = 0; j < unique_count; j++) {
            if (elements[j].key == num) {
                elements[j].count++;
                found = 1;
                break;
            }
        }
        
        // If not found, add it to the elements array
        if (!found) {
            elements[unique_count].key = num;
            elements[unique_count].count = 1;
            unique_count++;
        }
    }

    // Sort the elements based on the key
    qsort(elements, unique_count, sizeof(Element), compare);

    // Initialize a counter for pairs that sum to zero
    long long c = 0;

    // Iterate through each unique number in the elements array
    for (int i = 0; i < unique_count; i++) {
        int num = elements[i].key;
        if (num == 0) {
            // For zero, count pairs (count choose 2)
            c += (long long)elements[i].count * (elements[i].count - 1);
        } else {
            // Check if the negative counterpart exists
            for (int j = i + 1; j < unique_count; j++) {
                if (elements[j].key == -num) {
                    c += (long long)elements[i].count * elements[j].count;
                    break;
                }
            }
        }
    }

    // Since each pair is counted twice, divide the total count by 2 before printing
    printf("%lld\n", c / 2);

    // Free allocated memory
    free(elements);
    
    return 0;
}

// <END-OF-CODE>
