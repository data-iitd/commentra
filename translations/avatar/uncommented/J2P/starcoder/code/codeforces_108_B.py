
# <START-OF-CODE>
n = int(input())
a = [int(x) for x in input().split()]
a.sort()
for i in range(n-1):
    if a[i+1] < a[i]*2 and a[i]!= a[i+1]:
        print("YES")
        break
else:
    print("NO")
# 