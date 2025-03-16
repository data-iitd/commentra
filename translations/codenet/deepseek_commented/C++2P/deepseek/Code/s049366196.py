def is_prime(x):
    i = 2
    while i * i <= x:
        if x % i == 0:
            return False
        i += 1
    return True

def main():
    N = int(input())
    ans = 1
    for i in range(2, N + 1):
        if is_prime(i):
            NN = N
            cnt = 0
            while NN > 0:
                cnt += NN // i
                NN //= i
            ans *= cnt + 1
            ans %= 10**9 + 7
    print(ans)

