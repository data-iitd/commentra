# Read input values: n (number of elements), L (left multiplier), R (right multiplier), QL (left penalty), QR (right penalty)
n, L, R, QL, QR = map(int, input().split())

# Read the list of weights W
W = list(map(int, input().split()))

# Initialize a list to store cumulative sums, starting with 0 for the base case
sum_el = [0]

# Calculate cumulative sums of the weights
for i in range(1, n + 1):
    sum_el.append(W[i - 1] + sum_el[i - 1])

# Calculate the initial answer based on the total weight and the right multiplier
answer = QR * (n - 1) + sum_el[n] * R

# Iterate through each element to find the minimum energy configuration
for i in range(1, n + 1):
    # Calculate the energy for the current configuration
    energy = L * sum_el[i] + R * (sum_el[n] - sum_el[i])
    
    # Adjust energy based on the position of the current element relative to the midpoint
    if i > (n - i):
        # If the current index is in the right half, apply left penalty
        energy += (i - (n - i) - 1) * QL
    elif (n - i) > i:
        # If the current index is in the left half, apply right penalty
        energy += ((n - i) - i - 1) * QR
    
    # Update the answer if the current energy is less than the previously recorded answer
    if energy < answer:
        answer = energy

# Print the minimum energy found
print(answer)
