#######
#include <stdio.h>
#include <stdlib.h>

// Class definition for CodeforcesTask397BSolution

typedef struct CodeforcesTask397BSolution {
    char *result;
    int t;
    int **queries;
} CodeforcesTask397BSolution;

// Method to read input
void read_input ( CodeforcesTask397BSolution *Solution ) {
    Solution->t = atoi(fgets(Solution->t, 100, stdin));
    Solution->queries = (int **) malloc(Solution->t * sizeof(int *));
    for ( int i = 0; i < Solution->t; i++ ) {
        Solution->queries[i] = (int *) malloc(3 * sizeof(int));
        Solution->queries[i][0] = atoi(fgets(Solution->queries[i][0], 100, stdin));
        Solution->queries[i][1] = atoi(fgets(Solution->queries[i][1], 100, stdin));
        Solution->queries[i][2] = atoi(fgets(Solution->queries[i][2], 100, stdin));
    }
}

// Method to process the task
void process_task ( CodeforcesTask397BSolution *Solution ) {
    char *res = (char *) malloc(Solution->t * 100);
    for ( int i = 0; i < Solution->t; i++ ) {
        int k = Solution->queries[i][0] / Solution->queries[i][1];
        if ( k * Solution->queries[i][2] >= Solution->queries[i][0] ) {
            strcpy(res + i * 100, "Yes");
        } else {
            strcpy(res + i * 100, "No");
        }
    }
    Solution->result = res;
}

// Method to get the result
char *get_result ( CodeforcesTask397BSolution *Solution ) {
    return Solution->result;
}

// Main method to run the code
int main ( void ) {
    CodeforcesTask397BSolution Solution;
    Solution.result = (char *) malloc(100);
    read_input(&Solution);
    process_task(&Solution);
    printf("%s", get_result(&Solution));
    return 0;
}

