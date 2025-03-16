
from math import factorial as f

# Take an integer input N
N = int(input())

# Define a list of prime numbers
primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47]

# Initialize an empty list to store the prime factorization results
divs = []

# Loop from 1 to 100 to calculate the prime factorization of each number
for i in range(1,101):
    tmp = [0 for _ in range(len(primes))]
    for j in range(len(primes)):
        p = primes[j]
        tmp[j] = 0
        while(i//p==i/p):
            i = i//p
            tmp[j] += 1
    divs.append(tmp)

# Initialize a list to store the sum of prime factors for each prime number up to N
divsum = [0 for _ in range(len(primes))]

# Loop from 1 to N to calculate the sum of prime factors
for i in range(1, N+1):
    for j in range(len(primes)):
        divsum[j] += divs[i-1][j]

# Define a function to count how many prime numbers have at least n-1 occurrences in the range from 1 to N
def num(n):
    return len(list(filter(lambda x:x>=n-1, divsum)))

# Initialize the answer variable
ans = 0

# Calculate the number of numbers that satisfy the condition for 74
ans += num(75)

# Calculate the number of numbers that satisfy the condition for 14 and 13~4
ans += num(15)*(num(5)-1)

# Calculate the number of numbers that satisfy the condition for 24 and 23~2
ans += num(25)*(num(3)-1)

# Calculate the number of numbers that satisfy the condition for 4, 4, and 2
ans += num(5) * (num(5)-1) * (num(3)-2) // 2 

# Print the final result
print(int(ans))

