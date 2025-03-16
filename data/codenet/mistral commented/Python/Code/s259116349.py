# Importing the math module and defining a shorthand for factorial function
from math import factorial as f

# Taking the input value N from the user
N = int(input())

# Initializing an empty list 'primes' with the first 14 prime numbers
primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43]

# Initializing an empty list 'divs' to store the prime divisor counts for each number up to 100
divs = []

# Iterating through each number from 1 to 100 and calculating the prime divisor counts
for i in range(1,101):
    # Initializing a list 'tmp' of same length as 'primes' to store the prime divisor counts for current number 'i'
    tmp = [0 for _ in range(len(primes))]
    
    # Iterating through each prime number in 'primes' and counting the number of occurrences in the prime factorization of 'i'
    for j in range(len(primes)):
        p = primes[j]
        # Setting the initial count of prime number 'p' in 'tmp' to zero
        tmp[j] = 0
        # While the current number 'i' is divisible by the prime number 'p', increment the count in 'tmp'
        while(i//p==i/p):
            i = i//p
            tmp[j] += 1
    
    # Appending the 'tmp' list (prime divisor counts for current number 'i') to the 'divs' list
    divs.append(tmp)

# Initializing an empty list 'divsum' to store the sum of prime divisor counts for each prime number up to 'N'
divsum = [0 for _ in range(len(primes))]

# Iterating through each number from 1 to 'N' and calculating the sum of prime divisor counts for each prime number
for i in range(1, N+1):
    # Iterating through each prime number in 'primes' and adding the count to the corresponding index in 'divsum'
    for j in range(len(primes)):
        divsum[j] += divs[i-1][j]

# Defining a helper function 'num' to calculate the number of primes greater than or equal to 'n'
def num(n):
    # Returning the length of the list filtered by prime numbers greater than or equal to 'n'
    return len(list(filter(lambda x:x>=n-1, divsum)))

# Initializing the answer 'ans' to zero
ans = 0

# Calculating the answer by adding the number of primes greater than or equal to 75,
# the number of primes between 13 and 5 (excluding 5), the number of primes between 23 and 2 (excluding 2),
# and the number of primes less than or equal to 5 multiplied by the number of primes less than or equal to 5 minus 2,
# all multiplied by 1
ans += num(75)
ans += num(15)*(num(5)-1)
ans += num(25)*(num(3)-1)
ans += num(5) * (num(5)-1) * (num(3)-2) // 2

# Printing the final answer
print(int(ans))
