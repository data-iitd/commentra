
# Initialize a dictionary to count occurrences of integers
m = {}

# Read the number of initial integers (N) and the number of operations (M)
N, M = map(int, input().split())

# Read N integers and count their occurrences in the dictionary
for i in range(N):
    m[int(input())] = m.get(int(input()), 0) + 1

# Process M operations, where each operation adds B occurrences of integer C
for i in range(M):
    B, C = map(int, input().split())
    m[C] = m.get(C, 0) + B

# Create a list to hold the unique integers from the dictionary
ints = list(m.keys())

# Sort the integers in descending order
ints.sort(reverse=True)

# Initialize variables to keep track of remaining integers and the total sum
rest = N
sum = 0

# Calculate the maximum sum based on the sorted integers
for i in ints:
    num = m[i]
    # If the number of occurrences is greater than or equal to the remaining count
    if num >= rest:
        sum += rest * i # Add the product of remaining count and the integer
        break # Exit the loop as we have used all remaining integers
    sum += num * i # Add the product of occurrences and the integer to the sum
    rest -= num # Decrease the remaining count by the number of occurrences

# Output the final calculated sum
print(sum)

