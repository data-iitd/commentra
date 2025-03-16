# Read an integer value from the standard input and store it in N
N = int(input())  
# Declare an integer array named A with a size of N+1
A = list(map(int, input().split()))[:N+1]  
# Declare an integer array named B with a size of N
B = list(map(int, input().split()))[:N]  

# Initialize a variable named ans to 0
ans = 0  

# Nested for loop to compare each pair of elements from arrays A and B
for i in range(N):
    # site i
    if A[i] >= B[i]:
        ans += B[i]  # Add the smaller element to the answer
        A[i] -= B[i]  # Subtract the smaller element from the corresponding element in array A
        B[i] = 0  # Set the smaller element in array B to 0
    else:
        ans += A[i]  # Add the smaller element to the answer
        B[i] -= A[i]  # Subtract the smaller element from the corresponding element in array B
        A[i] = 0  # Set the smaller element in array A to 0

    # site i + 1
    if A[i + 1] >= B[i]:
        ans += B[i]  # Add the smaller element to the answer
        A[i + 1] -= B[i]  # Subtract the smaller element from the corresponding element in array A
        B[i] = 0  # Set the smaller element in array B to 0
    else:
        ans += A[i + 1]  # Add the smaller element to the answer
        B[i] -= A[i + 1]  # Subtract the smaller element from the corresponding element in array B
        A[i + 1] = 0  # Set the smaller element in array A to 0

# Print the final answer
print(ans)  # Print the value of the answer variable

# Return 0 to indicate the successful execution of the program
# In Python, we don't need to return from main
# <END-OF-CODE>
