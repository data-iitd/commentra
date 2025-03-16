#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int a;
    int b;
} Job;

int compare(const void *a, const void *b) {
    Job *job1 = (Job *) a;
    Job *job2 = (Job *) b;

    if (job1->a == job2->a) {
        return job1->b - job2->b;
    } else {
        return job1->a - job2->a;
    }
}

int main() {
    char *line = NULL;
    size_t len = 0;
    int N, M;

    getline(&line, &len, stdin);
    sscanf(line, "%d %d", &N, &M);

    Job *jobs = (Job *) malloc(N * sizeof(Job));

    for (int i = 0; i < N; i++) {
        getline(&line, &len, stdin);
        sscanf(line, "%d %d", &jobs[i].a, &jobs[i].b);
    }

    qsort(jobs, N, sizeof(Job), compare);

    int cnt = 0;
    int *benefits = (int *) malloc(M * sizeof(int));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (jobs[j].a <= i + 1) {
                benefits[i] += jobs[j].b;
                jobs[j].a = 0;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        cnt += benefits[i];
    }

    printf("%d\n", cnt);

    free(jobs);
    free(benefits);

    return 0;
}

