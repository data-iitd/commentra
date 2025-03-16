
import sys

def main():
    startTime = int(round(time.time() * 1000))
    n = int(input())
    div = 100000007
    A = [int(x) for x in input().split()]
    ans = 0

    for i in range(60):
        a = 0
        count1 = 0

        for j in range(n):
            if (A[j] >> i) & 1 == 1:
                count1 += 1

        a = a + count1 * (n - count1)

        for j in range(i):
            a = (a << 1) % div

        ans += a
        ans %= div

    print(ans)
    endTime = int(round(time.time() * 1000))
    print("Time:", endTime - startTime, "ms")

if __name__ == "__main__":
    main()

