#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} Tuple;

int compare(const void *p1, const void *p2) {
    Tuple *t1 = (Tuple *)p1;
    Tuple *t2 = (Tuple *)p2;
    return (t2->b - t1->b);
}

int main() {
    int n;
    printf("Enter the number of tuples: ");
    scanf("%d", &n);

    Tuple m[n];
    for (int i = 0; i < n; i++) {
        printf("Enter tuple %d: ", i + 1);
        scanf("%d %d", &m[i].a, &m[i].b);
    }

    qsort(m, n, sizeof(Tuple), compare);

    Tuple a = m[0];
    for (int i = 1; i < n; i++) {
        if (m[i].b > a.b) {
            printf("Happy Alex\n");
            return 0;
        }
        a = m[i];
    }

    printf("Poor Alex\n");
    return 0;
}
