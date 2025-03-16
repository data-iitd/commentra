# Take the number of pairs as input
n = int(input())

# Initialize an empty list to store the pairs
ls = []

# Read pairs from the user input and convert them to lists of integers
# Append each pair to the list
for i in range(n):
    pair = list(map(int, input().split()))
    ls.append(pair)

# Sort the list based on the sum of the pair elements in descending order
ls = sorted(ls, key=lambda x: sum(x), reverse=True)

# Calculate the sum of the first elements of each pair in the sorted list
taka = sum([ls[i][0] for i in range(0, len(ls), 2)])

# Calculate the sum of the second elements of each pair in the sorted list
aoki = sum([ls[i][1] for i in range(1, len(ls), 2)])

# Print the difference between the sums of the first and second elements of the pairs
print(taka - aoki)
