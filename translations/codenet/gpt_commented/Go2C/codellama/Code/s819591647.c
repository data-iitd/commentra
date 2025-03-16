
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define constMod 1000000007

// Read n and m from input
int n, m;
scanf("%d %d", &n, &m);

// Read n integers into array a
int a[n];
for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
}

// Calculate the sum of all elements in a
int sum = 0;
for (int i = 0; i < n; i++) {
    sum += a[i];
}

// Count how many elements in a meet the required rate
int count = 0;
for (int i = 0; i < n; i++) {
    float rate = (float)sum / (4 * m);
    if (a[i] >= rate) {
        count++;
    }
}

// Output "Yes" if count is greater than or equal to m, otherwise "No"
if (count >= m) {
    printf("Yes\n");
} else {
    printf("No\n");
}

// End of code
