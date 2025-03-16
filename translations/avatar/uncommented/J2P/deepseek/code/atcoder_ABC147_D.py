import sys

def main():
    start_time = time.time()
    n = int(input().strip())
    div = 10**9 + 7
    A = list(map(int, input().strip().split()))
    ans = 0

    for i in range(60):
        a = 0
        count1 = 0
        for j in range(n):
            if (A[j] >> i) & 1:
                count1 += 1
        a = a + count1 * (n - count1)
        for j in range(i):
            a = (a << 1) % div
        ans += a
        ans %= div

    print(ans)
    end_time = time.time()
    # print(f"Time taken: {end_time - start_time} seconds")

if __name__ == "__main__":
    import time
    main()
