#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} Job;

// Comparator function for the priority queue
int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    if (jobA->a == jobB->a) {
        return jobA->b - jobB->b;
    }
    return jobA->a - jobB->a;
}

// Function to add a job to the priority queue
void addJob(Job *jobs, int *size, Job job) {
    jobs[(*size)++] = job;
    qsort(jobs, *size, sizeof(Job), compare);
}

// Function to remove the job with the highest reward
int removeJob(Job *jobs, int *size) {
    if (*size == 0) return 0; // No jobs to remove
    int reward = jobs[*size - 1].b; // Get the highest reward
    (*size)--; // Decrease the size
    return reward;
}

int main() {
    int N, M;
    scanf("%d \u2581 %d", &N, &M);
    
    Job *jobs = malloc(N * sizeof(Job));
    int jobCount = 0;

    // Read job details and add to the array
    for (int i = 0; i < N; i++) {
        scanf("%d \u2581 %d", &jobs[i].a, &jobs[i].b);
        jobCount++;
    }

    // Sort jobs initially
    qsort(jobs, jobCount, sizeof(Job), compare);

    int cnt = 0;
    Job *jobQ = malloc(N * sizeof(Job));
    int jobQCount = 0;

    // Process each day from 1 to M
    for (int i = 1; i <= M; i++) {
        // Add jobs that can be processed on day i
        for (int j = 0; j < jobCount; j++) {
            if (jobs[j].a <= i) {
                jobQ[jobQCount++] = jobs[j]; // Add to jobQ
            } else {
                break; // No more jobs can be added
            }
        }
        // Remove the job with the highest reward
        if (jobQCount > 0) {
            cnt += removeJob(jobQ, &jobQCount);
        }
    }

    // Print the total reward
    printf("%d\n", cnt);

    // Free allocated memory
    free(jobs);
    free(jobQ);

    return 0;
}

// <END-OF-CODE>
