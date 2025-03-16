class Main:
    @staticmethod
    def possible(N, A):
        sum_A = sum(A)  # Calculate the sum of all elements in the array A

        # Calculate the expected sum based on the number of elements in the array
        NS = N * (N + 1) // 2

        # Check if the sum of all elements is equal to the expected sum
        if sum_A % NS != 0:
            return False

        # Calculate the common difference between consecutive elements
        K = sum_A // NS

        # Check each pair of consecutive elements to see if their difference is valid
        for i in range(N):
            j = (i - 1) if i > 0 else (N - 1)
            d = K - (A[i] - A[j])  # Calculate the difference

            # Check if the difference is valid
            if d < 0 or d % N != 0:
                return False

        # If all checks pass, return true
        return True

if __name__ == "__main__":
    # Read the number of elements in the array from standard input
    N = int(input())

    # Read each element of the array A from standard input
    A = list(map(int, input().split()))

    # Check if the conditions for a possible solution are met
    if Main.possible(N, A):
        # Print "YES" if the conditions are met
        print("YES")
    else:
        # Print "NO" if the conditions are not met
        print("NO")

# <END-OF-CODE>
