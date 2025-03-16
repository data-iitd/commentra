n, ans = 0, 0

array_size = 101
a = [[0] * array_size for _ in range(array_size)]

def find_ans(i, j, sum):
    global ans
    if i == 1 and j == n - 1 and sum + a[i][j] > ans:
        ans = sum + a[i][j]
        return
    if i == 0:
        find_ans(i + 1, j, sum + a[i][j])
    if j + 1 < n:
        find_ans(i, j + 1, sum + a[i][j])

n = int(input())
for i in range(2):
    a[i] = list(map(int, input().split()))

find_ans(0, 0, 0)
print(ans)

# <END-OF-CODE>
