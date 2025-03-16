def main():
    n = int(input())  # Read the number of elements
    h = list(map(int, input().split()))  # Read the heights of elements
    max_height = -1  # Initialize max_height to -1 to store the maximum height found
    flag = 0  # Initialize flag to 0 to indicate whether the condition is met

    # Loop to find the maximum height and check the condition
    for height in h:
        if max_height < height:
            max_height = height  # Update max_height if the current height is greater than max_height

        if max_height - height >= 2:
            flag = 1  # Set flag to 1 if the difference between max_height and current height is at least 2

    # Print the result based on the flag value
    print("No" if flag == 1 else "Yes")

# Call the main function
main()
