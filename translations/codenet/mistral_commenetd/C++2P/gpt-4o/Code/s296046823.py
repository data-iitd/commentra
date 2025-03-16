# Initialize variables N and K with user input
N, K = map(int, input().split())

# Create a list 'v' of size N to store the input integers
v = [0] * N

# Read N integers from the user and store them in the list 'v'
for i in range(N):
    v[i] = int(input())

# Calculate the number of subarrays of size K that can be formed from the list 'v'
count = ((N - 1) + ((K - 1) - 1)) // (K - 1)

# Output the result to the console
print(count)

# <END-OF-CODE>
