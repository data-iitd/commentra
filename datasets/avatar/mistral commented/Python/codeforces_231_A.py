# Take an integer 'n' as input from the user
n = int(input())

# Initialize a counter 'c' to 0
c = 0

# Iterate through the range of 'n'
for i in range(n):
    # Take 'n' lists of integers as input from the user
    l1 = list(map(int, input().split()))
    
    # Check if the sum of the elements in the current list is greater than 1
    if sum(l1) > 1:
        # Increment the counter 'c' by 1 if the condition is true
        c += 1

# Print the value of the counter 'c'
print(c)
