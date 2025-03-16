# Function to find the greatest common divisor (GCD) of two numbers
def gcd(a: int, b: int) -> int:
    # Base case: if b is 0, return a as the GCD
    if b == 0:
        return a
    # Recursive case: find the GCD of b and the remainder of a divided by b
    return gcd(b, a % b)

# Function to perform Ruiseki algorithm on a given array
def ruiseki_lr(array):
    # Define a helper function to find the GCD of two numbers
    op = lambda a, b: gcd(a, b)
    # Initialize empty lists 'left' and 'right' of size 'n+1'
    e = 0
    n = len(array)
    left = [e] * (n + 1)
    right = [e] * (n + 1)
    # Iterate through the array and calculate the left and right arrays
    for i in range(n):
        left[i+1] = op(left[i], array[i])
    # Iterate through the array in reverse order and calculate the right arrays
    for i in reversed(range(n)):
        right[i] = op(right[i+1], array[i])
    # Return the calculated left and right arrays
    return left, right

# Read input from the user: number of elements in the array and the array itself
n = int(input())
a = list(map(int, input().split()))
# Perform Ruiseki algorithm on the given array and get the left and right arrays
left, right = ruiseki_lr(a)
# Initialize answer variable with 0
ans = 0
# Iterate through the array and find the maximum GCD between adjacent elements in the left and right arrays
for i in range(n):
    ans = max(gcd(left[i], right[i+1]), ans)
# Print the final answer
print(ans)
