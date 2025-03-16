
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Inf 1 << 60

typedef struct {
    int cost, id;
} State;

typedef struct {
    State *data;
    int size;
} Heap;

void initDist(int H, int W, int K, int x1, int y1, int x2, int y2) {
    dist = (int *)malloc(sizeof(int) * W * H * 4);
    for (int i = 0; i < W * H * 4; i++) {
        dist[i] = Inf;
    }
    for (int i = 0; i < 4; i++) {
        q.push((State){0, toID(x1, y1, i)});
    }
}

void processHeap() {
    while (q.size > 0) {
        State now = q.pop();
        int x = now.id % W, y = now.id / W, dir = now.id % 4;
        if (x == x2 && y == y2) {
            break;
        }
        if (dist[now.id] <= now.cost) {
            continue;
        }
        dist[now.id] = now.cost;
        for (int i = 0; i < 4; i++) {
            int nCost = now.cost + K;
            int nID = toID(x, y, i);
            if (dist[nID] <= nCost) {
                continue;
            }
            q.push((State){nCost, nID});
        }
        int nx = x + dx[dir], ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            int nCost = now.cost + 1;
            int nID = toID(nx, ny, dir);
            if (dist[nID] <= nCost) {
                continue;
            }
            q.push((State){nCost, nID});
        }
    }
}

int calculateAnswer() {
    int ans = Inf;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i);
        if (dist[id] < ans) {
            ans = dist[id];
        }
    }
    return ans;
}

void printResult() {
    if (ans < Inf) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }
}

int main() {
    int H, W, K, x1, y1, x2, y2;
    scanf("%d %d %d", &H, &W, &K);
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x1--, y1--, x2--, y2--;
    char **c = (char **)malloc(sizeof(char *) * H);
    for (int i = 0; i < H; i++) {
        c[i] = (char *)malloc(sizeof(char) * W);
        scanf("%s", c[i]);
    }
    initDist(H, W, K, x1, y1, x2, y2);
    processHeap();
    int ans = calculateAnswer();
    printResult();
    return 0;
}

