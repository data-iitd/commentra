def is_prime(x):
    """Function to check if a number is prime."""
    if x < 2:
        return False
    for i in range(2, int(x**0.5) + 1):  # Iterates from 2 to the square root of x
        if x % i == 0:
            return False  # Returns false if x is divisible by i
    return True  # Returns true if no divisors are found

def main():
    N = int(input())  # Reads an integer N from standard input

    ans = 1  # Initializes the answer variable to 1
    mod = 10**9 + 7  # Defines a constant for modulo operation
    for i in range(2, N + 1):  # Iterates from 2 to N
        if is_prime(i):  # Checks if the current number i is prime
            NN = N
            cnt = 0  # Initializes a counter to count the power of the prime
            while NN:  # While loop to calculate the power of the prime in N
                cnt += NN // i  # Adds the quotient of NN divided by i to cnt
                NN //= i  # Divides NN by i
            ans *= (cnt + 1)  # Multiplies ans by cnt+1
            ans %= mod  # Takes modulo mod to prevent overflow

    print(ans)  # Prints the final answer

if __name__ == "__main__":
    main()  # Calls the main function

# <END-OF-CODE>
