
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

k = int(input())  # Read the value of k from the input
ans = 0

# Iterate over all possible values of a, b, and c from 1 to k
for a in range(1, k + 1):
    for b in range(1, k + 1):
        for c in range(1, k + 1):
            # Calculate the greatest common divisor of a and the greatest common divisor of b and c, and add it to ans
            ans += gcd(a, gcd(b, c))

print(ans)  # Print the final value of ans

