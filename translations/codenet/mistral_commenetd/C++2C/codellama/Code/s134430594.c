#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Define a struct to store information about intervals
struct Ban {
    int l; // left endpoint of the interval
    int r; // right endpoint of the interval
    int val; // value of the interval

    Ban() {}

    Ban(int l_, int r_, int val_) {
        l = l_;
        r = r_;
        val = val_;
    }
};

// Define a struct to store information about the segment tree
struct Sp {
    int mn[20][200007]; // An array to store the minimum value in each segment of the segment tree
    int pw[200007]; // An array to store the power of 2 up to the maximum depth of the segment tree
};

// A function to initialize the segment tree
void Sp_init(struct Sp *sp, vector<int> a) {
    int n = (int)a.size();
    // Initialize the first level of the segment tree
    for (int i = 0; i < n; i++) {
        sp->mn[0][i] = a[i]; // Store the value of the element at index i in the first level of the segment tree
    }
    // Build the segment tree recursively
    for (int i = 0; i + 1 < 20; i++) {
        for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
            sp->mn[i + 1][j] = max(sp->mn[i][j], sp->mn[i][j + (1 << i)]); // Find the minimum value in the current segment and store it in the next level of the segment tree
        }
    }
    // Calculate the power of 2 up to the maximum depth of the segment tree
    sp->pw[1] = 0;
    for (int i = 2; i < 200007; i++) {
        sp->pw[i] = sp->pw[i / 2] + 1; // Calculate the power of 2 for each index
    }
}

// A function to get the minimum value in a segment of the segment tree
int Sp_get(struct Sp *sp, int l, int r) {
    r++; // Adjust the index of the right endpoint of the segment to be one more than the actual index
    int p = sp->pw[r - l]; // Calculate the depth of the segment tree for the given segment
    return min(sp->mn[p][l], sp->mn[p][r - (1 << p)]); // Return the minimum value in the given segment
}

int main() {
    // Read the number of elements in the array
    int n;
    scanf("%d", &n);

    // Read the elements of the array
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize some variables
    vector<int> dl(n); // An array to store the difference between the index and the index of the element in the array
    int ans = 0; // The answer
    vector<Ban> bans; // A vector to store some information about the intervals

    // Calculate the differences between the indices and the elements in the array
    for (int i = 0; i < n; i++) {
        if (a[i] > i) { // Check if the element is out of its position
            printf("%d\n", -1); // Output -1 if the element is out of its position
            return 0;
        }
        dl[i] = i - a[i]; // Calculate the difference between the index and the element
    }

    // Initialize the segment tree using the differences between the indices and the elements in the array
    struct Sp sp;
    Sp_init(&sp, dl);

    // Calculate the answer and store some information about the intervals in a vector
    for (int i = 0; i < n; i++) {
        int r = i; // Initialize a variable to store the right endpoint of the current interval
        while (r + 1 < n && a[r] + 1 == a[r + 1]) { // Check if there is a longer interval with the same value
            r++; // Move to the next index if there is
        }
        ans += a[r]; // Add the value of the right endpoint of the current interval to the answer
        i = r; // Update the index to be the right endpoint of the current interval
        bans.push_back(Ban(r - a[r], r, r - a[r])); // Store some information about the current interval in the vector
    }

    // Check some conditions and calculate the answer if possible
    for (int i = 0; i < (int)bans.size(); i++) {
        if (Sp_get(&sp, bans[i].l, bans[i].r) > bans[i].val) { // Check if the minimum value in the segment of the segment tree is greater than the value of the interval
            printf("%d\n", -1); // Output -1 if the condition is not satisfied
            return 0;
        }
    }

    // Output the answer
    printf("%d\n", ans);

    return 0;
}

