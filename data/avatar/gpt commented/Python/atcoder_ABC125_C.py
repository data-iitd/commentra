def gcd(a: int, b: int) -> int:
    # Base case: if b is 0, return a as the GCD
    if b == 0:
        return a
    # Recursive case: call gcd with b and the remainder of a divided by b
    return gcd(b, a % b)

def ruiseki_lr(array):
    # Define the operation to find the GCD of two numbers
    op = lambda a, b: gcd(a, b)
    
    # Initialize the identity element for GCD
    e = 0
    n = len(array)
    
    # Create lists to store cumulative GCD from the left and right
    left = [e] * (n + 1)
    right = [e] * (n + 1)
    
    # Calculate cumulative GCD from the left
    for i in range(n):
        left[i + 1] = op(left[i], array[i])
    
    # Calculate cumulative GCD from the right
    for i in reversed(range(n)):
        right[i] = op(right[i + 1], array[i])
    
    # Return both cumulative GCD lists
    return left, right

# Read the number of elements in the array
n = int(input())
# Read the array elements from input and convert them to integers
a = list(map(int, input().split()))

# Compute the cumulative GCD from the left and right
left, right = ruiseki_lr(a)

# Initialize the answer variable to store the maximum GCD found
ans = 0

# Iterate through the array to find the maximum GCD of left and right parts
for i in range(n):
    ans = max(gcd(left[i], right[i + 1]), ans)

# Print the maximum GCD found
print(ans)
