#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    long x;

    // Reading input from the console
    scanf("%d", &N);
    scanf("%ld", &x);

    long srimeList[N];

    // Reading elements of the array
    for (int i = 0; i < N; i++) {
        scanf("%ld", &srimeList[i]);
    }

    long costList[N][N];

    // Filling the cost arrays with the minimum cost for each index and each cast number
    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i]; // Setting the first element of the cost array to the original element
        for (int castNum = 1; castNum < N; castNum++) {
            int index = (i - castNum + N) % N;
            costList[i][castNum] = (costList[i][castNum - 1] < srimeList[index]) ? costList[i][castNum - 1] : srimeList[index];
        }
    }

    long result[N];

    // Calculating the result for each index and adding it to the ArrayList
    for (int i = 0; i < N; i++) {
        long temp = i * x; // Multiplying the index with the multiplier
        for (int j = 0; j < N; j++) {
            temp += costList[i][j];
        }
        result[i] = temp;
    }

    // Finding the minimum result
    long minResult = result[0];
    for (int i = 1; i < N; i++) {
        if (result[i] < minResult) {
            minResult = result[i];
        }
    }

    // Printing the minimum result
    printf("%ld\n", minResult);

    return 0;
}
