import sys

def power(x, n, mod):
    if n == 0:
        return 1  # Base case: x^0 is 1
    val = power(x, n // 2, mod)  # Recursive call to calculate x^(n/2)
    val = val * val % mod  # Squaring the result
    if n % 2 == 1:
        val = val * x % mod  # Multiplying by x if n is odd
    return val  # Returning the result

def main():
    input = sys.stdin.read
    data = input().splitlines()  # Reading all input lines
    n = int(data[0])  # Parsing the first line as integer n
    c = list(map(int, data[1].split()))  # Reading the second line and converting to a list of integers

    mod = 1000000007  # Defining the modulo value
    if n == 1:
        print(c[0] * 2 % mod)  # If n is 1, print the result directly
        return  # Exit the program as no further computation is needed

    c.sort()  # Sorting the array c in ascending order

    b = power(2, n, mod)  # Calculating 2^n
    a = power(2, n - 2, mod)  # Calculating 2^(n-2)
    ans = 0  # Initializing the answer variable

    # Calculating the final answer
    for i in range(2, n + 2):
        val = a * i % mod  # Intermediate calculation
        val *= c[n + 1 - i]  # Intermediate calculation
        val %= mod  # Modulo operation
        ans += val  # Adding to the answer
        ans %= mod  # Modulo operation

    ans *= b  # Multiplying the answer by b
    ans %= mod  # Modulo operation
    print(ans)  # Printing the final result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
