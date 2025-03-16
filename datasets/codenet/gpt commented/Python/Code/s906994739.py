# Read the number of time slots (n)
n = int(input())

# Read the F matrix, which contains the values for each time slot for n different entities
F = [tuple(map(int, input().split())) for _ in range(n)]

# Read the P matrix, which contains the profit values based on the number of time slots opened for n different entities
P = [tuple(map(int, input().split())) for _ in range(n)]

# Initialize the answer variable to a very small number
ans = -10 ** 18

# Iterate over all possible combinations of opening time slots (from 1 to 2^10 - 1)
for i in range(1, 2**10):
    # Temporary variable to store the total profit for the current combination
    tmp = 0
    
    # List to keep track of how many time slots are opened for each entity
    lst = [0] * n
    
    # Iterate over each time slot (0 to 9)
    for j in range(10):  # time slots
        # Check if the j-th time slot is included in the current combination
        if (i >> j) & 1:  # if the j-th bit of i is set
            # Update the count of opened time slots for each entity
            for k in range(n):
                lst[k] += F[k][j]
    
    # Calculate the total profit for the current combination of opened time slots
    for k in range(n):
        tmp += P[k][lst[k]]
    
    # Update the maximum profit found so far
    ans = max(ans, tmp)

# Print the maximum profit
print(ans)
