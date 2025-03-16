# Import necessary libraries
import sys

def main():
    n = int(input())  # Input the number of elements
    a = list(map(int, input().split()))  # Read n elements into the list a

    avg = sum(a) / n  # Calculate the average of the elements

    s = abs(a[0] - avg)  # Initialize the smallest difference with the absolute difference of the first element from the average
    ans = 0  # Initialize the index of the closest element to the first element

    # Loop to find the index of the element closest to the average
    for i in range(1, n):
        # Check if the current element's difference from the average is smaller than the smallest found so far
        if s > abs(a[i] - avg):
            s = abs(a[i] - avg)  # Update the smallest difference
            ans = i  # Update the index of the closest element

    # Output the index of the element closest to the average
    print(ans)

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
