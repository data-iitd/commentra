#include <stdio.h>
#include <stdlib.h>

// Step 2: Define Job structure
typedef struct {
    int a;
    int b;
} Job;

// Step 2: Implement compare function to compare jobs based on parameters a and b
int compare(const void *p1, const void *p2) {
    Job *job1 = (Job *)p1;
    Job *job2 = (Job *)p2;
    if (job1->a == job2->a)
        return job1->b - job2->b;
    else
        return job1->a - job2->a;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    // Step 4: Allocate memory for jobs array
    Job jobs[N];
    
    // Step 6: Read job details and store in the jobs array
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &jobs[i].a, &jobs[i].b);
    }
    
    // Step 7: Sort the jobs array using qsort and compare function
    qsort(jobs, N, sizeof(Job), compare);
    
    // Step 8: Initialize counters and another priority queue (using max heap)
    int cnt = 0;
    int jobQ[M];
    for (int i = 0; i < M; i++) {
        jobQ[i] = 0;
    }
    
    // Step 9: Process each day from 1 to M
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (jobs[i].a <= j + 1 && jobQ[j] == 0) {
                jobQ[j] = jobs[i].b;
                cnt += jobs[i].b;
                break;
            }
        }
    }
    
    // Step 10: Print the total reward
    printf("%d\n", cnt);
    
    return 0;
}
