#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100002

typedef struct {
    int value;
    int index;
} Element;

int compare(const void *a, const void *b) {
    return ((Element *)a)->value - ((Element *)b)->value;
}

int main() {
    int N;
    scanf("%d", &N);

    Element *elements = (Element *)malloc(N * sizeof(Element));
    int *index_map = (int *)malloc(MAX_NUM * sizeof(int));

    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        elements[i].value = tmp;
        elements[i].index = i;
        index_map[tmp] = i;
    }

    // Sort the elements based on their values
    qsort(elements, N, sizeof(Element), compare);

    int bin = 0;
    int diff = 0;

    for (int i = 0; i < N; i++) {
        int num = elements[i].value;
        int idx = index_map[num];
        if ((bin % 2) != (idx % 2)) {
            diff++;
        }
        bin++;
        bin %= 2;
    }

    int ans = diff / 2;
    printf("%d\n", ans);

    free(elements);
    free(index_map);

    return 0;
}

// <END-OF-CODE>
