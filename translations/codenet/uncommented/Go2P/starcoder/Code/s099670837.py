n = int(input())
a = [[0 for i in range(n)] for j in range(2)]
for i in range(2):
    for j in range(n):
        a[i][j] = int(input())

ans = 0

def findAns(i, j, sum):
    global ans
    if i == 1 and j == n-1 and sum+a[i][j] > ans:
        ans = sum + a[i][j]
        return
    if i == 0:
        findAns(i+1, j, sum+a[i][j])
    if j+1 < n:
        findAns(i, j+1, sum+a[i][j])

findAns(0, 0, 0)
print(ans)

