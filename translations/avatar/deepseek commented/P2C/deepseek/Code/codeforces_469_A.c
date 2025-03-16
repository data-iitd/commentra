#include <stdio.h>
#include <stdlib.h>

int main() {
    int max_level, n, m, i, level;
    scanf("%d", &max_level);

    // Read the first list and discard the first element
    scanf("%d", &n);
    int x[n];
    for (i = 1; i < n; i++) {
        scanf("%d", &x[i]);
    }

    // Read the second list and discard the first element
    scanf("%d", &m);
    int y[m];
    for (i = 1; i < m; i++) {
        scanf("%d", &y[i]);
    }

    // Create sets and add elements, discarding 0 if present
    int x_set[max_level + 1], y_set[max_level + 1];
    for (i = 0; i <= max_level; i++) {
        x_set[i] = 0;
        y_set[i] = 0;
    }

    for (i = 1; i < n; i++) {
        level = x[i];
        if (level != 0) {
            x_set[level] = 1;
        }
    }

    for (i = 1; i < m; i++) {
        level = y[i];
        if (level != 0) {
            y_set[level] = 1;
        }
    }

    // Check if all levels are covered
    int all_levels_covered = 1;
    for (i = 1; i <= max_level; i++) {
        if (x_set[i] == 0 && y_set[i] == 0) {
            all_levels_covered = 0;
            break;
        }
    }

    if (all_levels_covered) {
        printf("I become the guy.\n");
    } else {
        printf("Oh, my keyboard!\n");
    }

    return 0;
}
