# Function to calculate the absolute value of a number
def abs_value(x):
    return -x if x < 0 else x

def main():
    # Read the number of test cases
    N = int(input())
    
    # Initialize variables
    nx, ny, nt = 0, 0, 0
    
    # Loop through each test case
    for _ in range(N):
        # Read the time and coordinates for each test case
        t, x, y = map(int, input().split())
        
        # Calculate the time left after accounting for the previous time and the distance traveled
        tmp = t - nt - (abs_value(x - nx) + abs_value(y - ny))
        
        # Check if the remaining time is negative or odd
        if tmp < 0 or tmp % 2:
            # If so, print "No" and exit the program
            print("No")
            return
        
        # Update the current position and time for the next iteration
        nt = t  # Update the previous time
        nx = x  # Update the previous x coordinate
        ny = y  # Update the previous y coordinate
    
    # If all test cases are valid, print "Yes"
    print("Yes")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
