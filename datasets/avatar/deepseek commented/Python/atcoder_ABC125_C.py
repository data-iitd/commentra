
def gcd(a: int, b: int) -> int:
    # Recursively calculates the greatest common divisor (GCD) of a and b
    if b == 0:
        return a
    return gcd(b, a % b)

def ruiseki_lr(array):
    # Defines a lambda function to compute GCD
    op = lambda a, b: gcd(a, b)
    # Initial GCD value
    e = 0
    # Length of the input array
    n = len(array)
    # Initialize prefix and suffix GCD arrays
    left = [e] * (n + 1)
    right = [e] * (n + 1)
    # Compute prefix GCD array
    for i in range(n):
        left[i + 1] = op(left[i], array[i])
    # Compute suffix GCD array
    for i in reversed(range(n)):
        right[i] = op(right[i + 1], array[i])
    return left, right

# Read the number of elements
n = int(input())
# Read the list of elements
a = list(map(int, input().split()))
# Compute prefix and suffix GCD arrays
left, right = ruiseki_lr(a)
# Initialize the answer variable
ans = 0
# Iterate through the array to find the maximum GCD
for i in range(n):
    ans = max(gcd(left[i], right[i + 1]), ans)
# Print the result
print(ans)

