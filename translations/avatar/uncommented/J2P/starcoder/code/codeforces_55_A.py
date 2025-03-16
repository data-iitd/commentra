
# <START-OF-CODE>

n = int(input())
a = [0] * 1000

for i in range(1, n+1):
    for j in range(i, n+1, i):
        a[j-1] += 1

if a[n-1] == 0:
    print("NO")
else:
    print("YES")

# 