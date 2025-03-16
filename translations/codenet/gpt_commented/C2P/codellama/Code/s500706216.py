#include <stdbool.h>
#include <stdio.h>

# Declare arrays and typedef for long long
a = [0] * 200000
tmpa = [0] * 200000
light = [0] * 200010

# Define a function to calculate the influence range for each element in 'a'
def calculate_influence_range(a, light, n):
    for i in range(n):
        r = i - a[i] # Calculate the left boundary
        l = i + a[i] # Calculate the right boundary
        light[(r < 0 ? 0 : r)] += 1 # Increment the start of the influence range
        light[(l + 1 > n ? n + 1 : l + 1)] -= 1 # Decrement the end of the influence range

# Define a function to update the array 'a' based on the current influence ranges
def update_a(a, tmpa, light, n):
    sum = 0
    for j in range(n):
        tmpa[j] = a[j] # Store the current state of 'a' in 'tmpa'
        sum += light[j] # Accumulate the influence
        a[j] = sum # Update 'a' with the accumulated influence

# Define a function to update the influence ranges based on the new values in 'a'
def update_influence_range(a, tmpa, light, n):
    for j in range(n):
        r = j - tmpa[j] # Calculate the left boundary for the previous state
        l = j + tmpa[j] # Calculate the right boundary for the previous state
        light[(r < 0 ? 0 : r)] -= 1 # Decrement the start of the previous influence range
        light[(l + 1 > n ? n + 1 : l + 1)] += 1 # Increment the end of the previous influence range

        r = j - a[j] # Calculate the new left boundary
        l = j + a[j] # Calculate the new right boundary
        light[(r < 0 ? 0 : r)] += 1 # Increment the start of the new influence range
        light[(l + 1 > n ? n + 1 : l + 1)] -= 1 # Decrement the end of the new influence range

# Define a function to check if all elements in 'a' are the same and equal to n
def check_if_same(a, n):
    for j in range(n - 1):
        if a[j] != a[j + 1]:
            return False # Return false if any elements differ
    return True # Return true if all elements are the same and equal to n

# Read the number of elements (n) and the number of iterations (k)
n, k = map(int, input().split())

# Input the initial values into the array 'a'
for i in range(n):
    a[i] = int(input())

# Calculate the influence range for each element in 'a'
calculate_influence_range(a, light, n)

# Perform k iterations to update the array 'a'
for i in range(k):
    # Update 'a' based on the current influence ranges
    update_a(a, tmpa, light, n)

    # Update the influence ranges based on the new values in 'a'
    update_influence_range(a, tmpa, light, n)

    # Check if all elements in 'a' are the same and equal to n
    if check_if_same(a, n) and a[0] == n:
        break

# Output the final state of the array 'a'
for j in range(n):
    print(a[j], end=" ") # Print each element of 'a'
print() # Print a newline after the last element

