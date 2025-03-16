from collections import defaultdict

def main():
    m = defaultdict(lambda: float('inf'))
    for i in range(0, 5001 // 200 + 1):
        for j in range(0, 5001 // 300 + 1):
            for k in range(0, 5001 // 500 + 1):
                w = i * 200 + j * 300 + k * 500
                p = (i // 5) * 5 * 380 * 0.8 + (i % 5) * 380 + \
                    (j // 4) * 4 * 550 * 0.85 + (j % 4) * 550 + \
                    (k // 3) * 3 * 850 * 0.88 + (k % 3) * 850
                if w in m:
                    m[w] = min(m[w], p)
                else:
                    m[w] = p

    while True:
        n = int(input())
        if n == 0:
            break
        print(m[n])

if __name__ == "__main__":
    main()
