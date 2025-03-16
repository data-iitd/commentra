import sys

def main():
    # Reading the number of elements in the array from the standard input
    N = int(input().strip())
    # Reading the elements of the array from the standard input
    A = list(map(int, input().strip().split()))

    count = 0  # Initializing the count variable to zero

    # Iterating through the array to find the number of increasing and decreasing sequences
    i = 0
    while i < N - 1:
        if A[i] == A[i + 1]:  # If the current and next elements are equal, do nothing
            i += 1
        elif A[i] < A[i + 1]:  # If the current element is less than the next element
            while i < N - 1 and A[i] <= A[i + 1]:  # Finding the length of the increasing sequence
                i += 1
            count += 1  # Increment the count after finding the length of the increasing sequence
        else:  # If the current element is greater than the next element
            while i < N - 1 and A[i] >= A[i + 1]:  # Finding the length of the decreasing sequence
                i += 1
            count += 1  # Increment the count after finding the length of the decreasing sequence
        i += 1

    # Printing the final count
    print(count)

if __name__ == "__main__":
    main()

