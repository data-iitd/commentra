def sieve_of_eratosthenes():
    prime_or_not = [0] * 1001
    prime_list = []
    for i in range(2, 1001):
        if prime_or_not[i] == 0:
            prime_list.append(i)
            for j in range(i * 2, 1001, i):
                prime_or_not[j] = 1
    return prime_list

def prime_factorization(N, n):
    time = 0
    while True:
        if N % n == 0:
            N = N // n
            time += 1
        else:
            break
    return time, N

def main():
    prime_list = sieve_of_eratosthenes()
    N = int(input())
    prime_num = [0] * 1001
    result = 1
    for current_num in range(2, N + 1):
        factors = current_num
        for prime in prime_list:
            if prime > factors:
                break
            time, factors = prime_factorization(factors, prime)
            prime_num[prime] += time
    result = 1
    for i in range(2, N + 1):
        for j in range(11):
            prime_num[j] += A[i][j]
    for i in range(len(prime_list)):
        result = (result * (prime_num[prime_list[i]] + 1)) % 1000000007
    print(result)

