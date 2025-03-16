import sys

def main():
    # Reading the number of elements in the array from the console
    n = int(sys.stdin.readline().strip())

    # Reading the three integers representing the array elements
    a, b, c = map(int, sys.stdin.readline().strip().split())

    # Defining the maximum size of the dynamic programming array
    maxn = 4010

    # Defining an array to store the array elements
    arr = [a, b, c]

    # Creating a dynamic programming array of size maxn
    dp = [float('-inf')] * maxn

    # Initializing the dynamic programming array with minimum values
    dp[0] = 0

    # Filling the dynamic programming array using two nested loops
    for i in range(3):  # Looping through the array elements
        for j in range(arr[i], maxn):  # Looping through the dynamic programming array
            dp[j] = max(dp[j], dp[j - arr[i]] + 1)  # Updating the maximum length ending at j

    # Printing the result, which is the maximum length ending at the nth index
    print(dp[n])

if __name__ == "__main__":
    main()
