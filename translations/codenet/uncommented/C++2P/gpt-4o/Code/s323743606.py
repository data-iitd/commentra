from collections import defaultdict

m = defaultdict(int)

for i in range(5001 // 200 + 1):
    for j in range(5001 // 300 + 1):
        for k in range(5001 // 500 + 1):
            w = i * 200 + j * 300 + k * 500
            p = (i // 5 * 5 * 380 * 0.8 + i % 5 * 380 +
                 j // 4 * 4 * 550 * 0.85 + j % 4 * 550 +
                 k // 3 * 3 * 850 * 0.88 + k % 3 * 850)
            if w in m:
                m[w] = min(m[w], p)
            else:
                m[w] = p

while True:
    try:
        n = int(input())
        if n == 0:
            break
        print(m[n])
    except EOFError:
        break

# <END-OF-CODE>
