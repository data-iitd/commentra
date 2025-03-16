
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

// Step 2: Define Job struct
typedef struct Job {
    int a;
    int b;
} Job;

// Step 2: Implement compare function to compare jobs based on parameters a and b
int compare(const void *a, const void *b) {
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    
    if (job1->a == job2->a)
        return job1->b - job2->b;
    else
        return job1->a - job2->a;
}

int main() {
    // Step 4: Read input and initialize variables
    char line[1000];
    fgets(line, sizeof(line), stdin);
    char *token = strtok(line, " \u2581");
    int N = atoi(token);
    token = strtok(NULL, " \u2581");
    int M = atoi(token);
    
    // Step 5: Create an array to store jobs
    Job *jobs = (Job *)malloc(N * sizeof(Job));
    
    // Step 6: Read job details and store in the array
    for (int i = 0; i < N; i++) {
        fgets(line, sizeof(line), stdin);
        token = strtok(line, " \u2581");
        jobs[i].a = atoi(token);
        token = strtok(NULL, " \u2581");
        jobs[i].b = atoi(token);
    }
    
    // Step 7: Initialize counters and another array to store job indices
    int cnt = 0;
    int *jobIndices = (int *)malloc(N * sizeof(int));
    int jobCount = 0;
    
    // Step 8: Process each day from 1 to M
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < N; j++) {
            if (jobs[j].a <= i) {
                jobIndices[jobCount++] = j;
            }
        }
        
        qsort(jobIndices, jobCount, sizeof(int), compare);
        
        for (int j = 0; j < jobCount; j++) {
            cnt += jobs[jobIndices[j]].b;
        }
        
        jobCount = 0;
    }
    
    // Step 10: Print the total reward
    printf("%d\n", cnt);
    
    // Step 11: Free memory
    free(jobs);
    free(jobIndices);
    
    return 0;
}
