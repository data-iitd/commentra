
MOD = 1000000007

def main():
    n, x = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort()

    ans = 0
    i, j = 0, 0
    while j < len(A):
        if x >= A[i]:
            ans += 1
            x -= A[i]
            i += 1
        else:
            j += 1

    if x > 0 and len(A) == ans:
        ans -= 1

    print(ans)

main()

