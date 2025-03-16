# Read two integers n and m from input, where n is the number of elements and m is the divisor
n, m = map(int, input().split())

# Read a list of n integers from input
l = list(map(int, input().split()))

# Initialize an empty list to store the results after processing the input list
l2 = []

# Iterate through each element in the input list
for i in l:
    # If the current element is divisible by m, append the quotient to l2
    if i % m == 0:
        l2.append(i // m)
    # If the current element is not divisible by m, append the quotient plus one to l2
    else:
        l2.append(i // m + 1)

# Find the maximum value in the processed list l2
mx = max(l2)

# Iterate through the range of n to find the index of the maximum value in l2
for i in range(n):
    if l2[i] == mx:
        ind = i  # Store the index of the maximum value

# Print the index of the maximum value (1-based index)
print(ind + 1)
