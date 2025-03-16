# Declare arrays and import necessary modules
a = [0] * 200000
tmpa = [0] * 200000
light = [0] * 200010

# Read the number of elements (n) and the number of iterations (k)
n, k = map(int, input().split())

# Input the initial values into the array 'a'
for i in range(n):
    a[i] = int(input())

# Calculate the influence range for each element in 'a'
for i in range(n):
    r = i - a[i]  # Calculate the left boundary
    l = i + a[i]  # Calculate the right boundary
    light[max(0, r)] += 1  # Increment the start of the influence range
    if l + 1 <= n:
        light[l + 1] -= 1  # Decrement the end of the influence range

# Perform k iterations to update the array 'a'
for _ in range(k):
    sum_influence = 0

    # Update 'a' based on the current influence ranges
    for j in range(n):
        tmpa[j] = a[j]  # Store the current state of 'a' in 'tmpa'
        sum_influence += light[j]  # Accumulate the influence
        a[j] = sum_influence  # Update 'a' with the accumulated influence

    # Update the influence ranges based on the new values in 'a'
    for j in range(n):
        r = j - tmpa[j]  # Calculate the left boundary for the previous state
        l = j + tmpa[j]  # Calculate the right boundary for the previous state
        light[max(0, r)] -= 1  # Decrement the start of the previous influence range
        if l + 1 <= n:
            light[l + 1] += 1  # Increment the end of the previous influence range

        r = j - a[j]  # Calculate the new left boundary
        l = j + a[j]  # Calculate the new right boundary
        light[max(0, r)] += 1  # Increment the start of the new influence range
        if l + 1 <= n:
            light[l + 1] -= 1  # Decrement the end of the new influence range

    # Check if all elements in 'a' are the same and equal to n
    is_same = all(a[j] == a[0] for j in range(n))
    # If all elements are the same and equal to n, exit the loop
    if is_same and a[0] == n:
        break

# Output the final state of the array 'a'
print(" ".join(map(str, a)))  # Print each element of 'a' in a single line
# <END-OF-CODE>
