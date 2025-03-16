
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int cost;
    int id;
} State;

typedef struct {
    State *data;
    int size;
    int capacity;
} Heap;

int compareStates(const void *a, const void *b) {
    State *sa = (State *)a;
    State *sb = (State *)b;
    return sa->cost - sb->cost;
}

void initHeap(Heap *h) {
    h->data = (State *)malloc(sizeof(State) * 100000);
    h->size = 0;
    h->capacity = 100000;
}

void pushHeap(Heap *h, State s) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->data = (State *)realloc(h->data, sizeof(State) * h->capacity);
    }
    h->data[h->size++] = s;
    int i = h->size - 1;
    while (i > 0 && compareStates(&h->data[i], &h->data[(i - 1) / 2]) < 0) {
        State temp = h->data[i];
        h->data[i] = h->data[(i - 1) / 2];
        h->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

State popHeap(Heap *h) {
    if (h->size == 0) {
        printf("Heap is empty\n");
        exit(1);
    }
    State s = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (2 * i + 1 < h->size) {
        int j = 2 * i + 1;
        if (j + 1 < h->size && compareStates(&h->data[j], &h->data[j + 1]) < 0) {
            j++;
        }
        if (compareStates(&h->data[i], &h->data[j]) < 0) {
            State temp = h->data[i];
            h->data[i] = h->data[j];
            h->data[j] = temp;
            i = j;
        } else {
            break;
        }
    }
    return s;
}

int main() {
    int H, W, K;
    scanf("%d %d %d", &H, &W, &K);
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x1--, y1--;
    x2--, y2--;
    char c[H][W];
    for (int i = 0; i < H; i++) {
        scanf("%s", c[i]);
    }
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int dist[H][W][4];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < 4; k++) {
                dist[i][j][k] = 100000000;
            }
        }
    }
    Heap h;
    initHeap(&h);
    for (int i = 0; i < 4; i++) {
        pushHeap(&h, (State){0, i * W * H + x1 * W + y1});
    }
    while (h.size > 0) {
        State s = popHeap(&h);
        int x = s.id % W;
        int y = (s.id % (W * H)) / W;
        int dir = s.id / (W * H);
        if (c[y][x] == '@') {
            continue;
        }
        if (dist[y][x][dir] <= s.cost) {
            continue;
        }
        dist[y][x][dir] = s.cost;
        if (x == x2 && y == y2) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nCost = (s.cost + K - 1) / K * K;
            int nID = i * W * H + x * W + y;
            if (dist[y][x][i] <= nCost) {
                continue;
            }
            pushHeap(&h, (State){nCost, nID});
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            int nCost = s.cost + 1;
            int nID = dir * W * H + nx * W + ny;
            if (dist[ny][nx][dir] <= nCost) {
                continue;
            }
            pushHeap(&h, (State){nCost, nID});
        }
    }
    int ans = 100000000;
    for (int i = 0; i < 4; i++) {
        int id = i * W * H + x2 * W + y2;
        if (dist[y2][x2][i] < ans) {
            int d2 = (dist[y2][x2][i] + K - 1) / K;
            if (d2 < ans) {
                ans = d2;
            }
        }
    }
    if (ans < 100000000) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }
    return 0;
}
