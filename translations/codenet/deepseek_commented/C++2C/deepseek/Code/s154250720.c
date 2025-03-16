#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

// Define constants
#define maxn 200000 + 10
#define INF 100000000

// Declare arrays
int maps[maxn];
int num[maxn];

int main() {
    int n;
    while(~scanf("%d", &n)) { // Read the number of elements
        // Read the elements into maps array and copy them to num array
        for(int i = 1; i <= n; i++) {
            scanf("%d", &maps[i]);
            num[i] = maps[i];
        }

        // Sort the maps array to find the median easily
        std::sort(maps + 1, maps + n + 1);

        // Calculate the median index
        int m = n / 2;

        // Iterate through the num array and print the appropriate median value
        for(int i = 1; i <= n; i++) {
            if(num[i] <= maps[m])
                printf("%d\n", maps[m + 1]); // Print the element after the median if num[i] is less than or equal to the median
            else
                printf("%d\n", maps[m]); // Print the median if num[i] is greater than the median
        }
    }
    return 0;
}
