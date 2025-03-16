#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int first;
    char second[100]; // Assuming a maximum length for the string
} P;

P v[22]; // Array to store n pairs
int d[33][22]; // Array of arrays to store indices
int d_size[33]; // Array to keep track of the size of each d array

int main(void) {
    int n;
    while (scanf("%d", &n) && n) { // Read n until it is zero
        int m;
        for (int i = 0; i < 33; i++) {
            d_size[i] = 0; // Clear all sizes in d
        }
        for (int i = 0; i < n; i++) { // Read m for each element
            v[i].first = 0; // Initialize the first element of v to 0
            scanf("%s %d", v[i].second, &m); // Read the string and m
            for (int j = 0; j < m; j++) { // For each m, read an integer and update v and d
                int a;
                scanf("%d", &a);
                v[i].first += n - d_size[a]; // Update the first element of v
                for (int k = 0; k < d_size[a]; k++) { // Update the first elements of other v elements
                    v[d[a][k]].first--;
                }
                d[a][d_size[a]] = i; // Store the index of the current element in d
<<<<<<< HEAD
                d_size[a]++; // Increment the size of the current d array
=======
                d_size[a]++; // Increment the size of the corresponding d array
>>>>>>> 98c87cb78a (data updated)
            }
        }
        
        // Sort the array v based on the first element of P
        for (int i = 0; i < n - 1; i++) {
<<<<<<< HEAD
            for (int j = 0; j < n - i - 1; j++) {
                if (v[j].first > v[j + 1].first) {
                    P temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
=======
            for (int j = i + 1; j < n; j++) {
                if (v[i].first > v[j].first) {
                    P temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
>>>>>>> 98c87cb78a (data updated)
                }
            }
        }
        
        printf("%d %s\n", v[0].first, v[0].second); // Output the first element of v
    }
    return 0;
}

// <END-OF-CODE>
