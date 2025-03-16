def possible(N, A):
    total_sum = sum(A)
    NS = N * (N + 1) // 2
    if total_sum % NS != 0:
        return False
    K = total_sum // NS
    for i in range(N):
        j = N - 1 if i == 0 else i - 1
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

if __name__ == "__main__":
    main()

# <END-OF-CODE>
