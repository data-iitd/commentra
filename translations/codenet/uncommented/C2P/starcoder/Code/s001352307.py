
# <START-OF-CODE>

W, N = map(int, raw_input().split())

input = []
for i in range(N):
    input.append(map(int, raw_input().split(',')))

ans = [[0, 0] for i in range(1024)]

for i in range(N):
    for j in range(W, 0, -1):
        if ans[j][0] < input[i][0] + ans[j - input[i][1]][0]:
            ans[j][0] = input[i][0] + ans[j - input[i][1]][0]
            ans[j][1] = input[i][1] + ans[j - input[i][1]][1]

for j in range(W):
    if ans[W][0] == ans[W - j - 1][0]:
        break

print "Case %d:" % (t + 1)
print ans[W - j][0]
print ans[W - j][1]

# 