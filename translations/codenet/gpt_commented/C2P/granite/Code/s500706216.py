
import sys

# Read the number of elements (n) and the number of iterations (k)
n, k = map(int, input().split())

# Input the initial values into the array 'a'
a = list(map(int, input().split()))

# Calculate the influence range for each element in 'a'
light = [0] * (n + 1)
for i in range(n):
    r = i - a[i]
    l = i + a[i]
    light[r if r >= 0 else 0] += 1
    light[l + 1 if l + 1 <= n else n + 1] -= 1

# Perform k iterations to update the array 'a'
for _ in range(k):
    tmpa = a[:]
    sum = 0
    for j in range(n):
        sum += light[j]
        a[j] = sum
    for j in range(n):
        r = j - tmpa[j]
        l = j + tmpa[j]
        light[r if r >= 0 else 0] -= 1
        light[l + 1 if l + 1 <= n else n + 1] += 1
        r = j - a[j]
        l = j + a[j]
        light[r if r >= 0 else 0] += 1
        light[l + 1 if l + 1 <= n else n + 1] -= 1
    if all(x == a[0] == n for x in a):
        break

# Output the final state of the array 'a'
print(*a)

