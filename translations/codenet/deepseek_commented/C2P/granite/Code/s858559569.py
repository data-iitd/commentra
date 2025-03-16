
import sys
sys.setrecursionlimit(10000)

N = 4

def Heu(Q):
    i, j, sum = 0, 0, 0
    for i in range(N):
        for j in range(N):
            if Q[i][j] == 0:
                continue
            hx = (Q[i][j] - 1) % N - j
            hy = (Q[i][j] - 1) // N - i
            if hx < 0:
                sum -= hx
            else:
                sum += hx
            if hy < 0:
                sum -= hy
            else:
                sum += hy
    return sum

def dfs(x, y, max, count, n):
    i, temp, x0, y0, ans = 0, 0, 0, 0, -1
    h = Heu(Q)
    if h == 0:
        return count
    if (count + h) > max:
        return -1
    for i in range(4):
        x0 = x + dx[i]
        y0 = y + dy[i]
        if ((i == (n + 2) % 4) and (n!= -1)) or not (0 <= x0 < N and 0 <= y0 < N):
            continue
        temp = Q[y][x]
        Q[y][x] = Q[y0][x0]
        Q[y0][x0] = temp
        ans = dfs(x0, y0, max, count + 1, i)
        if ans!= -1:
            return ans
        temp = Q[y][x]
        Q[y][x] = Q[y0][x0]
        Q[y0][x0] = temp
    return -1

if __name__ == "__main__":
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    Q = []
    for i in range(N):
        Q.append([0] * N)
    for i in range(N):
        for j in range(N):
            a = int(input())
            Q[i][j] = a
            if a == 0:
                kx = j
                ky = i
    tQ = Q
    for i in range(1, 46):
        Q = tQ
        ans = dfs(kx, ky, i, 0, -1)
        if ans!= -1:
            print(ans)
            break

