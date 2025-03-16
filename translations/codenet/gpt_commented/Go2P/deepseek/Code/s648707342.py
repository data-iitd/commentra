import sys

# Function to read an integer from input
def read_int():
    return int(sys.stdin.readline().strip())

# Initialize the input to split by whitespace
sys.stdin.readline()

# Main function where the program execution begins
def main():
    # Read the number of arms
    n = read_int()
    
    # Define a class to represent an arm with left and right bounds
    class Arm:
        def __init__(self, center, length):
            self.l = center - length  # Calculate the left bound
            self.r = center + length  # Calculate the right bound
    
    # Create a list to hold the arms
    arms = []
    
    # Read the arm data from input
    for _ in range(n):
        center, length = map(int, sys.stdin.readline().strip().split())
        arms.append(Arm(center, length))
    
    # Sort the arms based on their right bounds
    arms.sort(key=lambda arm: arm.r)

    # Initialize the count of non-overlapping arms and the rightmost bound
    ans = 1  # Start with the first arm
    r = arms[0].r  # Set the rightmost bound to the right of the first arm
    
    # Iterate through the sorted arms to count non-overlapping arms
    for i in range(1, n):
        # If the left bound of the current arm is greater than or equal to the rightmost bound
        if arms[i].l >= r:
            ans += 1  # Increment the count of non-overlapping arms
            r = arms[i].r  # Update the rightmost bound to the current arm's right bound
    
    # Print the total count of non-overlapping arms
    print(ans)

# Call the main function
main()

