def abs_value(x):
    return -x if x < 0 else x  # Function to calculate the absolute value of a number

def main():
    N = int(input())  # Read the number of test cases
    nx, ny, nt = 0, 0, 0  # Variables to store the previous coordinates

    # Loop through each test case
    for _ in range(N):
        t, x, y = map(int, input().split())  # Read the current test case data (t, x, y)

        # Calculate the temporary variable 'tmp' to check the distance between the current and previous coordinates
        tmp = t - nt - (abs_value(x - nx) + abs_value(y - ny))

        # Check if the current test case satisfies the condition
        if tmp < 0 or tmp % 2:
            # If the condition is not satisfied, print 'No' and exit the program
            print("No")
            return

        # Update the previous coordinates for the next iteration
        nx, ny, nt = x, y, t

    # If all the test cases satisfy the condition, print 'Yes'
    print("Yes")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
