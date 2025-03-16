import sys

# Global list to hold the sieve flags for prime numbers
flag = []

# Function to generate prime numbers up to a given number using the Sieve of Eratosthenes
def prime(num):
    global flag
    flag = [True] * (num + 1)
    p = 2
    while p * p <= num:
        if flag[p]:
            for i in range(p * p, num + 1, p):
                flag[i] = False
        p += 1

# Main function to execute the program
def main():
    # Generate prime numbers up to 50000
    prime(50000)

    # Infinite loop to continuously accept user input
    while True:
        # Read an integer from the user
        n = int(sys.stdin.readline().strip())
        # Exit the loop if the input is 0
        if n == 0:
            break
        
        i = 2  # Start checking from the smallest prime number
        cnt = 0  # Initialize count of valid pairs

        # Check pairs of primes that sum up to n
        while i * 2 <= n:
            # If both i and n-i are prime
            if flag[i] and flag[n - i]:
                cnt += 1  # Increment the count of valid pairs
            i += 1  # Move to the next number
        
        # Output the count of prime pairs that sum up to n
        print(cnt)

# Execute the main function
if __name__ == "__main__":
    main()
