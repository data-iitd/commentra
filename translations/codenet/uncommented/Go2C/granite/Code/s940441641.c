
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Inf 1000000000

typedef struct {
    int cost, id;
} State;

typedef struct {
    State *data;
    int size;
} Heap;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int toID(int x, int y, int dir) {
    return 4 * (y * W + x) + dir;
}

void splatID(int id, int *x, int *y, int *dir) {
    *x = id / 4 % W;
    *y = id / 4 / W;
    *dir = id % 4;
}

int main() {
    int H, W, K;
    scanf("%d %d %d", &H, &W, &K);
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x1--, y1--, x2--, y2--;
    char c[H][W];
    for (int y = 0; y < H; y++) {
        scanf("%s", c[y]);
    }

    int dist[H][W][4];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < 4; k++) {
                dist[i][j][k] = Inf;
            }
        }
    }

    Heap q;
    q.data = (State *)malloc(sizeof(State) * (H * W * 4));
    q.size = 0;
    for (int i = 0; i < 4; i++) {
        q.data[q.size++] = (State){0, toID(x1, y1, i)};
    }
    while (q.size > 0) {
        State now = q.data[--q.size];
        int x, y, dir;
        splatID(now.id, &x, &y, &dir);
        if (c[y][x] == '@') {
            continue;
        }
        if (dist[y][x][dir] <= now.cost) {
            continue;
        }
        dist[y][x][dir] = now.cost;
        if (x == x2 && y == y2) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            State next = (State){(now.cost + K - 1) / K * K, toID(x, y, i)};
            if (dist[next.id / 4 / W][next.id / 4 % W][next.id % 4] > next.cost) {
                q.data[q.size++] = next;
            }
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            State next = (State){now.cost + 1, toID(nx, ny, dir)};
            if (dist[next.id / 4 / W][next.id / 4 % W][next.id % 4] > next.cost) {
                q.data[q.size++] = next;
            }
        }
    }
    int ans = Inf;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i);
        if (dist[id / 4 / W][id / 4 % W][id % 4] < ans) {
            int d2 = (dist[id / 4 / W][id / 4 % W][id % 4] + K - 1) / K;
            if (d2 < ans) {
                ans = d2;
            }
        }
    }
    if (ans < Inf) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }
    return 0;
}

