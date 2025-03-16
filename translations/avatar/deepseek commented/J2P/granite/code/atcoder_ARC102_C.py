
```python
import sys

mod = 998244353
nchoosek = [[0] * 4001 for _ in range(4001)]

# Initialize nchoosek array for binomial coefficients
for i in range(4001):
    nchoosek[i][0] = nchoosek[i][i] = 1

# Fill the nchoosek array using dynamic programming
for i in range(2, 4001):
    for j in range(1, i):
        nchoosek[i][j] = (nchoosek[i - 1][j] + nchoosek[i - 1][j - 1]) % mod

# Read input values k and n
k, n = map(int, sys.stdin.readline().split())

# Main loop to compute and print results for each i from 2 to 2*k
for i in range(2, 2 * k + 1):
    pairs = k - i // 2 if i > k else (i - 1) // 2
    active = k - 2 * pairs
    if i % 2 == 0:
        active -= 1
    times2 = 1
    total = 0

    # Calculate total using binomial coefficients
    for j in range(pairs + 1):
        choice = times2 * nchoosek[pairs][j] % mod
        times2 = times2 * 2 % mod
        if active + j - 1 < 0:
            continue
        total += choice * nchoosek[n + active - 1][active + j - 1]
        if i % 2 == 0:
            total += choice * nchoosek[n + active - 2][active + j - 1]
        total %= mod
    print(total)
```

