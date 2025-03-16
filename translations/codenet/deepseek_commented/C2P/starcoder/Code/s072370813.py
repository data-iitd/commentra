
# <START-OF-CODE>

# Declare a function to read the input and return the number of elements
def read_input():
    N = int(input())
    return N

# Declare a function to read the elements of the array A
def read_array(N):
    A = []
    for i in range(N):
        A.append(int(input()))
    return A

# Declare a function to calculate the sum and the weighted sum
def calculate_sum(A, N):
    sum = 0
    wa = 0
    for i in range(N):
        sum += A[i]
        wa += i+1
    return sum, wa

# Declare a function to calculate the quotient
def calculate_quotient(sum, wa):
    shou = sum/wa
    return shou

# Declare a function to calculate the differences between consecutive elements
def calculate_sa(A, N, shou):
    sa = []
    for i in range(N):
        sa.append(A[(i+1)%N] - A[i] - shou)
    return sa

# Declare a function to check if the differences are less than or equal to 0 and divisible by N
def check_sa(sa, N):
    for i in range(N-1):
        if( sa[i] <= 0 and not(sa[i] % N) ):
            return True
    return False

# Declare a function to print the result
def print_result(ans):
    if( ans ):
        print("YES")
    else:
        print("NO")

# Read the number of elements
N = read_input()

# Read the elements of the array A
A = read_array(N)

# Calculate the sum and the weighted sum
sum, wa = calculate_sum(A, N)

# Check if the sum is divisible by wa
if( sum % wa ):
    ans = False
else:
    # Calculate the quotient
    shou = calculate_quotient(sum, wa)
    # Calculate the differences between consecutive elements
    sa = calculate_sa(A, N, shou)
    # Check if the differences are less than or equal to 0 and divisible by N
    ans = check_sa(sa, N)

# Print the result
print_result(ans)

# 