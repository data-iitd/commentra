
import sys

def main():
    N = int(raw_input())
    A = int(raw_input())
    B = int(raw_input())
    k = 0

    # Check if the values of N, A, and B are within the specified ranges
    if 1 <= N and N <= 10 ** 18 and 0 <= A and 0 <= B and 0 < A + B and A + B <= 10 ** 18:

        # Calculate the number of complete cycles (k) of A and B that fit into N
        if A + B <= N:
            k = N / (A + B)
            if N - k * (A + B) > A:
                print A * k + (N - k * (A + B)) - (N - (k * (A + B) + A))
            else:
                print A * k + (N - k * (A + B))
        # If the sum of A and B is greater than N and A is less than or equal to N
        elif A + B > N and A <= N:
            print A
        # If none of the above conditions are met, print N
        else:
            print N

if __name__ == "__main__":
    main()

