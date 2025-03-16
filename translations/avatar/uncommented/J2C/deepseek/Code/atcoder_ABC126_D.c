#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point {
    int name;
    struct Point** friends;
    int friends_count;
    int* lengths;
} Point;

void become_friend(Point* p, Point* friend, int length) {
    p->friends_count++;
    p->friends = (Point**)realloc(p->friends, p->friends_count * sizeof(Point*));
    p->lengths = (int*)realloc(p->lengths, p->friends_count * sizeof(int));
    p->friends[p->friends_count - 1] = friend;
    p->lengths[p->friends_count - 1] = length;
}

void dfs(Point* p, int length, int* colors, int n) {
    if (colors[p->name] != -1) return;
    if (length % 2 == 0) {
        colors[p->name] = 0;
    } else {
        colors[p->name] = 1;
    }
    for (int i = 0; i < p->friends_count; i++) {
        dfs(p->friends[i], length + p->lengths[i], colors, n);
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    m = n - 1;
    int colors[n];
    memset(colors, -1, n * sizeof(int));
    Point* points = (Point*)malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        points[i].name = i;
        points[i].friends = NULL;
        points[i].friends_count = 0;
        points[i].lengths = NULL;
    }
    while (m-- > 0) {
        int me, you, length;
        scanf("%d %d %d", &me, &you, &length);
        me--;
        you--;
        become_friend(&points[me], &points[you], length);
        become_friend(&points[you], &points[me], length);
    }
    dfs(&points[0], 0, colors, n);
    for (int i = 0; i < n; i++) {
        printf("%d\n", colors[i]);
    }
    free(points);
    return 0;
}
