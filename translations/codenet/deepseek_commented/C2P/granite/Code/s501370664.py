
import sys

def prime(num):
    flag = [0] * (num + 1) # Initialize a list of zeros to mark non-prime numbers
    for i in range(2, int(num ** 0.5) + 1):
        if flag[i] == 0:
            for j in range(2, num // i + 1):
                flag[i * j] = 1
    return flag

def main():
    flag = prime(50000) # Call the prime function to mark non-prime numbers up to 50000
    while True:
        n = int(input()) # Read an integer 'n' from the user
        if n == 0:
            break # Exit the loop if 'n' is zero
        i = 2 # Initialize the starting prime number
        cnt = 0 # Initialize the count of pairs
        while i * 2 <= n: # Loop to find pairs of primes summing to 'n'
            if flag[i] == 0 and flag[n - i] == 0: # Check if both 'i' and 'n-i' are prime
                cnt += 1 # Increment the count if a valid pair is found
            i += 1 # Move to the next potential prime number
        print(cnt) # Print the count of pairs of primes summing to 'n'

if __name__ == "__main__":
    sys.exit(main())

