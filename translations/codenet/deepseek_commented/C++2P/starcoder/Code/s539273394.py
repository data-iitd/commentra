# Array to store the result of prime factorization
kekka = [0,0]

# Array to determine if a number is prime or not (0 for prime, 1 for not prime)
prime_or_not = [0 for i in range(1001)]

# Array to store prime numbers
prime_list = [0 for i in range(1001)]

# Array to store the power of each prime factor
prime_num = [0 for i in range(1001)]

# Counter to keep track of the number of prime numbers found
prime_counter = 0

# Function to find all prime numbers up to 1000
def sosuubunnpu():
    # Initialize the prime_or_not array to 0 (indicating all numbers are potential primes)
    for i in range(1,1001):
        prime_or_not[i] = 0

    # Mark non-prime numbers using the Sieve of Eratosthenes algorithm
    for i in range(2,1001):
        for j in range(2,1001/i):
            if(prime_or_not[i]==0):
                prime_or_not[i*j] = 1

    # Collect all prime numbers into the prime_list array
    for i in range(2,1001):
        if(prime_or_not[i]==0):
            prime_list[prime_counter] = i
            prime_counter+=1

# Function to find the power of a prime factor in the factorization of a number
def innsuubunnkai(N,n):
    time = 0
    while(1):
        if(N%n == 0):
            N = N/n
            time+=1
        else:
            break
    kekka[0] = time
    kekka[1] = N

# Read the integer N
N = int(input())

# Call the function to find all prime numbers up to 1000
sosuubunnpu()

# Initialize arrays to store the prime factorization of numbers up to N
innsuu = [0 for i in range(11)]
A = [[0 for i in range(11)] for j in range(N+1)]

# Calculate the prime factorization of each number up to N
result = 1
for current_num in range(2,N+1):
    kekka[1] = current_num
    for i in range(0,prime_counter):
        innsuubunnkai(kekka[1],prime_list[i])
        prime_num[i]+=kekka[0]

# Sum the powers of each prime factor for all numbers up to N
for current_num in range(2,N+1):
    for i in range(0,11):
        innsuu[i] += A[current_num][i]

# Calculate the result using the formula for the number of divisors
for i in range(0,prime_counter):
    result = (result*(prime_num[i]+1))%1000000007

# Print the final result
print(result)

