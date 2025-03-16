def main():
    # Declare variables
    N = int(input())  # Number of elements in the array
    A = [0] * N       # Array to store input elements
    sum = 0           # Sum of all elements in the array
    wa = 0            # Sum of all indices from 1 to N
    ans = 0           # Answer flag
    shou = 0          # Quotient of sum and wa

    # Read N integers into the array A
    for i in range(N):
        A[i] = int(input())
        # Add current element to sum
        sum += A[i]
        # Add current index to wa
        wa += i + 1

    # Check if sum is divisible by wa
    if sum % wa != 0:
        ans = 0
    else:
        # Calculate quotient of sum and wa
        shou = sum // wa
        # Calculate differences between adjacent elements and store in array sa
        sa = [0] * N
        for i in range(N):
            sa[i] = A[(i + 1) % N] - A[i] - shou

        # Check if any difference is less than or equal to 0 and divisible by N
        for i in range(N - 1):
            if sa[i] <= 0 and sa[i] % N == 0:
                ans = 1
            else:
                ans = 0
                break

    # Print answer
    if ans:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
