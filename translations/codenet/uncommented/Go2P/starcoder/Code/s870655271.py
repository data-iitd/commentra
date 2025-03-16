
def max(x, y):
    return x if x > y else y

def min(x, y):
    return x if x < y else y

def pow(x, y):
    return x ** y

def abs(x):
    return x if x >= 0 else -x

def floor(x):
    return int(x)

def main():
    N, M = map(int, input().split())
    ans = 0
    if N == 1 and M == 1:
        ans += 1
    elif 1 < N and 1 < M:
        ans += (N - 2) * (M - 2)
    else:
        ans += (N * M) - 2
    print(ans)

if __name__ == "__main__":
    main()

/*  ----------------------------------------  */

