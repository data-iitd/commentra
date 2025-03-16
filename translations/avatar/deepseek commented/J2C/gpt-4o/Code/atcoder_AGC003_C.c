#include <stdio.h>
#include <stdlib.h>

#define NUM (int)(1e5 + 2)

typedef struct {
    int value;
    int index;
} Element;

int compare(const void *a, const void *b) {
    return ((Element *)a)->value - ((Element *)b)->value;
}

int main() {
    // Initialize variables
    int N;
    scanf("%d", &N);

    // Initialize an array to store elements and their indices
    Element *elements = (Element *)malloc(N * sizeof(Element));

    // Read each number and store it along with its index
    for (int i = 0; i < N; i++) {
        scanf("%d", &elements[i].value);
        elements[i].index = i;
    }

    // Sort the elements based on their values
    qsort(elements, N, sizeof(Element), compare);

    // Initialize variables to keep track of the current index and the count of differences
    int bin = 0;
    int diff = 0;

    // Loop through the sorted elements
    for (int i = 0; i < N; i++) {
        int idx = elements[i].index;

        // If the current index is not even when bin is even (or vice versa), increment the diff counter
        if ((bin % 2) != (idx % 2)) {
            diff++;
        }

        // Update bin and take modulo 2 to keep it within 0 or 1
        bin++;
        bin %= 2;
    }

    // Calculate the answer by dividing diff by 2
    int ans = diff / 2;

    // Print the result
    printf("%d\n", ans);

    // Free allocated memory
    free(elements);

    return 0;
}

// <END-OF-CODE>
