import sys

def power(x, n, mod=1000000007):
    if n == 0:
        return 1
    val = power(x, n // 2, mod)
    val = val * val % mod
    if n % 2 == 1:
        val = val * x % mod
    return val

def main():
    # Reading the first line of input
    sa = input().split()
    n = int(sa[0])
    
    # Reading the second line of input
    sa = input().split()
    c = [int(x) for x in sa]
    
    mod = 1000000007
    
    # Checking if the size of the array is 1
    if n == 1:
        print(c[0] * 2 % mod)
        return
    
    # Sorting the array c
    c.sort()
    
    # Calculating the values of b and a
    b = power(2, n)
    a = power(2, n - 2)
    
    # Initializing the variable ans to 0
    ans = 0
    
    # Iterating through the array from index 2 to n+1
    for i in range(2, n + 2):
        # Calculating the value of val using the current index i and the previously calculated value a
        val = a * i % mod
        # Multiplying the value of val with the current element of the array c[n+1-i]
        val *= c[n + 1 - i]
        # Taking the modulus of the product to ensure the result is within the range of modulus
        val %= mod
        # Adding the value of val to the variable ans
        ans += val
        # Taking the modulus of the sum of ans and val to ensure the result is within the range of modulus
        ans %= mod
    
    # Multiplying the value of ans with the value of b
    ans *= b
    # Taking the modulus of the product to ensure the result is within the range of modulus
    ans %= mod
    
    # Printing the final result
    print(ans)

# Calling the main function
if __name__ == "__main__":
    main()
