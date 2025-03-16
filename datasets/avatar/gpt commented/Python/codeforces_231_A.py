# Read an integer input which represents the number of lists to process
n = int(input())

# Initialize a counter to keep track of lists with a sum greater than 1
c = 0

# Loop through the range of n to process each list
for i in range(n):
    # Read a line of input, split it into individual string elements, convert them to integers, and store them in a list
    l1 = list(map(int, input().split()))
    
    # Check if the sum of the current list is greater than 1
    if sum(l1) > 1:
        # Increment the counter if the condition is met
        c = c + 1

# Print the final count of lists that had a sum greater than 1
print(c)
