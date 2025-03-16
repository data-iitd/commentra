
import sys

# Define a constant for a large number to represent infinity
inf = 100000000000

def main():
    # Read the number of elements in the array
    n = int(input())

    # Read the input values into a list
    arrA = list(map(int, input().split()))

    # Create a cumulative sum list to store the cumulative sums of arrA
    cumSumA = [0] * (n + 1)
    cumSumA[0] = 0  # The first element is 0 (sum of zero elements)
    # Calculate the cumulative sums
    for i, a in enumerate(arrA):
        cumSumA[i + 1] = cumSumA[i] + a

    # Initialize the answer variable to a large value
    ans = inf
    # Iterate through the cumulative sums to find the minimum difference
    for i in range(1, n):
        # Calculate the absolute difference between the total sum and twice the current cumulative sum
        if abs(cumSumA[n] - cumSumA[i] * 2) < ans:
            # Update the answer if the current difference is smaller
            ans = abs(cumSumA[n] - cumSumA[i] * 2)

    # Print the final answer as an integer
    print(int(ans))

if __name__ == "__main__":
    main()

