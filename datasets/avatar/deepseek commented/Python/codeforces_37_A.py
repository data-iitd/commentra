
n = int(input())  # Read the number of elements
l = list(map(int, input().split()))  # Read the list of elements

# Initialize variables
high = 1
tower = n
maximum = 1

# Sort the list
l.sort()

# Loop through the sorted list
for i in range(1, n):
    if l[i] == l[i - 1]:  # Check if the current element is equal to the previous element
        tower -= 1  # Decrement the tower count
        high += 1  # Increment the high count
    else:
        if high > maximum:  # Check if the current high is greater than the maximum
            maximum = high  # Update the maximum
        high = 1  # Reset high to 1

if high > maximum:  # Check if the final high is greater than the maximum
    maximum = high  # Update the maximum

# Print the result
print(maximum, tower)

