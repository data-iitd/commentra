# Importing the necessary module for taking input from the user
import sys

def main():
    a = int(input())  # Reading the size of the array from the user
    ar = [int(input()) for _ in range(a)]  # Initializing the array with the size read from the user
    max_diff = 0
    min_diff = 0

    # Calculating the minimum and maximum differences between consecutive elements of the array
    for i in range(len(ar)):
        max_diff = max(ar[i] - ar[0], ar[-1] - ar[i])  # Calculating the maximum difference
        if i == 0:
            min_diff = ar[i + 1] - ar[i]  # Calculating the minimum difference for the first element
        elif i == len(ar) - 1:
            min_diff = ar[i] - ar[i - 1]  # Calculating the minimum difference for the last element
        else:
            min_diff = min(ar[i] - ar[i - 1], ar[i + 1] - ar[i])  # Calculating the minimum difference for other elements
        print(min_diff, max_diff)  # Displaying the minimum and maximum differences

if __name__ == "__main__":
    main()

# <END-OF-CODE>
