#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} Job;

int compareJobs(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    if (jobA->a == jobB->a) {
        return jobA->b - jobB->b;
    }
    return jobA->a - jobB->a;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    Job *jobs = (Job *)malloc(N * sizeof(Job));
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &jobs[i].a, &jobs[i].b);
    }
    
    // Sort jobs based on the custom comparator
    qsort(jobs, N, sizeof(Job), compareJobs);
    
    int cnt = 0;
    int *jobQ = (int *)malloc(N * sizeof(int));
    int jobQSize = 0;

    for (int i = 1; i <= M; i++) {
        // Add jobs to jobQ that can be processed at time i
        for (int j = 0; j < N; j++) {
            if (jobs[j].a <= i) {
                jobQ[jobQSize++] = jobs[j].b;
            } else {
                break;
            }
        }
        
        // Sort jobQ in descending order
        for (int j = 0; j < jobQSize - 1; j++) {
            for (int k = j + 1; k < jobQSize; k++) {
                if (jobQ[j] < jobQ[k]) {
                    int temp = jobQ[j];
                    jobQ[j] = jobQ[k];
                    jobQ[k] = temp;
                }
            }
        }
        
        // Process the highest priority job
        if (jobQSize > 0) {
            cnt += jobQ[0];
            // Remove the processed job
            for (int j = 1; j < jobQSize; j++) {
                jobQ[j - 1] = jobQ[j];
            }
            jobQSize--;
        }
    }

    printf("%d\n", cnt);
    
    free(jobs);
    free(jobQ);
    
    return 0;
}

// <END-OF-CODE>
