

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *a;
    int *b;
    int *c;
    int *d;
    int q;
    int n;
    int m;
    long ans;
} State;

void dfs(State *state, int *list, int size) {
    if (size == state->n) {
        long score = 0;
        for (int i = 0; i < state->q; i++) {
            score += (list[state->b[i]] - list[state->a[i]] == state->c[i])? state->d[i] : 0;
        }
        state->ans = score > state->ans? score : state->ans;
        return;
    }

    if (size > 0) {
        for (int num = list[size - 1]; num <= state->m; num++) {
            list[size] = num;
            dfs(state, list, size + 1);
        }
    } else {
        for (int num = 1; num <= state->m; num++) {
            list[size] = num;
            dfs(state, list, size + 1);
        }
    }
}

int main() {
    State *state = (State *)malloc(sizeof(State));
    state->a = (int *)malloc(sizeof(int) * 1000);
    state->b = (int *)malloc(sizeof(int) * 1000);
    state->c = (int *)malloc(sizeof(int) * 1000);
    state->d = (int *)malloc(sizeof(int) * 1000);
    int *list = (int *)malloc(sizeof(int) * 1000);

    scanf("%d %d %d", &state->n, &state->m, &state->q);
    for (int i = 0; i < state->q; i++) {
        scanf("%d %d %d %d", &state->a[i], &state->b[i], &state->c[i], &state->d[i]);
        state->a[i]--;
        state->b[i]--;
    }

    dfs(state, list, 0);
    printf("%ld\n", state->ans);

    free(state->a);
    free(state->b);
    free(state->c);
    free(state->d);
    free(list);
    free(state);

    return 0;
}

