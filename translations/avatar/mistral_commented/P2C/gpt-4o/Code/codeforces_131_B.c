#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

// Structure to hold the count of each number
typedef struct {
    int number;
    int count;
} Counter;

// Function to compare two Counter elements for qsort
int compare(const void *a, const void *b) {
    return ((Counter *)a)->number - ((Counter *)b)->number;
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of test cases

    Counter w[MAX_SIZE];
    int unique_count = 0;

    // Read the numbers and count occurrences
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        // Check if the number is already counted
        int found = 0;
        for (int j = 0; j < unique_count; j++) {
            if (w[j].number == num) {
                w[j].count++;
                found = 1;
                break;
            }
        }
        
        // If not found, add it to the Counter
        if (!found) {
            w[unique_count].number = num;
            w[unique_count].count = 1;
            unique_count++;
        }
    }

    // Sort the Counter array
    qsort(w, unique_count, sizeof(Counter), compare);

    long long c = 0; // Initialize the counter for the result

    // Iterate through each number in the Counter
    for (int i = 0; i < unique_count; i++) {
        int current = w[i].number;
        if (current == 0) {
            // If the number is zero, add occurrences multiplied by (occurrences - 1)
            c += (long long)w[i].count * (w[i].count - 1);
        } else {
            // If the number '-current' is present, add occurrences multiplied by occurrences of 'current'
            for (int j = 0; j < unique_count; j++) {
                if (w[j].number == -current) {
                    c += (long long)w[i].count * w[j].count;
                    break;
                }
            }
        }
    }

    // Print the result divided by 2
    printf("%lld\n", c / 2);

    return 0;
}

// <END-OF-CODE>
