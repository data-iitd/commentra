import sys

# Define a constant for a large number to represent infinity
inf = 10000000000.0

def main():
    # Read the number of elements in the array
    n = int(input().strip())

    # Initialize a list to hold the input values
    arrA = list(map(int, input().strip().split()))

    # Create a cumulative sum array to store the cumulative sums of arrA
    cumSumA = [0] * (n + 1)
    # Calculate the cumulative sums
    for i in range(n):
        cumSumA[i + 1] = cumSumA[i] + arrA[i]

    # Initialize the answer variable to a large value
    ans = inf
    # Iterate through the cumulative sums to find the minimum difference
    for i in range(1, n):
        # Calculate the absolute difference between the total sum and twice the current cumulative sum
        current_diff = abs(cumSumA[n] - (cumSumA[i] * 2))
        if current_diff < ans:
            # Update the answer if the current difference is smaller
            ans = current_diff

    # Print the final answer as an integer
    print(int(ans))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
