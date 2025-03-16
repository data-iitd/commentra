#include <stdio.h>
#include <stdlib.h>

typedef struct Job { // Defining a structure named Job
    int a; // Declaring an integer variable named a
    int b; // Declaring an integer variable named b
} Job;

// Function to compare two jobs for sorting
int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    if (jobA->a == jobB->a) {
        return jobA->b - jobB->b; // If a values are equal, compare b values
    }
    return jobA->a - jobB->a; // Otherwise, compare a values
}

int main() { // Defining the main function
    int N, M; // Declaring integer variables N and M
    scanf("%d %d", &N, &M); // Reading N and M from input

    Job *jobs = (Job *)malloc(N * sizeof(Job)); // Allocating memory for N jobs

    for (int i = 0; i < N; i++) { // Iterating through the number of jobs
        scanf("%d %d", &jobs[i].a, &jobs[i].b); // Reading job a and b values
    }

    // Sorting jobs based on the compare function
    qsort(jobs, N, sizeof(Job), compare);

    int cnt = 0; // Initializing the counter variable to 0
    int *jobQ = (int *)malloc(N * sizeof(int)); // Allocating memory for jobQ
    int jobQSize = 0; // Size of jobQ

    for (int i = 1; i <= M; i++) { // Iterating through the number of machines
        for (int j = 0; j < N; j++) { // Iterating through the jobs
            if (jobs[j].a <= i) { // If the machine number is greater than or equal to job a
                jobQ[jobQSize++] = jobs[j].b; // Adding the benefit of the job to jobQ
            } else {
                break; // Exiting the loop if job a is greater than machine number
            }
        }

        // Sorting jobQ in descending order
        for (int k = 0; k < jobQSize - 1; k++) {
            for (int l = k + 1; l < jobQSize; l++) {
                if (jobQ[k] < jobQ[l]) {
                    int temp = jobQ[k];
                    jobQ[k] = jobQ[l];
                    jobQ[l] = temp;
                }
            }
        }

        if (jobQSize > 0) { // If jobQ is not empty
            cnt += jobQ[0]; // Adding the benefit of the job to the counter variable
            // Shift elements to remove the first element
            for (int k = 1; k < jobQSize; k++) {
                jobQ[k - 1] = jobQ[k];
            }
            jobQSize--; // Decreasing the size of jobQ
        }
    }

    printf("%d\n", cnt); // Printing the value of the counter variable

    free(jobs); // Freeing allocated memory for jobs
    free(jobQ); // Freeing allocated memory for jobQ

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
