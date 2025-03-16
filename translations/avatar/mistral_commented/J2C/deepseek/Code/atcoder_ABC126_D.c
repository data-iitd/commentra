#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Point {
    int name;
    struct Point** friends;
    int* friend_lengths;
    int friend_count;
} Point;

int colors[1000];

void dfs(Point* p, int length) {
    bool alreadyKnown = colors[p->name] != -1;
    if (alreadyKnown) return;

    if (length % 2 == 0) {
        colors[p->name] = 0;
    } else {
        colors[p->name] = 1;
    }

    for (int i = 0; i < p->friend_count; i++) {
        Point* friend = p->friends[i];
        int length2 = p->friend_lengths[i];
        dfs(friend, length + length2);
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    m = n - 1;

    Point* points[n];
    for (int i = 0; i < n; i++) {
        points[i] = (Point*)malloc(sizeof(Point));
        points[i]->name = i;
        points[i]->friends = (Point**)malloc(n * sizeof(Point*));
        points[i]->friend_lengths = (int*)malloc(n * sizeof(int));
        points[i]->friend_count = 0;
    }

    for (int i = 0; i < m; i++) {
        int me, you, length;
        scanf("%d %d %d", &me, &you, &length);
        me--; you--;

        points[me]->friends[points[me]->friend_count] = points[you];
        points[me]->friend_lengths[points[me]->friend_count] = length;
        points[me]->friend_count++;

        points[you]->friends[points[you]->friend_count] = points[me];
        points[you]->friend_lengths[points[you]->friend_count] = length;
        points[you]->friend_count++;
    }

    for (int i = 0; i < n; i++) {
        colors[i] = -1;
    }

    dfs(points[0], 0);

    for (int i = 0; i < n; i++) {
        printf("%d\n", colors[i]);
    }

    for (int i = 0; i < n; i++) {
        free(points[i]->friends);
        free(points[i]->friend_lengths);
        free(points[i]);
    }

    return 0;
}

