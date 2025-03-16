# Import necessary libraries
import sys

# Define constants
INF = 1001001001001001
MOD = 1000000007

# Main function starts here
def main():
    # Read the number of elements in the array 'a'
    n = int(input().strip())

    # Initialize a list 'a' of size 'n'
    a = list(map(int, input().strip().split()))

    # Initialize a list 'acc' of size 'n+1' with zero as initial value
    acc = [0] * (n + 1)

    # Read the elements of the array 'a' and calculate the cumulative sum
    for i in range(n):
        acc[i + 1] = (acc[i] + a[i]) % MOD

    # Initialize the answer 'ans' to zero
    ans = 0

    # Calculate the answer using the formula
    for i in range(n):
        # Calculate the contribution of the current element 'a[i]' to the answer
        temp = (a[i] % MOD) * (MOD + acc[n] - acc[i + 1]) % MOD

        # Add the contribution to the answer
        ans = (ans + temp) % MOD

    # Print the answer
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
