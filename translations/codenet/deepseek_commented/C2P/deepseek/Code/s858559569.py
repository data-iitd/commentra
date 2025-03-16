N = 4

class Pazz:
    def __init__(self, P):
        self.P = P

def Heu(Q):
    sum = 0
    for i in range(N):
        for j in range(N):
            if Q.P[i][j] == 0:
                continue
            hx = (Q.P[i][j] - 1) % N - j
            hy = (Q.P[i][j] - 1) // N - i
            sum += abs(hx) if hx >= 0 else -hx
            sum += abs(hy) if hy >= 0 else -hy
    return sum

def dfs(x, y, max_depth, count, n):
    h = Heu(Q)
    if h == 0:
        return count
    if count + h > max_depth:
        return -1

    for i in range(4):
        x0 = x + dx[i]
        y0 = y + dy[i]
        if ((i == (n + 2) % 4) and (n != -1)) or not (0 <= x0 < N and 0 <= y0 < N):
            continue
        temp = Q.P[y][x]
        Q.P[y][x] = Q.P[y0][x0]
        Q.P[y0][x0] = temp

        ans = dfs(x0, y0, max_depth, count + 1, i)
        if ans != -1:
            return ans
        temp = Q.P[y][x]
        Q.P[y][x] = Q.P[y0][x0]
        Q.P[y0][x0] = temp

    return -1

def main():
    global Q
    Q = Pazz([[0] * N for _ in range(N)])
    kx, ky = -1, -1

    for i in range(N):
        for j in range(N):
            a = int(input())
            Q.P[i][j] = a
            if a == 0:
                kx, ky = j, i

    tP = Pazz(Q.P)
    for i in range(1, 46):
        Q = tP
        ans = dfs(kx, ky, i, 0, -1)
        if ans != -1:
            print(ans)
            break

if __name__ == "__main__":
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    main()
