#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000

typedef struct Point {
    int name;
    struct Point** friends;
    int friends_count;
    int* friend_lengths;
} Point;

int colors[MAX_NODES];

void dfs(Point* p, int length) {
    if (colors[p->name] != -1) return;

    if (length % 2 == 0) {
        colors[p->name] = 0;
    } else {
        colors[p->name] = 1;
    }

    for (int i = 0; i < p->friends_count; i++) {
        dfs(p->friends[i], length + p->friend_lengths[i]);
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    m = n - 1;
    memset(colors, -1, sizeof(colors));

    Point* points[MAX_NODES];
    for (int i = 0; i < n; i++) {
        points[i] = (Point*)malloc(sizeof(Point));
        points[i]->name = i;
        points[i]->friends_count = 0;
        points[i]->friend_lengths = (int*)malloc(MAX_NODES * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int me, you, length;
        scanf("%d %d %d", &me, &you, &length);
        me--; you--;

        points[me]->friends[points[me]->friends_count] = points[you];
        points[me]->friend_lengths[points[me]->friends_count] = length;
        points[me]->friends_count++;

        points[you]->friends[points[you]->friends_count] = points[me];
        points[you]->friend_lengths[points[you]->friends_count] = length;
        points[you]->friends_count++;
    }

    dfs(points[0], 0);

    for (int i = 0; i < n; i++) {
        printf("%d\n", colors[i]);
        free(points[i]->friends);
        free(points[i]->friend_lengths);
        free(points[i]);
    }

    return 0;
}
