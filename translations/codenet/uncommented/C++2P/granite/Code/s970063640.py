
n = int(input())
a = int(input())
sum = 0
s = list(map(int, input().split()))
s.sort(reverse=True)
for i in range(n-a):
    sum += s[i]
print(sum)
