#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int answer[MAX_N];
int left[MAX_N];
int left_size = 0;

void add_to_left(int index) {
    left[left_size++] = index;
}

int ceiling(int l) {
    for (int i = 0; i < left_size; i++) {
        if (left[i] >= l) {
            return left[i];
        }
    }
    return -1; // Indicates no valid ceiling found
}

void remove_from_left(int index) {
    for (int i = 0; i < left_size; i++) {
        if (left[i] == index) {
            left[i] = left[left_size - 1]; // Replace with the last element
            left_size--; // Decrease the size
            return;
        }
    }
}

int main() {
    int n, q;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        add_to_left(i);
        answer[i] = -1; // Initialize answer array
    }
    
    scanf("%d", &q);
    while (q-- > 0) {
        int l, r, win;
        scanf("%d %d %d", &l, &r, &win);
        l--; r--; win--; // Adjust for 0-based indexing
        
        while (1) {
            int curr = ceiling(l);
            if (curr == -1 || curr > r) break; // No more valid elements in range
            
            answer[curr] = win + 1; // Store the winning index (adjusted for 1-based indexing)
            remove_from_left(curr);
        }
        
        answer[win] = 0; // Set the winning index to 0
        add_to_left(win); // Add the winning index back to the left
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d", answer[i]); // Print the final result
    }
    printf("\n");
    
    return 0;
}

/* <END-OF-CODE> */
