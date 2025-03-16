#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Step 2: Define Job struct
typedef struct {
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
    char line[100];
    int N, M;
    scanf("%s", line);
    sscanf(line, "%d \u2581 %d", &N, &M);
    
    // Step 5: Create a priority queue to store jobs
    Job *q = (Job *)malloc(N * sizeof(Job));
    for (int i = 0; i < N; i++) {
        scanf("%s", line);
        sscanf(line, "%d \u2581 %d", &q[i].a, &q[i].b);
    }
    qsort(q, N, sizeof(Job), compare);
    
    // Step 6: Read job details and add to the priority queue
    int cnt = 0;
    int *jobQ = (int *)malloc(N * sizeof(int));
    int jobQSize = 0;
    
    // Step 7: Process each day from 1 to M
    for (int i = 1; i <= M; i++) {
        while (q[0].a <= i) {
            jobQ[jobQSize++] = q[0].b;
            q++;
        }
        if (jobQSize > 0)
            cnt += jobQ[--jobQSize];
    }
    
    // Step 10: Print the total reward
    printf("%d\n", cnt);
    
    // Step 11: Free memory
    free(q);
    free(jobQ);
    
    return 0;
}

