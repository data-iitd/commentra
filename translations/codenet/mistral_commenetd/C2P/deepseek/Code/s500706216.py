import sys

# Read input n and k
n, k = map(int, sys.stdin.readline().split())

# Read input array a
a = list(map(int, sys.stdin.readline().split()))

# Initialize light array based on initial a array
light = [0] * (n + 2)
for i in range(n):
    r = i - a[i]
    l = i + a[i]
    light[max(0, r)] += 1
    light[min(n + 1, l + 1)] -= 1

# Perform k iterations
for _ in range(k):
    # Initialize temporary array tmpa
    tmpa = a.copy()
    sum_light = 0
    for j in range(n):
        sum_light += light[j]
        a[j] = sum_light

    # Update light array based on new a array
    for j in range(n):
        r = j - a[j]
        l = j + a[j]
        light[max(0, r)] -= 1
        light[min(n + 1, l + 1)] += 1
        light[max(0, r)] += 1
        light[min(n + 1, l + 1)] -= 1

    # Check if a array is the same for all elements except the first one, and if the first element is equal to the size of the array
    is_same = all(a[i] == a[i + 1] for i in range(n - 1))
    if is_same and a[0] == n:
        break

# Print out updated a array
print(" ".join(map(str, a)))
