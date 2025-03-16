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
    return -1; // Indicates no ceiling found
}

void remove_from_left(int index) {
    for (int i = 0; i < left_size; i++) {
        if (left[i] == index) {
            left[i] = left[left_size - 1]; // Replace with last element
            left_size--;
            return;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        add_to_left(i);
        answer[i] = 0; // Initialize answer array
    }
    
    int q;
    scanf("%d", &q);
    
    while (q-- > 0) {
        int l, r, win;
        scanf("%d %d %d", &l, &r, &win);
        l--; r--; win--; // Convert to 0-based index
        
        while (1) {
            int curr = ceiling(l);
            if (curr == -1 || curr > r) {
                break;
            }
            answer[curr] = win + 1; // Store the winner (1-based index)
            remove_from_left(curr);
        }
        answer[win] = 0; // Reset the winner's position
        add_to_left(win); // Add winner back to available positions
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d", answer[i]);
    }
    printf("\n");
    
    return 0;
}

/* <END-OF-CODE> */
