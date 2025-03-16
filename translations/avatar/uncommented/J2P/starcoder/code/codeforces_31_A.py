
# <START-OF-CODE>
n = int(input())
a = [int(x) for x in input().split()]

for k in range(n):
    t = a[k]
    for i in range(n):
        for j in range(n-1):
            if i!= j and t == (a[i] + a[j]):
                print(k+1, j+1, i+1)
                break
        if j!= n-1:
            break
    if j!= n-1:
        break
else:
    print(-1)
# 