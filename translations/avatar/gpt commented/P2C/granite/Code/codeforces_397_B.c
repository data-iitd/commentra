
#include <stdio.h>

int main() {
    // Initialize the result string, number of queries, and a list to hold the queries
    char result[100000];
    int t, queries[1000][3];
    int i, j, k;

    // Read the number of queries from input
    scanf("%d", &t);
    // Read each query and store it as a list of integers in the queries list
    for (i = 0; i < t; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &queries[i][j]);
        }
    }

    // Process each query to determine if the condition is met
    for (i = 0; i < t; i++) {
        // Calculate how many complete sets of queries[i][1] fit into queries[i][0]
        k = queries[i][0] / queries[i][1];
        // Check if k multiplied by queries[i][2] is at least queries[i][0]
        if (k * queries[i][2] >= queries[i][0]) {
            sprintf(result + strlen(result), "Yes\n");
        } else {
            sprintf(result + strlen(result), "No\n");
        }
    }

    // Print the final results
    printf("%s", result);

    return 0;
}
