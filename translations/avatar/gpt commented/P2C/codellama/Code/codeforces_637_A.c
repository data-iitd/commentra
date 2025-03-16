#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the count of each element
typedef struct {
    int count;
    char element;
} element_count;

// Function to sort the array of element_count structures
int compare(const void *a, const void *b) {
    element_count *ia = (element_count *)a;
    element_count *ib = (element_count *)b;
    return ia->count - ib->count;
}

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Read the input string, remove the last character (newline), and split it into a list
    char s[100000];
    scanf("%[^\n]%*c", s);
    char *token = strtok(s, " ");
    char *tokens[100000];
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }

    // Count the occurrences of each element in the list
    element_count w[100000];
    for (int i = 0; i < n; i++) {
        w[i].element = tokens[i][0];
        w[i].count = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (w[i].element == w[j].element) {
                w[i].count++;
                w[j].count = 0;
            }
        }
    }

    // Reverse the list to process elements in reverse order
    for (int i = 0; i < n / 2; i++) {
        element_count temp = w[i];
        w[i] = w[n - i - 1];
        w[n - i - 1] = temp;
    }

    // Initialize variables to track the index of the most frequent element and its value
    int c = -1, a = 0;

    // Iterate through each unique element in the count dictionary
    for (int i = 0; i < n; i++) {
        // Check if the current element's count is equal to the maximum count
        if (w[i].count == w[0].count) {
            // If the index of the current element in the reversed list is greater than the current index
            if (w[i].element > c) {
                // Update the most frequent element and its index
                a = w[i].element;
                c = w[i].element;
            }
        }
    }

    // Print the most frequent element that appears last in the original order
    printf("%c\n", a);

    return 0;
}

