import sys

def main():
    N = int(sys.stdin.readline())
    K = int(sys.stdin.readline())
    S = [int(sys.stdin.readline()) for _ in range(N)]
    temp = 0
    ans = 1000000000
    if K == 1:
        for i in range(N):
            temp = S[i]
            ans = min(abs(temp), ans)
        print(ans)
    elif N - K!= 0:
        for i in range(N - K + 1):
            min = S[i]
            max = S[i + K - 1]
            if min < 0 and max > 0:
                temp = min(2 * (-min) + max, (-min) + 2 * max)
            else:
                temp = max(abs(min), abs(max))
            ans = min(ans, temp)
        print(ans)
    else:
        min = S[0]
        max = S[N - 1]
        if min < 0 and max > 0:
            print(min(2 * (-min) + max, (-min) + 2 * max))
        else:
            print(max(abs(min), abs(max)))

if __name__ == "__main__":
    main()

