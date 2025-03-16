# Import necessary libraries
import sys

def main():
    n = int(sys.stdin.readline().strip())  # Read the number of elements from standard input
    h = list(map(int, sys.stdin.readline().strip().split()))  # Read heights of elements into a list
    max_height = -1  # Initialize max_height to -1 to store the maximum height found
    flag = 0  # Initialize flag to 0 to indicate whether the condition is met

    # Loop to update the maximum height found
    for height in h:
        if max_height < height:
            max_height = height  # Update max_height if the current height is greater than max_height

        if max_height - height >= 2:
            flag = 1  # Check if the difference between max_height and current height is at least 2

    if flag == 1:
        print("No")  # Print "No" if the condition is met
    else:
        print("Yes")  # Print "Yes" if the condition is not met

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
