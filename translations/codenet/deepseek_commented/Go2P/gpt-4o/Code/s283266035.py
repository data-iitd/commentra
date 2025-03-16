def main():
    n = int(input())  # Read an input value for `n` from the user
    ans = 0  # Initialize a variable `ans` to 0 to store the final answer

    # Loop through values of `i` starting from 1
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0 and n % (n // i - 1) == i:  # Check if `i` is a divisor of `n` and if `n/(i-1)` is also a divisor of `n`
            ans += n // i - 1  # Add `n/(i-1) - 1` to `ans` if both conditions are met

    print(ans)  # Print the value of `ans`

if __name__ == "__main__":
    main()

# <END-OF-CODE>
