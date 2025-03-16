
n = int(input())
a = [[0 for _ in range(n)] for _ in range(2)]
for i in range(2):
    a[i] = list(map(int, input().split()))

def find_ans(i, j, sum):
    if i == 1 and j == n - 1 and sum + a[i][j] > ans:
        global ans
        ans = sum + a[i][j]
        return
    if i == 0:
        find_ans(i + 1, j, sum + a[i][j])
    if j + 1 < n:
        find_ans(i, j + 1, sum + a[i][j])

ans = 0
find_ans(0, 0, 0)
print(ans)
