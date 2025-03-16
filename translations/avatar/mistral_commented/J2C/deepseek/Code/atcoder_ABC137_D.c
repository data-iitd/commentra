#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int a;
    int b;
} Job;

int compareJobs(const void *p1, const void *p2) {
    Job *job1 = (Job *)p1;
    Job *job2 = (Job *)p2;
    if (job1->a == job2->a) {
        return job1->b - job2->b;
    } else {
        return job1->a - job2->a;
    }
}

int compareInts(const void *p1, const void *p2) {
    return (*(int *)p2 - *(int *)p1);
}

int main() {
    int N, M, cnt = 0;
    char line[100];
    char *token;
    Job jobs[1000];
    int jobQ[1000];
    int jobQSize = 0;

    fgets(line, sizeof(line), stdin);
    token = strtok(line, "\u2581");
    N = atoi(token);
    token = strtok(NULL, "\u2581");
    M = atoi(token);

    for (int i = 0; i < N; i++) {
        fgets(line, sizeof(line), stdin);
        token = strtok(line, "\u2581");
        jobs[i].a = atoi(token);
        token = strtok(NULL, "\u2581");
        jobs[i].b = atoi(token);
    }

    qsort(jobs, N, sizeof(Job), compareJobs);

    for (int i = 1; i <= M; i++) {
        while (N > 0 && jobs[N - 1].a <= i) {
            jobQ[jobQSize++] = jobs[N - 1].b;
            N--;
        }
        if (jobQSize > 0) {
            qsort(jobQ, jobQSize, sizeof(int), compareInts);
            cnt += jobQ[0];
            jobQSize--;
        }
    }

    printf("%d\n", cnt);
    return 0;
}
