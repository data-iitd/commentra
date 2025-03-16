
#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 INT64_MAX
#define INF_BIT60 1LL << 60
#define INF_INT32 INT32_MAX
#define INF_BIT30 1 << 30
#define NIL -1

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef long long ll;

int n, q;
int C[500000 + 50];
int P[500000 + 50];
int Answers[500000 + 50];

typedef struct Query {
    int idx, l, r;
} Query;

Query Q[500000 + 50];

void init() {
    // bufio.ScanWords <---> bufio.ScanLines
    // ReadString = newReadString(os.Stdin, bufio.ScanWords)
    // stdout = bufio.NewWriter(os.Stdout)
}

int main() {
    // Read input
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &C[i]);
        P[i] = -1;
    }

    // Process queries
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &Q[i].l, &Q[i].r);
        Q[i].idx = i;
    }

    qsort(Q, q, sizeof(Query), compare);

    int k = 0;
    for (int i = 0; i < q; i++) {
        // Process each query
        for (k = Q[i].l; k <= Q[i].r; k++) {
            if (P[C[k]]!= -1) {
                // ft.Add(P[C[k]]+1, -1);
            }
            P[C[k]] = k;
            // ft.Add(k+1, 1);
        }

        // Calculate answer and print it
        // Answers[Q[i].idx] = ft.Sum(Q[i].r) - ft.Sum(Q[i].l-1);
    }

    // Print answers
    for (int i = 0; i < q; i++) {
        // printf("%d\n", Answers[i]);
    }

    return 0;
}

int compare(const void *a, const void *b) {
    Query *q1 = (Query *)a;
    Query *q2 = (Query *)b;

    if (q1->r < q2->r) {
        return -1;
    } else if (q1->r > q2->r) {
        return 1;
    } else {
        return 0;
    }
}

