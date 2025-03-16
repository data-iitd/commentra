# Main function starts here
def main():
    # Initialize an array 'prime' of size MAX_V+1 with all elements set to 1
    MAX_V = 999999
    prime = [1] * (MAX_V + 1)

    # Sieve of Eratosthenes algorithm to find prime numbers
    for i in range(2, MAX_V + 1):
        # If i is prime, mark all its multiples as composite
        if prime[i]:
            for k in range(i * i, MAX_V + 1, i):
                prime[k] = 0

    # Set prime[0] and prime[1] to 0 as they are not prime numbers
    prime[0] = 0
    prime[1] = 0

    # Initialize a counter 'count' for the number of test cases
    count = 0

    # Read input test cases until end of file is reached
    try:
        while True:
            n = int(input())
            # Increment the counter for each test case
            count += 1

            # Initialize a counter 'cnt' to count the number of prime digits in n
            cnt = 0

            # Iterate through each digit of n and count the number of prime digits
            for digit in str(n):
                if prime[int(digit)] == 1:
                    cnt += 1  # Increment the counter if the digit is prime

            # Print the result for the current test case
            print(cnt)

            # Break the loop if the required number of test cases have been processed
            if count == 30:
                break
    except EOFError:
        pass

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
