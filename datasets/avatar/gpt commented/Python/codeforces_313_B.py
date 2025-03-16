# Read the input string from the user
soz = input()

# Initialize a list 'a' to store the cumulative count of consecutive characters
# The length of 'a' is one more than the length of 'soz' to handle the base case
a = [0] * (len(soz) + 1)

# Iterate through the string to fill the cumulative count array 'a'
for i in range(1, len(soz)):
    # Carry forward the previous count
    a[i] = a[i - 1]
    
    # If the current character is the same as the previous one, increment the count
    if soz[i - 1] == soz[i]:
        a[i] += 1

# Read the number of queries from the user
n = int(input())

# Initialize an empty list to store the results of each query
arr = []

# Process each query
for i in range(n):
    # Read the start and end indices for the query
    m, l = input().split()
    
    # Calculate the number of consecutive characters between indices m and l
    # and append the result to the 'arr' list
    arr.append(a[int(l) - 1] - a[int(m) - 1])

# Print the results for each query
for i in arr:
    print(i)
