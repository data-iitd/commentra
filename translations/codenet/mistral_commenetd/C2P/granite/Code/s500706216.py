
import sys

# Read input n and k
n, k = map(int, input().split())

# Read input array a
a = list(map(int, input().split()))

# Initialize light array based on initial a array
light = [0] * (n + 1)
for i in range(n):
    r = i - a[i]
    l = i + a[i]
    light[r if r >= 0 else 0] += 1
    light[l + 1 if l + 1 <= n else n + 1] -= 1

# Perform k iterations
for _ in range(k):
    # Initialize temporary array tmpa
    tmpa = a[:]
    sum = 0
    for j in range(n):
        sum += light[j]
        tmpa[j] = sum

    # Update light array based on new a array
    light = [0] * (n + 1)
    for j in range(n):
        r = j - tmpa[j]
        l = j + tmpa[j]
        light[r if r >= 0 else 0] -= 1
        light[l + 1 if l + 1 <= n else n + 1] += 1
        r = j - tmpa[j]
        l = j + tmpa[j]
        light[r if r >= 0 else 0] += 1
        light[l + 1 if l + 1 <= n else n + 1] -= 1

    # Check if a array is the same for all elements except the first one, and if the first element is equal to the size of the array
    isSame = all(a[i] == a[i + 1] for i in range(n - 1)) and a[0] == n
    if isSame:
        break

# Print out updated a array
print(*a)

