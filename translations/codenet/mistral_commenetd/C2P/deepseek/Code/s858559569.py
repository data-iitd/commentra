N = 4

# Define a class Pazz to hold a 2D array P
class Pazz:
    def __init__(self):
        self.P = [[0] * N for _ in range(N)]

# Initialize an empty Pazz structure Q
Q = Pazz()

# Define the possible moves in x and y direction
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

# Function to calculate the heuristic value of the given Pazz structure Q
def Heu(Q):
    sum = 0
    for i in range(N):
        for j in range(N):
            if Q.P[i][j] == 0:
                continue
            hx = (Q.P[i][j] - 1) % N - j
            hy = (Q.P[i][j] - 1) // N - i
            if hx < 0:
                sum -= hx
            else:
                sum += hx
            if hy < 0:
                sum -= hy
            else:
                sum += hy
    return sum

# Recursive function to find the solution using Depth First Search algorithm
def dfs(x, y, max, count, n):
    h = Heu(Q)
    if h == 0:
        return count
    if (count + h) > max:
        return -1
    for i in range(4):
        x0 = x + dx[i]
        y0 = y + dy[i]
        if (((i == (n + 2) % 4) and (n != -1)) or not (0 <= x0 < N and 0 <= y0 < N)):
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

# Main function to read the input and call the function dfs to find the solution
def main():
    kx, ky = -1, -1
    for i in range(N):
        for j in range(N):
            a = int(input())
            Q.P[i][j] = a
            if a == 0:
                kx, ky = j, i
    ans = dfs(kx, ky, 46, 0, -1)
    if ans != -1:
        print(ans)
        exit(0)
    print("No solution found")
    exit(1)

main()
