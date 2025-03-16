
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct TSize
{
    int r;
    int c;
} TSize;

typedef struct TMcmSolver
{
    TSize* FChain;
    int* FMemo;
    int FSize;

    int Count(TSize Left, TSize Right)
    {
        return Left.r * Right.c * Left.c;
    }
    int Solve(int s, int l)
    {
        if(s == l) return 0;
        if(FMemo[s*FSize+l]!= 0) return FMemo[s*FSize+l];
        if(s + 1 == l){
            FMemo[s*FSize+l] = Count(FChain[s], FChain[l]);
        }else{
            int min = INT_MAX;
            for(int i = s; i < l; ++i){
                int c = Solve(s, i) + Count((TSize){FChain[s].r, FChain[i].c}, (TSize){FChain[i+1].r, FChain[l].c}) + Solve(i+1, l);
                if(c < min) min = c;
            }
            FMemo[s*FSize+l] = min;
        }
        return FMemo[s*FSize+l];
    }
} TMcmSolver;

TMcmSolver* CreateSolver(TSize* Chain, int Size)
{
    TMcmSolver* Solver = (TMcmSolver*)malloc(sizeof(TMcmSolver));
    Solver->FChain = Chain;
    Solver->FSize = Size;
    Solver->FMemo = (int*)malloc(sizeof(int)*Size*Size);
    for(int i = 0; i < Size*Size; ++i){
        Solver->FMemo[i] = 0;
    }
    return Solver;
}

void DestroySolver(TMcmSolver* Solver)
{
    free(Solver->FMemo);
    free(Solver);
}

int Answer(TMcmSolver* Solver)
{
    return Solver->Solve(0, Solver->FSize-1);
}

int main()
{
    int n;
    scanf("%d", &n);
    if(n == 1){
        printf("0\n");
        return 0;
    }
    TSize* Chain = (TSize*)malloc(sizeof(TSize)*n);
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &Chain[i].r, &Chain[i].c);
    }
    TMcmSolver* Solver = CreateSolver(Chain, n);
    printf("%d\n", Answer(Solver));
    DestroySolver(Solver);
    free(Chain);
    return 0;
}

