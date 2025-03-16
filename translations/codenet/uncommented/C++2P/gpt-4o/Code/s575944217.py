n = int(input())
ans = [0] * n
for _ in range(n - 1):
    a = int(input()) - 1
    ans[a] += 1
for count in ans:
    print(count)
# <END-OF-CODE>
