import sys

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
    # Read the number of elements in the array from standard input
    N = int(sys.stdin.readline().strip())

    # Read each element of the array A from standard input
    A = list(map(int, sys.stdin.readline().strip().split()))

    # Check if the conditions for a possible solution are met
    if possible(N, A):
        # Print "YES" if the conditions are met
        print("YES")
    else:
        # Print "NO" if the conditions are not met
        print("NO")

if __name__ == "__main__":
    main()

