#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, id = 0;
    int l, r;
    scanf("%d", &n);
    scanf("%d %d", &l, &r);

    for (int i = 1; i < n; i++) {
        int li, ri;
        scanf("%d %d", &li, &ri);
        if (li <= l && r <= ri) {
            id = i;
        } else if (li < l || r < ri) {
            id = n;
        }
        l = l < li ? l : li;
        r = r > ri ? r : ri;
    }

    printf("%d\n", id == n ? -1 : id + 1);
    return 0;
}

