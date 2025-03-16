import sys

# Reading the input from System.in
n = int(sys.stdin.readline().strip())
c = list(map(int, sys.stdin.readline().strip().split()))

# Checking if the size of the array is 1
if n == 1:
    # Printing the result for the case when the size of the array is 1
    print(c[0] * 2 % 1000000007)
    sys.exit(0)

# Sorting the array c in parallel using the sorted() function
c.sort()

# Calculating the values of b and a
b = 2 ** n
a = 2 ** (n - 2)

# Initializing the variable ans to 0
ans = 0

# Iterating through the array from index 2 to n+1
for i in range(2, n + 2):
    # Calculating the value of val using the current index i and the previously calculated value a
    val = a * i % 1000000007

    # Multiplying the value of val with the current element of the array c[n+1-i]
    val *= c[n + 1 - i]

    # Taking the modulus of the product to ensure the result is within the range of modulus
    val %= 1000000007

    # Adding the value of val to the variable ans
    ans += val

    # Taking the modulus of the sum of ans and val to ensure the result is within the range of modulus
    ans %= 1000000007

# Multiplying the value of ans with the value of b
ans *= b

# Taking the modulus of the product to ensure the result is within the range of modulus
ans %= 1000000007

# Printing the final result
print(ans)

