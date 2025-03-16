
# Function to compute the greatest common divisor (GCD) of two integers
def gcd(a, b):
    # Ensure 'a' is the larger number for the algorithm
    if a < b:
        a, b = b, a
    r = a % b
    while r > 0:
        a = b
        b = r
        r = a % b
    return b

n = int(input())
ans = int(input())
for i in range(1, n):
    a = int(input())
    ans = gcd(ans, a)
print(ans)

