
import sys

n = int(raw_input())
a = [0] * n

for i in range(n):
    a[i] = int(raw_input())

k = 0
i = 0
flag = True

while k <= n:
    i += k
    if i >= n:
        while i >= n:
            i -= n
    a[i] += 1
    k += 1

for i in range(n):
    if a[i] == 0:
        flag = False
        break

if flag:
    print "YES"
else:
    print "NO"

#