#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int id = 0;
    int l, r;
    scanf("%d %d", &l, &r);

    for (int i = 1; i < n; i++) {
        int li, ri;
        scanf("%d %d", &li, &ri);
        
        // Check if the current interval completely covers the best candidate interval
        if (li <= l && r <= ri) {
            id = i;
        }
        // Check if the current interval overlaps with the best candidate interval
        else if (li < l || r < ri) {
            id = n;
        }
        // Update the boundaries of the best candidate interval
        l = (l < li) ? l : li;
        r = (r > ri) ? r : ri;
    }

    // Output the result
    printf("%d\n", (id == n) ? -1 : id + 1);

    return 0;
}

// <END-OF-CODE>
