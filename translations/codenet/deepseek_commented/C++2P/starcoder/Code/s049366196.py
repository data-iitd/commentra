# Python 3 program to find the number of
# distinct prime factors of N

# Function to check if a number is prime
def is_prime(x):
    for i in range(2, int(x**0.5)+1):
        if x % i == 0:
            return False
    return True

# Function to find the number of distinct
# prime factors of N
def countDistinctPrimeFactors(N):
    ans = 1
    for i in range(2, N+1):
        if is_prime(i):
            cnt = 0
            while N:
                cnt += N//i
                N //= i
            ans *= cnt+1
            ans %= mod
    return ans

# Driver Code
if __name__ == '__main__':
    N = int(input())
    print(countDistinctPrimeFactors(N))

