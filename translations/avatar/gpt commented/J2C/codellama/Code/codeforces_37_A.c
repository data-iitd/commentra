#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 

// Structure to store the frequency of each integer
struct HashMap { 
    int val; 
    int count; 
}; 

// Function to read input efficiently
void read_input(struct HashMap *map, int *n) { 
    scanf("%d", n); 
    for (int i = 0; i < *n; i++) { 
        scanf("%d", &map[i].val); 
        map[i].count = 0; 
    } 
} 

// Function to update the frequency of each integer
void update_frequency(struct HashMap *map, int n) { 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            if (map[i].val == map[j].val) { 
                map[i].count++; 
            } 
        } 
    } 
} 

// Function to find the maximum frequency
int find_max(struct HashMap *map, int n) { 
    int max = INT_MIN; 
    for (int i = 0; i < n; i++) { 
        if (map[i].count > max) { 
            max = map[i].count; 
        } 
    } 
    return max; 
} 

// Function to print the maximum frequency and the number of unique integers
void print_output(int max, int n) { 
    printf("%d %d\n", max, n); 
} 

// Driver function
int main() { 
    // Initialize a HashMap to store the frequency of each integer
    struct HashMap map[1000]; 
    int n; 
    read_input(map, &n); 
    update_frequency(map, n); 
    int max = find_max(map, n); 
    print_output(max, n); 
    return 0; 
} 

