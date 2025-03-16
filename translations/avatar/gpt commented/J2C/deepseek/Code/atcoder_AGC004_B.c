#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N;
    long x, srimeList[1000], costList[1000][1000];
    long result[1000];
    
    // Read the number of elements (N) and a long value (x) from input
    scanf("%d %ld", &N, &x);
    
    // Read N long values into the srimeList
    for (int i = 0; i < N; i++) {
        scanf("%ld", &srimeList[i]);
    }
    
    // Populate the costList with minimum values based on the srimeList
    for (int i = 0; i < N; i++) {
        // Set the first column of costList to the corresponding values from srimeList
        costList[i][0] = srimeList[i];
        // Calculate the minimum costs for each subsequent column
        for (int castNum = 1; castNum < N; castNum++) {
            int index = (i - castNum + N) % N;
            costList[i][castNum] = (costList[i][castNum - 1] < srimeList[index]) ? costList[i][castNum - 1] : srimeList[index];
        }
    }
    
    // Calculate the result for each index based on the costs and the value of x
    for (int i = 0; i < N; i++) {
        result[i] = 0;
        for (int j = 0; j < N; j++) {
            result[i] += costList[j][i];
        }
        result[i] += i * x;
    }
    
    // Find the minimum value from the result list
    long minResult = LONG_MAX;
    for (int i = 0; i < N; i++) {
        if (result[i] < minResult) {
            minResult = result[i];
        }
    }
    
    // Print the minimum value
    printf("%ld\n", minResult);
    
    return 0;
}
