import sys

# Read input
n, k = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))

# Initialize light array
light = [0] * (n + 2)

# Process the initial light array
for i in range(n):
    r = i - a[i]
    l = i + a[i]
    light[max(0, r)] += 1
    light[min(n + 1, l + 1)] -= 1

# Apply the prefix sum to get the light array for each day
for i in range(k):
    tmpa = a.copy()
    sum_light = 0
    for j in range(n):
        sum_light += light[j]
        a[j] = sum_light
    
    # Update the light array for the next day
    for j in range(n):
        r = j - tmpa[j]
        l = j + tmpa[j]
        light[max(0, r)] -= 1
        light[min(n + 1, l + 1)] += 1
        r = j - a[j]
        l = j + a[j]
        light[max(0, r)] += 1
        light[min(n + 1, l + 1)] -= 1
    
    # Check if the array has stabilized
    if all(a[j] == a[j + 1] for j in range(n - 1)) and a[0] == n:
        break

# Output the final array
print(" ".join(map(str, a)))
