#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} Job;

int compare_jobs(const void *a, const void *b) {
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    if (job1->a == job2->a) {
        return job1->b - job2->b;
    } else {
        return job1->a - job2->a;
    }
}

int compare_ints(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Job jobs[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &jobs[i].a, &jobs[i].b);
    }

    qsort(jobs, N, sizeof(Job), compare_jobs);

    int cnt = 0;
    int jobQ[M];
    int jobQ_size = 0;

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < N; j++) {
            if (jobs[j].a <= i) {
                jobQ[jobQ_size++] = jobs[j].b;
                jobs[j].a = M + 1; // Mark as processed
            } else {
                break;
            }
        }

        if (jobQ_size > 0) {
            qsort(jobQ, jobQ_size, sizeof(int), compare_ints);
            cnt += jobQ[0];
            jobQ_size--;
        }
    }

    printf("%d\n", cnt);
    return 0;
}
