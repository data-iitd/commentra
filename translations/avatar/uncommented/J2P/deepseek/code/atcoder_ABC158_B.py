import sys

def main():
    # Read input from stdin
    N = int(sys.stdin.readline().strip())
    A = int(sys.stdin.readline().strip())
    B = int(sys.stdin.readline().strip())

    # Check constraints
    if 1 <= N <= 10**18 and 0 <= A <= 10**18 and 0 <= B <= 10**18 and A + B > 0 and A + B <= 10**18:
        if A + B <= N:
            k = N // (A + B)
            if N - k * (A + B) > A:
                print(A * k + (N - k * (A + B)) - (N - (k * (A + B) + A)))
            else:
                print(A * k + (N - k * (A + B)))
        elif A + B > N and A <= N:
            print(A)
        else:
            print(N)

if __name__ == "__main__":
    main()
