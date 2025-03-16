import sys

# Read input
N, D, X = map(int, input().split())

# Initialize array A to store the number of chocolate pieces for each day
A = [int(input()) for _ in range(N)]

# Calculate the total number of chocolate pieces
num_of_chocolate = 0
for i in range(N):
    # Initialize variables for inner loop
    days = 0
    counter = 0

    # Calculate the number of days this chocolate piece lasts
    j = 0
    while True:
        days = j * A[i] + 1  # Calculate the number of days
        if days <= D:  # Check if the number of days is less than or equal to the maximum number of days
            counter += 1  # Increment the counter
        else:  # If the number of days is greater than the maximum number of days, break the loop
            break
        j += 1

    # Add the number of chocolate pieces eaten in this day to the total number of chocolate pieces
    num_of_chocolate += counter

# Add the extra chocolate
num_of_chocolate += X

# Output the result
print(num_of_chocolate)
