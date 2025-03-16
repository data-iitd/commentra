
n = int(input())  # Take an integer input representing the threshold
m = input().split()  # Take a space-separated string input and split it into a list
possible = True  # Initialize a boolean variable to check if the condition is possible

# Iterate over the unique elements in the list `m`
for i in set(m):
    # Check if the count of the current element is greater than or equal to n / 2 + 1
    if m.count(i) >= n / 2 + 1:
        possible = False  # Set possible to False if the condition is met
        break  # Break the loop as the condition is already not possible

# Print 'YES' if possible is True, otherwise print 'NO'
print('YES' if possible else 'NO')

