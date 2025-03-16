import sys

# Initialize the nchoosek array for binomial coefficients
nchoosek = [[1 for i in range(4001)] for j in range(4001)]
for i in range(4001):
    nchoosek[i][0] = nchoosek[i][i] = 1

# Fill the nchoosek array using dynamic programming
for i in range(2, 4001):
    for j in range(1, i):
        nchoosek[i][j] = (nchoosek[i - 1][j] + nchoosek[i - 1][j - 1]) % 998244353

# Read input values k and n
k = int(sys.stdin.readline())
n = int(sys.stdin.readline())

# Main loop to compute and print results for each i from 2 to 2*k
for i in range(2, 2 * k + 1):
    pairs = k - i // 2 if i > k else (i - 1) // 2
    active = k - 2 * pairs
    if i % 2 == 0:
        active -= 1
    times2 = 1
    total = 0
    for j in range(0, pairs + 1):
        choice = times2 * nchoosek[pairs][j] % 998244353
        times2 = times2 * 2 % 998244353
        if active + j - 1 < 0:
            continue
        total += choice * nchoosek[n + active - 1][active + j - 1]
        if i % 2 == 0:
            total += choice * nchoosek[n + active - 2][active + j - 1]
        total %= 998244353
    print(total)

# 