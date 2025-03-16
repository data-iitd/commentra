def is_prime(x):
    if x < 2:
        return False
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            return False
    return True

def main():
    N = int(input())
    
    ans = 1
    mod = 10**9 + 7
    
    for i in range(2, N + 1):
        if is_prime(i):
            NN = N
            cnt = 0
            while NN:
                cnt += NN // i
                NN //= i
            ans *= (cnt + 1)
            ans %= mod
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
