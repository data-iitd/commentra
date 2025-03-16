class Pazz:
    def __init__(self):
        self.P = [[0] * 4 for _ in range(4)]

def Heu(Q):
    sum = 0
    for i in range(4):
        for j in range(4):
            if Q.P[i][j] == 0:
                continue
            hx = (Q.P[i][j] - 1) % 4 - j
            hy = (Q.P[i][j] - 1) // 4 - i
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
    h = Heu(Q)
    if h == 0:
        return count
    if (count + h) > max:
        return -1
    for i in range(4):
        x0 = x + dx[i]
        y0 = y + dy[i]
        if ((i == (n + 2) % 4) and (n != -1)) or not (0 <= x0 < 4 and 0 <= y0 < 4):
            continue
        temp = Q.P[y][x]
        Q.P[y][x] = Q.P[y0][x0]
        Q.P[y0][x0] = temp
        ans = dfs(x0, y0, max, count + 1, i)
        if ans != -1:
            return ans
        temp = Q.P[y][x]
        Q.P[y][x] = Q.P[y0][x0]
        Q.P[y0][x0] = temp
    return -1

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

Q = Pazz()
kx, ky = -1, -1

for i in range(4):
    for j in range(4):
        a = int(input())
        Q.P[i][j] = a
        if a == 0:
            kx, ky = j, i

tP = Pazz()
for i in range(4):
    for j in range(4):
        tP.P[i][j] = Q.P[i][j]

for i in range(1, 46):
    for j in range(4):
        for k in range(4):
            Q.P[j][k] = tP.P[j][k]
    ans = dfs(kx, ky, i, 0, -1)
    if ans != -1:
        print(ans)
        break
