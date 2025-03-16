#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

typedef struct {
    int r;
    int c;
} TSize;

typedef struct {
    int** FMemo;
    TSize* FChain;
    int size;
} TMcmSolver;

<<<<<<< HEAD
int Count(TSize Left, TSize Right) {
    return Left.r * Right.c * Left.c;
}

int Solve(TMcmSolver* solver, int s, int l) {
=======
static int Count(const TSize* Left, const TSize* Right) {
    return Left->r * Right->c * Left->c;
}

static int Solve(TMcmSolver* solver, int s, int l) {
>>>>>>> 98c87cb78a (data updated)
    assert(s <= l);
    if (s == l) return 0;
    if (solver->FMemo[s][l] != 0) return solver->FMemo[s][l];
    if (s + 1 == l) {
<<<<<<< HEAD
        solver->FMemo[s][l] = Count(solver->FChain[s], solver->FChain[l]);
    } else {
        int min = INT_MAX;
        for (int i = s; i < l; ++i) {
            int c = Solve(solver, s, i) + Count((TSize){solver->FChain[s].r, solver->FChain[i].c}, (TSize){solver->FChain[i + 1].r, solver->FChain[l].c}) + Solve(solver, i + 1, l);
=======
        solver->FMemo[s][l] = Count(&solver->FChain[s], &solver->FChain[l]);
    } else {
        int min = INT_MAX;
        for (int i = s; i < l; ++i) {
            int c = Solve(solver, s, i) + Count(&(solver->FChain[s]), &(solver->FChain[i + 1])) + Solve(solver, i + 1, l);
>>>>>>> 98c87cb78a (data updated)
            if (c < min) {
                min = c;
            }
        }
        solver->FMemo[s][l] = min;
    }
    return solver->FMemo[s][l];
}

TMcmSolver* CreateSolver(TSize* Chain, int size) {
    TMcmSolver* solver = (TMcmSolver*)malloc(sizeof(TMcmSolver));
    solver->FChain = Chain;
    solver->size = size;
    solver->FMemo = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; ++i) {
        solver->FMemo[i] = (int*)calloc(size, sizeof(int));
    }
    return solver;
}

void FreeSolver(TMcmSolver* solver) {
    for (int i = 0; i < solver->size; ++i) {
        free(solver->FMemo[i]);
    }
    free(solver->FMemo);
    free(solver);
}

int Answer(TMcmSolver* solver) {
    return Solve(solver, 0, solver->size - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    TSize* Chain = (TSize*)malloc(n * sizeof(TSize));
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &Chain[i].r, &Chain[i].c);
    }
    TMcmSolver* Solver = CreateSolver(Chain, n);
    
    printf("%d\n", Answer(Solver));
    
    FreeSolver(Solver);
    free(Chain);
    return 0;
}

// <END-OF-CODE>
