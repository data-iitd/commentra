import sys

def main():
    start_time = time.time()
    n = int(input().strip())  # Read the number of elements
    div = 10**9 + 7  # Define the modulo constant
    A = list(map(int, input().strip().split()))  # Read n long integers from the user and store them in array A
    ans = 0  # Initialize the answer variable

    # Iterate over each bit position from 0 to 59
    for i in range(60):
        a = 0  # Initialize the contribution for the current bit position
        count1 = 0  # Count of elements with the current bit set to 1

        # Count the number of elements with the current bit set to 1
        for j in range(n):
            if (A[j] >> i) & 1:
                count1 += 1

        # Calculate the contribution of the current bit position
        a = a + count1 * (n - count1)

        # Shift the contribution left by 1 bit for each lower bit position and take modulo
        for j in range(i):
            a = (a << 1) % div

        # Add the contribution to the answer and take modulo
        ans += a
        ans %= div

    # Print the result
    print(ans)
    end_time = time.time()

if __name__ == "__main__":
    import time
    main()
