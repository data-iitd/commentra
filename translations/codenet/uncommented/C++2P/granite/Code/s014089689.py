
n = int(input())
s = input()
cnt = 0
for i in range(n):
    cnt += 1
    j = i + 1
    while j < n and s[i] == s[j]:
        j += 1
    i = j - 1
print(cnt)

