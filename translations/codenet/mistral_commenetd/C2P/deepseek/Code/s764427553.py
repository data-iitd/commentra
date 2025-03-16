MAX_V = 999999
prime = [1] * (MAX_V + 1)

# Sieve of Eratosthenes algorithm to find prime numbers
for i in range(2, int(MAX_V**0.5) + 1):
    if prime[i]:
        for k in range(i*i, MAX_V + 1, i):
            prime[k] = 0

# Set prime[0] and prime[1] to 0 as they are not prime numbers
prime[0] = 0
prime[1] = 0

count = 0

while True:
    try:
        n = int(input())
        count += 1
        cnt = 0

        # Iterate through each digit of n from right to left and count the number of prime digits
        for digit in str(n):
            if prime[int(digit)]:
                cnt += 1

        print(cnt)

        if count == 30:
            break
    except EOFError:
        break

