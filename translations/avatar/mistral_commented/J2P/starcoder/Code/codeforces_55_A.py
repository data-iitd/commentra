
import sys

n = int(input())

a = [0]*1000

for i in range(1,n+1):
    for j in range(i,n+1,i):
        a[j-1]+=1

flag = True

for i in range(n):
    if a[i] == 0:
        flag = False
        break

if flag:
    print("YES")
else:
    print("NO")

#