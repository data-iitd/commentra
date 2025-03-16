MOD = 998244353

def compute_nchoosek(max_n):
    nchoosek = [[0] * (max_n + 1) for _ in range(max_n + 1)]
    for i in range(max_n + 1):
        nchoosek[i][0] = nchoosek[i][i] = 1
    for i in range(2, max_n + 1):
        for j in range(1, i):
            nchoosek[i][j] = (nchoosek[i - 1][j] + nchoosek[i - 1][j - 1]) % MOD
    return nchoosek

def main():
    nchoosek = compute_nchoosek(4000)
    sc = Scanner(System.in)
    k = sc.nextInt()
    n = sc.nextInt()
    for i in range(2, 2 * k + 1):
        if i > k:
            pairs = k - i // 2
        else:
            pairs = (i - 1) // 2
        active = k - 2 * pairs
        if i % 2 == 0:
            active -= 1
        times2 = 1
        total = 0
        for j in range(pairs + 1):
            choice = times2 * nchoosek[pairs][j] % MOD
            times2 = times2 * 2 % MOD
            if active + j - 1 < 0:
                continue
            total += choice * nchoosek[n + active - 1][active + j - 1]
            if i % 2 == 0:
                total += choice * nchoosek[n + active - 2][active + j - 1]
            total %= MOD
        print(total)

if __name__ == "__main__":
    main()
