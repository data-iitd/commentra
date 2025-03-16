
# Global arrays for storing results and prime information
kekka = [0, 0]  # Array to store the result of factorization
prime_or_not = [0] * 1001  # Array to mark prime numbers
prime_list = []  # List to store prime numbers
prime_num = [0] * 1001  # Array to store the count of prime factors for each prime
prime_counter = 0  # Counter for the number of primes found

# Function to find all prime numbers up to 1000 using the Sieve of Eratosthenes
def sosuubunnpu():
    global prime_counter
    # Initialize the prime_or_not array to 0 (indicating all numbers are initially assumed prime)
    for i in range(1, 1001):
        prime_or_not[i] = 0

    # Mark non-prime numbers in the prime_or_not array
    for i in range(2, 1001):
        if prime_or_not[i] == 0:  # If i is still marked as prime
            for j in range(2, 1001 // i + 1):
                if prime_or_not[i * j] == 0:  # If i * j is still marked as prime
                    prime_or_not[i * j] = 1  # Mark i * j as non-prime
            prime_list.append(i)  # Add to the prime list
            prime_counter += 1  # Increment the prime counter

# Function to perform prime factorization of N by dividing it by n
def innsuubunnkai(N, n):
    global kekka
    time = 0  # Counter for how many times N can be divided by n
    while True:
        if N % n == 0:  # If N is divisible by n
            N = N // n  # Divide N by n
            time += 1  # Increment the division count
        else:
            break  # Exit loop if N is no longer divisible by n
    kekka[0] = time  # Store the count of divisions in kekka[0]
    kekka[1] = N  # Store the remaining value of N in kekka[1]

# Main function
def main():
    # Generate the list of prime numbers
    sosuubunnpu()

    N = int(input())  # Read the input number from the user
    innsuu = [0] * 11  # Array to store counts of prime factors (up to 10 different primes)
    A = [[0] * 11 for _ in range(N + 1)]  # 2D array to store factorization results (not used in the provided code)

    # Initialize the prime_num array to 0
    for i in range(1001):
        prime_num[i] = 0

    result = 1  # Variable to store the final result

    # Loop through each number from 2 to N to factorize it
    for current_num in range(2, N + 1):
        kekka[1] = current_num  # Set the current number to factorize
        for i in range(prime_counter):
            innsuubunnkai(kekka[1], prime_list[i])  # Factorize current_num by each prime
            prime_num[i] += kekka[0]  # Update the count of prime factors for the prime

    # Accumulate the counts of prime factors for each prime
    for current_num in range(2, N + 1):
        for i in range(11):
            innsuu[i] += A[current_num][i]  # This line seems to be incomplete or unused

    # Calculate the final result based on the counts of prime factors
    for i in range(prime_counter):
        result = (result * (prime_num[i] + 1)) % 1000000007  # Update result with the formula

    # Output the final result
    print(result)

# Call the main function
if __name__ == "__main__":
    main()

