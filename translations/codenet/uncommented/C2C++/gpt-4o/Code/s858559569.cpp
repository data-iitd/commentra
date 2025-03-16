#include <iostream>
#include <vector>
#define N 4

struct Pazz {
    int P[N][N];
};

Pazz Q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int Heu(Pazz Q) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (Q.P[i][j] == 0) continue;

            int hx = (Q.P[i][j] - 1) % N - j;
            int hy = (Q.P[i][j] - 1) / N - i;

            sum += (hx < 0) ? -hx : hx;
            sum += (hy < 0) ? -hy : hy;
        }
    }
    return sum;
}

int dfs(int x, int y, int max, int count, int n) {
    int ans = -1;
    int h = Heu(Q);

    if (h == 0) return count;
    if ((count + h) > max) return -1;

    for (int i = 0; i < 4; i++) {
        int x0 = x + dx[i];
        int y0 = y + dy[i];

        if (((i == (n + 2) % 4) && (n != -1)) || !((0 <= x0) && (x0 < N) && (0 <= y0) && (y0 < N)))) continue;

        std::swap(Q.P[y][x], Q.P[y0][x0]);

        ans = dfs(x0, y0, max, count + 1, i);

        if (ans != -1) return ans;
        std::swap(Q.P[y][x], Q.P[y0][x0]);
    }

    return -1;
}

int main() {
    int kx, ky, ans, a;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> a;
            Q.P[i][j] = a;
            if (a == 0) {
                kx = j;
                ky = i;
            }
        }
    }

    Pazz tP = Q;
    for (int i = 1; i < 46; i++) {
        Q = tP;
        ans = dfs(kx, ky, i, 0, -1);
        if (ans != -1) {
            std::cout << ans << std::endl;
            break;
        }
    }

    return 0;
}

// <END-OF-CODE>
