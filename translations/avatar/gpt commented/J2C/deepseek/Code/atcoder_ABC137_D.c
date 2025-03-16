#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Job with two attributes 'a' and 'b'
typedef struct {
    int a; // Represents the time or priority of the job
    int b; // Represents the value or weight of the job
} Job;

// Define a comparison function for Job structures
int compareJobs(const void *p1, const void *p2) {
    Job *job1 = (Job *)p1;
    Job *job2 = (Job *)p2;
    if (job1->a == job2->a)
        return job1->b - job2->b;
    else
        return job1->a - job2->a;
}

// Define a comparison function for integers in descending order
int compareIntDesc(const void *p1, const void *p2) {
    return (*(int *)p2 - *(int *)p1);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Allocate memory for an array of Job structures
    Job *jobs = (Job *)malloc(N * sizeof(Job));

    // Read the job details and store them in the array
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &jobs[i].a, &jobs[i].b);
    }

    // Sort the jobs based on their 'a' attribute
    qsort(jobs, N, sizeof(Job), compareJobs);

    int cnt = 0; // Counter to accumulate the total value of jobs processed
    int *jobQ = (int *)malloc(N * sizeof(int)); // Array to hold job values in descending order
    int jobQSize = 0; // Size of the jobQ array

    // Process jobs for each time unit from 1 to M
    for (int i = 1; i <= M; i++) {
        // While there are jobs that can be processed at time i
        while (N > 0 && jobs[N - 1].a <= i) {
            jobQ[jobQSize++] = jobs[--N].b; // Add the job value to jobQ and decrement N
        }

        // If there are jobs available to process, add the highest value job to the counter
        if (jobQSize > 0) {
            qsort(jobQ, jobQSize, sizeof(int), compareIntDesc); // Sort jobQ in descending order
            cnt += jobQ[--jobQSize]; // Add the highest value job from jobQ to cnt and decrement jobQSize
        }
    }

    // Output the total value of jobs processed
    printf("%d\n", cnt);

    // Free allocated memory
    free(jobs);
    free(jobQ);

    return 0;
}
