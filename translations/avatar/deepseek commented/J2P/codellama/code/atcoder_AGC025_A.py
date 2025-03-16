
import sys

def sum(a):
    ans = 0
    while a >= 10:
        ans += a % 10
        a //= 10
    ans += a
    return ans

if __name__ == "__main__":
    N = int(sys.stdin.readline())

    # Calculate n as half of N if N is even, or half of N plus one if N is odd
    n = 0
    if N % 2 == 0:
        n = N // 2
    else:
        n = (N + 1) // 2

    # Initialize ans with the sum of digits of 1 and N-1
    ans = sum(1) + sum(N - 1)

    # Iterate from 1 to n to find the minimum sum of digits of A and N-A
    for A in range(1, n + 1):
        if sum(A) + sum(N - A) < ans:
            ans = sum(A) + sum(N - A)

    # Print the minimum ans
    print(ans)

