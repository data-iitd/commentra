#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int first;
    char second[100]; // Assuming a maximum length for the string
} P;

P v[22];
<<<<<<< HEAD
int d[33][22]; // Array of lists to store indices
int d_size[33]; // To keep track of the size of each list
=======
int d[33][22]; // Array of arrays to store indices
int d_size[33]; // To keep track of the size of each array in d
>>>>>>> 98c87cb78a (data updated)

int compare(const void *a, const void *b) {
    P *p1 = (P *)a;
    P *p2 = (P *)b;
    return p1->first - p2->first; // Sort in ascending order
}

int main(void) {
    int n;
    while (scanf("%d", &n) && n) {
        int m;
        for (int i = 0; i < 33; i++) {
<<<<<<< HEAD
            d_size[i] = 0; // Clear the size of each list
=======
            d_size[i] = 0; // Clear the size of each array
>>>>>>> 98c87cb78a (data updated)
        }
        for (int i = 0; i < n; i++) {
            v[i].first = 0;
            scanf("%s %d", v[i].second, &m);
            for (int j = 0; j < m; j++) {
                int a;
                scanf("%d", &a);
                v[i].first += n - d_size[a]; // Update the first value
                for (int k = 0; k < d_size[a]; k++) {
<<<<<<< HEAD
                    v[d[a][k]].first--; // Decrease the first value of the corresponding indices
                }
                d[a][d_size[a]] = i; // Add the index to the list
                d_size[a]++; // Increment the size of the list
=======
                    v[d[a][k]].first--; // Decrement the first value of the corresponding indices
                }
                d[a][d_size[a]] = i; // Store the index
                d_size[a]++; // Increment the size for this index
>>>>>>> 98c87cb78a (data updated)
            }
        }
        qsort(v, n, sizeof(P), compare); // Sort the array of pairs
        printf("%d %s\n", v[0].first, v[0].second); // Output the result
    }
    return 0;
}
<<<<<<< HEAD

// <END-OF-CODE>
=======
>>>>>>> 98c87cb78a (data updated)
