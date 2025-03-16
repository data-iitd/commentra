# Initialize variables and read input
N = int(input("Enter the number of elements in the array: "))

A = []
print("Enter the elements of the array:")
for _ in range(N):
    A.append(int(input()))

# Sort the array in ascending order
A.sort()

# Calculate the answer
ans = 0
print("Calculating the answer...")
for i in range(1, N):
    ans += A[i] - A[i - 1]

# Print the answer
print("The answer is:", ans)

# <END-OF-CODE>
