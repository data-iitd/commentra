
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int l, r;
    scanf("%d %d", &l, &r);

    int id = 0;
    for (int i = 1; i < n; i++) {
        int li, ri;
        scanf("%d %d", &li, &ri);

        if (li <= l && r <= ri) {
            id = i;
        } else if (li < l || r < ri) {
            id = n;
        }

        l = (l < li)? l : li;
        r = (r > ri)? r : ri;
    }

    printf("%d\n", (id == n)? -1 : id + 1);

    return 0;
}
