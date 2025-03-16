# Importing the necessary module for reading input
import sys

def main():
    n = int(input())  # Reading the number of elements in the array from standard input

    f = 0  # Initializing a flag variable to keep track of whether an element is found in the array
    a = list(map(int, input().split()))  # Reading the elements of the array from standard input

    # Outer loop to iterate through each element in the array
    for k in range(n):
        t = a[k]  # Storing the current element in a temporary variable

        # Inner loop to compare the current element with other elements in the array
        for i in range(n):
            # Skipping the comparison if the current index is the same as the index of the current element
            if i != k:
                for j in range(n - 1):  # Inner most loop to compare the current element with all the previous elements in the array
                    if j != i and t == (a[i] + a[j]):  # Checking if the sum of the current and previous elements is equal to the current element
                        f = 1  # Setting the flag variable to 1 if a match is found
                        break  # Exiting the inner most loop if a match is found
                if f == 1:  # Checking if the flag variable is set to 1, indicating a match is found
                    break  # Exiting the inner loop if a match is found

        if f == 1:  # Checking if the flag variable is set to 1, indicating a match is found
            print(k + 1, j + 1, i + 1)  # Printing the indices of the previous and current elements if a match is found
            f = 0  # Resetting the flag variable to 0 for the next iteration

    if f == 0:  # Checking if no match is found in the array
        print("-1")  # Printing "-1" if no match is found

if __name__ == "__main__":
    main()

# <END-OF-CODE>
