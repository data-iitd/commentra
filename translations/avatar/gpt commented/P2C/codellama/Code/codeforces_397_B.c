#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Initialize the result string, number of queries, and a list to hold the queries
    char result[1000000] = "";
    int t = 0;
    int queries[1000000][3];

    // Read the number of queries from input
    scanf("%d", &t);
    // Read each query and store it as a list of integers in the queries list
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &queries[i][j]);
        }
    }

    // Initialize a list to hold the results for each query
    char res[1000000][4];
    // Process each query to determine if the condition is met
    for (int i = 0; i < t; i++)
    {
        // Calculate how many complete sets of queries[i][1] fit into queries[i][0]
        int k = queries[i][0] / queries[i][1];
        // Check if k multiplied by queries[i][2] is at least queries[i][0]
        if (k * queries[i][2] >= queries[i][0])
        {
            strcpy(res[i], "Yes");
        }
        else
        {
            strcpy(res[i], "No");
        }
    }
    // Join the results into a single string separated by newlines
    for (int i = 0; i < t; i++)
    {
        strcat(result, res[i]);
        strcat(result, "\n");
    }

    // Print the final results
    printf("%s", result);

    // End of code
    return 0;
}
