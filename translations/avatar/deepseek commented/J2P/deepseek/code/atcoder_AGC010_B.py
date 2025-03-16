def possible(N, A):
    sum_A = sum(A)
    NS = N * (N + 1) // 2
    if sum_A % NS != 0:
        return False
    K = sum_A // NS
    for i in range(N):
        j = (i - 1) % N
        d = K - (A[i] - A[j])
        if d < 0 or d % N != 0:
            return False
    return True

def main():
    N = int(input())
    A = list(map(int, input().split()))
    if possible(N, A):
        print("YES")
    else:
        print("NO")

main()

