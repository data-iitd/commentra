
n = int(input())
ans = list(map(int, input().split()))
ans.sort()
count = ans[-1]
for i in range(n-2, -1, -1):
    if ans[i] < ans[i+1]:
        count += ans[i]
    else:
        while ans[i] >= ans[i+1]:
            ans[i] -= 1
        if ans[i] > 0:
            count += ans[i]
print(count)
