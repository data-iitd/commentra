# Read the values of n and m from input, where n is the range of numbers and m is the number of pairs
n, m = list(map(int, input().split()))

# Initialize two empty lists to store the pairs
a = []
b = []

# Loop to read m pairs of integers from input
for i in range(m):
    a1, b1 = list(map(int, input().split()))  # Read a pair of integers
    a.append(a1)  # Append the first integer of the pair to list a
    b.append(b1)  # Append the second integer of the pair to list b

# Loop through each number from 1 to n
for i in range(1, n + 1):
    # Count occurrences of the current number in both lists a and b, and print the total count
    print(a.count(i) + b.count(i))
