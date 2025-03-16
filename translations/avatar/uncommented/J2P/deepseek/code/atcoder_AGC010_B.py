def possible(N, A):
    total_sum = sum(A)
    expected_sum = N * (N + 1) // 2
    if total_sum % expected_sum != 0:
        return False
    K = total_sum // expected_sum
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

if __name__ == "__main__":
    main()
