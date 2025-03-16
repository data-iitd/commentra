
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Job {
    int a;
    int b;
} Job;

int compareJob(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;

    if (jobA->a == jobB->a) {
        return jobA->b - jobB->b;
    } else {
        return jobA->a - jobB->a;
    }
}

int main() {
    char input[1000];
    int N, M;
    int i, j;
    int cnt = 0;
    Job *jobs;
    int *machine;

    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d %d", &N, &M);

    jobs = (Job *)malloc(sizeof(Job) * N);
    machine = (int *)malloc(sizeof(int) * M);

    for (i = 0; i < N; i++) {
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d %d", &jobs[i].a, &jobs[i].b);
    }

    qsort(jobs, N, sizeof(Job), compareJob);

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (jobs[j].a <= i + 1) {
                machine[i] = j;
                break;
            }
        }
    }

    for (i = 0; i < M; i++) {
        if (machine[i]!= -1) {
            cnt += jobs[machine[i]].b;
        }
    }

    printf("%d\n", cnt);

    free(jobs);
    free(machine);

    return 0;
}

