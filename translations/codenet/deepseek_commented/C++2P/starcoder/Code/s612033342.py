
h, w, k = map(int, input().split())
hw = [[0] * w for _ in range(h)]
for i in range(h):
    for j in range(w):
        hw[i][j] = int(input())

sum = 0
for i in range(pow(2, h)):
    for j in range(pow(2, w)):
        if count(hw, i, j) == k:
            sum += 1

print(sum)

