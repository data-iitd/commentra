
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *a;
    int *b;
    int *c;
    int *d;
    int n;
    int m;
    int q;
    long ans;
} State;

void dfs(State *state, int *list, int size) {
    if (size == state->n) {
        long score = 0;
        for (int i = 0; i < state->q; i++) {
            if (list[state->b[i]] - list[state->a[i]] == state->c[i]) {
                score += state->d[i];
            }
        }
        if (score > state->ans) {
            state->ans = score;
        }
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
    State state;
    state.a = (int *)malloc(sizeof(int) * 100);
    state.b = (int *)malloc(sizeof(int) * 100);
    state.c = (int *)malloc(sizeof(int) * 100);
    state.d = (int *)malloc(sizeof(int) * 100);
    int *list = (int *)malloc(sizeof(int) * 100);
    scanf("%d %d %d", &state.n, &state.m, &state.q);
    for (int i = 0; i < state.q; i++) {
        scanf("%d %d %d %d", &state.a[i], &state.b[i], &state.c[i], &state.d[i]);
    }
    state.ans = -100000000000000000L;
    dfs(&state, list, 0);
    printf("%ld\n", state.ans);
    free(state.a);
    free(state.b);
    free(state.c);
    free(state.d);
    free(list);
    return 0;
}
// END-OF-CODE