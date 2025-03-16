
n = int(input())
S = [int(x) for x in input().split()]
q = int(input())
T = [int(x) for x in input().split()]

c = 0
for t in T:
    if t in S:
        c += 1

print(c)

