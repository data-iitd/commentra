import sys

# Function to read an integer from input
def scan_int():
    return int(sys.stdin.readline().strip())

# Main function where the program execution begins
def main():
    # Read the number of arms
    n = scan_int()
    
    # Create a list to hold the arms as tuples of (left, right)
    arms = []
    
    # Read the arm data from input
    for _ in range(n):
        x, l = map(int, sys.stdin.readline().strip().split())  # Read the center and length of the arm
        arms.append((x - l, x + l))  # Calculate the left and right bounds and store them
    
    # Sort the arms based on their right bounds
    arms.sort(key=lambda arm: arm[1])

    # Initialize the count of non-overlapping arms and the rightmost bound
    ans = 1  # Start with the first arm
    r = arms[0][1]  # Set the rightmost bound to the right of the first arm
    
    # Iterate through the sorted arms to count non-overlapping arms
    for i in range(1, n):
        # If the left bound of the current arm is greater than or equal to the rightmost bound
        if arms[i][0] >= r:
            ans += 1  # Increment the count of non-overlapping arms
            r = arms[i][1]  # Update the rightmost bound to the current arm's right bound
    
    # Print the total count of non-overlapping arms
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
