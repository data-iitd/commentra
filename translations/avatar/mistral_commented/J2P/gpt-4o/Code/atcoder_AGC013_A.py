# Importing the necessary module for input
import sys

def main():  # Defining the main function
    N = int(input())  # Reading the number of elements in the array from the standard input
    A = list(map(int, input().split()))  # Reading the elements of the array from the standard input

    count = 0  # Initializing the count variable to zero

    # Iterating through the array to find the number of increasing and decreasing sequences
    i = 0
    while i < N - 1:  # Iterating up to the second last index of the array
        if i == N - 1: 
            count += 1  # If we have reached the last index, increment the count
            break
        elif A[i] == A[i + 1]:  # If the current and next elements are equal, do nothing
            i += 1
        elif A[i] < A[i + 1]:  # If the current element is less than the next element
            while i < N - 1 and A[i] <= A[i + 1]:  # Finding the length of the increasing sequence
                i += 1
            count += 1  # Increment the count after finding the length of the increasing sequence
        else:  # If the current element is greater than the next element
            while i < N - 1 and A[i] >= A[i + 1]:  # Finding the length of the decreasing sequence
                i += 1
            count += 1  # Increment the count after finding the length of the decreasing sequence

    print(count)  # Printing the final count

if __name__ == "__main__":
    main()  # Calling the main function

# <END-OF-CODE>
