import sys

def main():
    # Reading the size of the array from user input
    a = int(input())
    ar = list(map(int, input().split()))

    # Initializing variables for storing maximum and minimum differences
    max_diff = 0
    min_diff = 0

    # Finding maximum and minimum differences between consecutive elements in the array
    for i in range(len(ar)):
        # Finding maximum difference between current element and first element
        max_diff = max(ar[i] - ar[0], ar[-1] - ar[i])

        # Finding minimum difference between current element and previous element
        if i == 0:
            min_diff = ar[i + 1] - ar[i]  # For the first element, minimum difference is between current and next element
        elif i == len(ar) - 1:
            min_diff = ar[i] - ar[i - 1]  # For the last element, minimum difference is between current and previous element
        else:
            min_diff = min(ar[i] - ar[i - 1], ar[i + 1] - ar[i])  # For other elements, minimum difference is between current and previous or next element, whichever is smaller

        # Printing minimum and maximum differences for each pair of consecutive elements
        print(min_diff, max_diff)

if __name__ == "__main__":
    main()
