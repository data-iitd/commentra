import sys

def main():
    # Read a long integer input from the user
    n = int(input())

    # Calculate the integer square root of n
    sqrt = int(n ** 0.5)
    # Initialize the answer variable to count the number of prime factors
    answer = 0

    # Loop through all integers from 2 to the square root of n
    for i in range(2, sqrt + 1):
        # Initialize a count for the number of times i divides n
        count = 0
        # While n is divisible by i, divide n by i and increment count
        while 0 == (n % i):
            n //= i
            count += 1
        # For each count of prime factor i, calculate the number of unique factors
        for j in range(1, count + 1):
            count -= j
            answer += 1
    # If n is greater than 1, it means n is a prime number itself
    if n > 1:
        answer += 1
    # Print the total number of unique prime factors
    print(answer)

if __name__ == "__main__":
    main()

