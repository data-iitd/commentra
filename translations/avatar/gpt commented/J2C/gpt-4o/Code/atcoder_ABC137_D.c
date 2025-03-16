#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a; // Represents the time or priority of the job
    int b; // Represents the value or weight of the job
} Job;

// Comparator function for sorting jobs
int compareJobs(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    if (jobA->a == jobB->a) {
        return jobA->b - jobB->b; // Compare by 'b' if 'a' is equal
    }
    return jobA->a - jobB->a; // Compare by 'a'
}

// Function to process jobs
int processJobs(Job *jobs, int N, int M) {
    int cnt = 0; // Counter to accumulate the total value of jobs processed
    int *jobQ = (int *)malloc(N * sizeof(int)); // Queue to hold job values
    int jobQSize = 0; // Size of jobQ

    for (int i = 1; i <= M; i++) {
        // Add jobs that can be processed at time i to jobQ
        for (int j = 0; j < N; j++) {
            if (jobs[j].a <= i) {
                jobQ[jobQSize++] = jobs[j].b; // Add job value to jobQ
            }
        }

        // Sort jobQ in descending order
        qsort(jobQ, jobQSize, sizeof(int), (int (*)(const void *, const void *))compareJobs);
        
        // If there are jobs available to process, add the highest value job to the counter
        if (jobQSize > 0) {
            cnt += jobQ[--jobQSize]; // Poll the highest value job from jobQ and add to cnt
        }
    }

    free(jobQ); // Free allocated memory
    return cnt; // Return the total value of jobs processed
}

int main() {
    int N, M;
    // Read the first line of input
    scanf("%d \u2581 %d", &N, &M);

    Job *jobs = (Job *)malloc(N * sizeof(Job)); // Allocate memory for jobs

    // Read the job details
    for (int i = 0; i < N; i++) {
        scanf("%d \u2581 %d", &jobs[i].a, &jobs[i].b);
    }

    // Process jobs and get the total value
    int totalValue = processJobs(jobs, N, M);
    
    // Output the total value of jobs processed
    printf("%d\n", totalValue);

    free(jobs); // Free allocated memory for jobs
    return 0;
}

// <END-OF-CODE>
