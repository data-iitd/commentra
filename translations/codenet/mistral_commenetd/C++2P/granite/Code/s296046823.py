
# Read N and K from the user
N, K = map(int, input().split())

# Read N integers from the user and store them in a list
v = list(map(int, input().split()))

# Calculate the number of subarrays of size K that can be formed from the list 'v'
count = ((N - 1) + ((K - 1) - 1)) // (K - 1)

# Output the result to the console
print(count)

