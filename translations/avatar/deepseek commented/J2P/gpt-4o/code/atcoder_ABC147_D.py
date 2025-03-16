import sys

def main():
    start_time = sys.time()  # Start time for performance measurement
    n = int(input())  # Read the number of elements
    div = 10**9 + 7  # Define the modulo constant
    A = list(map(int, input().split()))  # Read n long integers from the user and store them in list A
    ans = 0  # Initialize the answer variable

    # Iterate over each bit position from 0 to 59
    for i in range(60):
        a = 0  # Initialize the contribution for the current bit position
        count1 = 0  # Count of elements with the current bit set to 1

        # Count the number of elements with the current bit set to 1
        for j in range(n):
            if (A[j] >> i) & 1 == 1:
                count1 += 1

        # Calculate the contribution of the current bit position
        a = count1 * (n - count1)

        # Shift the contribution left by 1 bit for each lower bit position and take modulo
        for j in range(i):
            a = (a << 1) % div

        # Add the contribution to the answer and take modulo
        ans = (ans + a) % div

    # Print the result
    print(ans)
    end_time = sys.time()  # End time for performance measurement

if __name__ == "__main__":
    main()

# <END-OF-CODE>
