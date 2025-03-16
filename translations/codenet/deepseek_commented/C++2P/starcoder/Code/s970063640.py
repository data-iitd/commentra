n = int(input())
a = int(input())
s = [int(input()) for i in range(n)]
s.sort()
print(sum(s[n-a:]))

