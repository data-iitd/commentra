import math

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def main():
    N = int(input())  # Read the number of elements
    A = list(map(int, input().split()))  # Read the elements of A from the input

    # Arrays to store the prefix and suffix GCDs
    L = [0] * N
    R = [0] * N

    # Calculate the prefix GCD array L
    L[0] = A[0]
    for i in range(1, N):
        L[i] = gcd(L[i - 1], A[i])

    # Calculate the suffix GCD array R
    R[N - 1] = A[N - 1]
    for i in range(N - 2, -1, -1):
        R[i] = gcd(R[i + 1], A[i])

    # Initialize the answer with the maximum of the GCD of the first and last elements of L and R
    answer = max(L[N - 2], R[1])

    # Iterate through the array to find the maximum GCD
    for i in range(1, N - 1):
        answer = max(answer, gcd(L[i - 1], R[i + 1]))

    # Print the final answer
    print(answer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
