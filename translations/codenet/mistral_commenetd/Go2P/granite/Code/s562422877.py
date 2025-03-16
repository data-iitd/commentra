

# Initialize variables and read input
# Code for A - Initialize variables and read input
N = int(input("Enter the number of elements in the array: "))
A = list(map(int, input("Enter the elements of the array: ").split()))

# Sort the array in ascending order
# Code for C - Sort the array
A.sort()

# Calculate the answer
# Code for D - Calculate the answer
ans = 0
for i in range(1, N):
    ans += A[i] - A[i-1]

# Print the answer
# Code for E - Print the answer
print("The answer is:", ans)

