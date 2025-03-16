MOD = 1000000007

def main():
    n = int(input())
    a = list(map(int, input().split()))
    acc = [0] * (n + 1)
    
    for i in range(n):
        acc[i + 1] = (acc[i] + a[i]) % MOD

    ans = 0
    for i in range(n):
        ans = (ans + a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD) % MOD

    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
