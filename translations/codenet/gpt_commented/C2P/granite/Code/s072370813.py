
# Read the number of elements from user input
N = int(input())

# Declare variables for iteration, sum, weighted sum, and arrays
sum = 0  # To store the total sum of elements
wa = 0   # To store the weighted sum (1 + 2 +... + N)
A = []    # List to hold the input elements
sa = []   # List to hold the adjusted differences
ans = 0   # Variable to store the final answer (0 or 1)
shou = 0  # Variable to store the average value

# Read the elements into list A and calculate the total sum and weighted sum
for i in range(N):
    A.append(int(input()))  # Read each element into the list A
    sum += A[i]               # Accumulate the sum of elements
    wa += i + 1              # Accumulate the weighted sum

# Check if the total sum is divisible by the weighted sum
if sum % wa:
    ans = 0  # If not divisible, set answer to 0 (NO)
else:
    # Calculate the average value (shou)
    shou = sum // wa

    # Calculate the adjusted differences and store them in list sa
    for i in range(N):
        sa.append(A[(i + 1) % N] - A[i] - shou)  # Adjusted difference for circular array

    # Check the conditions for the adjusted differences
    for i in range(N - 1):
        # If the adjusted difference is non-positive and divisible by N
        if sa[i] <= 0 and sa[i] % N == 0:
            ans = 1  # Set answer to 1 (YES)
        else:
            ans = 0  # If any condition fails, set answer to 0 (NO)
            break  # Exit the loop early

# Output the final result based on the answer
if ans:
    print("YES")  # Print YES if conditions are met
else:
    print("NO")   # Print NO if conditions are not met

# 