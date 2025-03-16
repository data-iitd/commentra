#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_M 100
#define MAX_SIZE 1000

int li[MAX_M][MAX_N]; // Array to hold the lists
int p[MAX_M]; // Array to hold the tuple p
int q[MAX_SIZE]; // Array to hold unique elements from li
int v[MAX_SIZE]; // Array to hold elements in r but not in q
int n, m; // n and m values
int q_size = 0; // Size of unique elements in q
int v_size = 0; // Size of elements in v

// Function to check if an element is in an array
int contains(int *arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1;
        }
    }
    return 0;
}

// Function to count the number of common elements
int count_common(int *set1, int size1, int *set2, int size2) {
    int count = 0;
    for (int i = 0; i < size1; i++) {
        if (contains(set2, size2, set1[i])) {
            count++;
        }
    }
    return count;
}

// Function to generate combinations
void generate_combinations(int *set, int set_size, int *current_combination, int current_size, int start, int *ans, int *v, int v_size) {
    // Check each combination
    for (int i = 0; i < m; i++) {
        int common_count = count_common(current_combination, current_size, li[i], li[i][0]);
        if (common_count % 2 != p[i]) {
            return; // Break if condition fails
        }
    }
    // If all checks passed, increment the answer
    (*ans) += (1 << v_size); // 2^v_size
}

void combine(int *set, int set_size, int *current_combination, int current_size, int start, int *ans, int *v, int v_size) {
    // Generate combinations of all sizes
    for (int i = start; i < set_size; i++) {
        current_combination[current_size] = set[i];
        generate_combinations(current_combination, current_size + 1, ans, v, v_size);
        combine(set, set_size, current_combination, current_size + 1, i + 1, ans, v, v_size);
    }
}

int main() {
    // Reading n and m
    scanf("%d %d", &n, &m);
    
    // Reading m lists of integers
    for (int i = 0; i < m; i++) {
        int size;
        scanf("%d", &size);
        li[i][0] = size; // Store the size
        for (int j = 1; j <= size; j++) {
            scanf("%d", &li[i][j]);
            if (!contains(q, q_size, li[i][j])) {
                q[q_size++] = li[i][j]; // Add to q if not already present
            }
        }
    }
    
    // Reading the tuple p
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }
    
    // Creating the set r
    for (int i = 1; i <= n; i++) {
        if (!contains(q, q_size, i)) {
            v[v_size++] = i; // Add to v if not in q
        }
    }
    
    int ans = 0;
    int current_combination[MAX_SIZE];
    
    // Generate combinations of q
    combine(q, q_size, current_combination, 0, 0, &ans, v, v_size);
    
    // Print the final answer
    printf("%d\n", ans);
    
    return 0;
}

// <END-OF-CODE>
