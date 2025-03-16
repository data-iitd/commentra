# Include the standard input-output library

def abs_value(x):  # Define a function to return the absolute value of a number
    return -x if x < 0 else x

def main():  # Start of the main function
    N = int(input())  # Read the number of movements from the standard input
    nx, ny, nt = 0, 0, 0  # Initialize the current positions and starting time

    for _ in range(N):  # Start a loop that runs N times
        t, x, y = map(int, input().split())  # Read the time and coordinates for each movement
        tmp = t - nt - (abs_value(x - nx) + abs_value(y - ny))  # Calculate the difference

        if tmp < 0 or tmp % 2:  # Check if the difference is less than 0 or if it is odd
            print("No")  # Output "No" and terminate the program
            return

        nx, ny, nt = x, y, t  # Update the current coordinates and time

    print("Yes")  # If the loop completes without issues, output "Yes"

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
