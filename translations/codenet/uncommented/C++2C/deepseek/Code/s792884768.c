#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

typedef struct {
    int r;
    int c;
} TSize;

typedef struct {
    int **FMemo;
    TSize *FChain;
    int FSize;
} TMcmSolver;

int Count(TSize Left, TSize Right) {
    return Left.r * Right.c * Left.c;
}

int Solve(TMcmSolver *solver, int s, int l) {
    assert(s <= l);
    if (s == l) return 0;
    if (solver->FMemo[s][l] != 0) return solver->FMemo[s][l];
    if (s + 1 == l) {
        solver->FMemo[s][l] = Count(solver->FChain[s], solver->FChain[l]);
    } else {
        int min = INT_MAX;
        for (int i = s; i < l; ++i) {
            int c = Solve(solver, s, i) + Count(TSize{solver->FChain[s].r, solver->FChain[i].c}, TSize{solver->FChain[i + 1].r, solver->FChain[l].c}) + Solve(solver, i + 1, l);
            if (c < min) min = c;
        }
        solver->FMemo[s][l] = min;
    }
    return solver->FMemo[s][l];
}

TMcmSolver* CreateSolver(TSize *Chain, int size) {
    TMcmSolver *solver = (TMcmSolver *)malloc(sizeof(TMcmSolver));
    solver->FChain = Chain;
    solver->FSize = size;
    solver->FMemo = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; ++i) {
        solver->FMemo[i] = (int *)calloc(size, sizeof(int));
    }
    return solver;
}

int Answer(TMcmSolver *solver) {
    return Solve(solver, 0, solver->FSize - 1);
}

void FreeSolver(TMcmSolver *solver) {
    for (int i = 0; i < solver->FSize; ++i) {
        free(solver->FMemo[i]);
    }
    free(solver->FMemo);
    free(solver->FChain);
    free(solver);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    TSize *Chain = (TSize *)malloc(n * sizeof(TSize));
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &Chain[i].r, &Chain[i].c);
    }
    TMcmSolver *Solver = CreateSolver(Chain, n);
    int result = Answer(Solver);
    printf("%d\n", result);
    FreeSolver(Solver);
    free(Chain);
    return 0;
}
