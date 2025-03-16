MOD = 10**9 + 7

def combi(n, k):
    min_comb = (k - 1) * k // 2
    max_comb = (2 * n - k + 1) * k // 2
    return max_comb - min_comb + 1

def main():
    n = int(input())
    k = int(input())

    total = 0
    for i in range(k, n + 2):
        comb = combi(n, i)
        total += comb
        total %= MOD

    print(total)

if __name__ == "__main__":
    main()
