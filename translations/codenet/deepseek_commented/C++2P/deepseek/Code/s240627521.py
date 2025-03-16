import sys

def main():
    N = int(input())  # Read the number of elements in the array A
    A = list(map(int, input().split()))  # Read the elements of the array A
    A.sort(reverse=True)  # Sort the array A in descending order
    max_diff = float('inf')  # Initialize max_diff with a large value
    index = -1

    # Iterate through the array to find the optimal pair
    for i in range(1, N):
        diff = abs(A[0] - 2 * A[i])
        if diff < max_diff:  # Check if the current difference is smaller than the previous minimum
            max_diff = diff  # Update the minimum difference
            index = i  # Store the index of the current element

    print(A[0], A[index])  # Output the first and the found optimal pair

if __name__ == "__main__":
    main()
