#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int answer[MAX_N];  // Array to store the answer for each index
int left[MAX_N];    // Array to store the indices of elements
int left_size = 0;  // Size of the left array

// Function to add an index to the left array
void add_to_left(int index) {
    left[left_size++] = index;
}

// Function to remove an index from the left array
void remove_from_left(int index) {
    for (int i = 0; i < left_size; i++) {
        if (left[i] == index) {
            left[i] = left[left_size - 1];  // Replace with the last element
            left_size--;  // Decrease the size
            return;
        }
    }
}

// Function to find the smallest index in left that is >= l
int ceiling(int l) {
    for (int i = 0; i < left_size; i++) {
        if (left[i] >= l) {
            return left[i];
        }
    }
    return -1;  // Return -1 if no such index exists
}

int main() {
    int n, q;
    scanf("%d", &n);  // Reading the number of elements in the array

    // Initializing the answer array with -1 and adding all indices to the left array
    for (int i = 0; i < n; i++) {
        add_to_left(i);
        answer[i] = -1;
    }

    scanf("%d", &q);  // Reading the number of queries

    // Processing each query
    while (q-- > 0) {
        int l, r, win;
        scanf("%d %d %d", &l, &r, &win);
        l--;  // Convert to 0-based index
        r--;  // Convert to 0-based index
        win--;  // Convert to 0-based index

        // Updating the answer for the winning index and all the indices between the left and right indices
        while (1) {
            int curr = ceiling(l);
            if (curr == -1 || curr > r) {
                break;
            }
            answer[curr] = win + 1;  // Store the winning index (1-based)
            remove_from_left(curr);
        }

        // Updating the answer for the winning index in the answer array
        answer[win] = 0;

        // Adding the winning index back to the left array
        add_to_left(win);
    }

    // Printing the answer for each index in the answer array
    for (int i = 0; i < n; i++) {
        printf("%d", answer[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");  // New line at the end

    return 0;
}

// <END-OF-CODE>
