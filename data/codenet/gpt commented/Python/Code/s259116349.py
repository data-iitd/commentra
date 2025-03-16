from math import factorial as f  # Importing factorial function from math module

# Read an integer input N from the user
N = int(input())

# List of prime numbers up to 50
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
divs = []  # Initialize a list to store the prime factor counts for numbers 1 to 100

# Loop through numbers from 1 to 100
for i in range(1, 101):
    tmp = [0 for _ in range(len(primes))]  # Temporary list to hold the count of each prime factor
    for j in range(len(primes)):
        p = primes[j]  # Get the current prime number
        tmp[j] = 0  # Initialize the count for this prime
        # Count how many times the prime divides the number
        while(i // p == i / p):
            i = i // p  # Divide the number by the prime
            tmp[j] += 1  # Increment the count for this prime
    divs.append(tmp)  # Append the counts for this number to the divs list
#print(divs)  # Uncomment to see the prime factor counts for numbers 1 to 100

# Initialize a list to hold the cumulative sums of prime factors for numbers 1 to N
divsum = [0 for _ in range(len(primes))]
# Loop through numbers from 1 to N
for i in range(1, N + 1):
    for j in range(len(primes)):
        divsum[j] += divs[i - 1][j]  # Accumulate the counts of prime factors

# Function to count how many numbers have at least n-1 prime factors
def num(n):
    return len(list(filter(lambda x: x >= n - 1, divsum)))

ans = 0  # Initialize the answer variable

# Count combinations with at least 75 prime factors
ans += num(75)

# Count combinations with at least 15 prime factors and between 4 and 13
ans += num(15) * (num(5) - 1)

# Count combinations with at least 25 prime factors and between 2 and 23
ans += num(25) * (num(3) - 1)

# Count combinations with at least 5 prime factors, and pairs of 5 and 3 prime factors
ans += num(5) * (num(5) - 1) * (num(3) - 2) // 2 

# Print the final answer
print(int(ans))
