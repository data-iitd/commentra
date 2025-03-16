#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct TSize
{
    int r;
    int c;
} TSize;

typedef struct TMatrix
{
    int** data;
    int row;
    int col;
} TMatrix;

TMatrix* TMatrix_new(int row, int col)
{
    TMatrix* m = (TMatrix*)malloc(sizeof(TMatrix));
    m->row = row;
    m->col = col;
    m->data = (int**)malloc(row * sizeof(int*));
    for(int i = 0; i < row; ++i){
        m->data[i] = (int*)malloc(col * sizeof(int));
        memset(m->data[i], 0, col * sizeof(int));
    }
    return m;
}

void TMatrix_delete(TMatrix* m)
{
    for(int i = 0; i < m->row; ++i){
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

int TMatrix_get(TMatrix* m, int r, int c)
{
    return m->data[r][c];
}

void TMatrix_set(TMatrix* m, int r, int c, int v)
{
    m->data[r][c] = v;
}

int TSize_count(TSize left, TSize right)
{
    return left.r * right.c * left.c;
}

int TMcmSolver_solve(TMatrix* memo, int s, int l, const std::vector<TSize>& chain)
{
    assert(s <= l);
    if(s == l) return 0;
    if(TMatrix_get(memo, s, l) != 0) return TMatrix_get(memo, s, l);
    if(s + 1 == l){
        TMatrix_set(memo, s, l, TSize_count(chain[s], chain[l]));
    }else{
        int min = INT_MAX;
        for(int i = s; i < l; ++i){
            int c = TMcmSolver_solve(memo, s, i, chain) + TSize_count(TSize(chain[s].r, chain[i].c), TSize(chain[i+1].r, chain[l].c)) + TMcmSolver_solve(memo, i+1, l, chain);
            min = c < min ? c : min;
        }
        TMatrix_set(memo, s, l, min);
    }
    return TMatrix_get(memo, s, l);
}

int TMcmSolver_answer(const std::vector<TSize>& chain)
{
    TMatrix* memo = TMatrix_new(chain.size(), chain.size());
    int answer = TMcmSolver_solve(memo, 0, memo->row - 1, chain);
    TMatrix_delete(memo);
    return answer;
}

int main()
{
    int n;
    scanf("%d", &n);
    if(n == 1){
        printf("0\n");
        return 0;
    }
    std::vector<TSize> chain(n);
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &chain[i].r, &chain[i].c);
    }
    int answer = TMcmSolver_answer(chain);
    printf("%d\n", answer);
    return 0;
}

