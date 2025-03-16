# Import necessary libraries
import sys

# Define a function to read input
def read_input():
    return sys.stdin.read().splitlines()

# Main function
def main():
    # Read height and width of the grid
    h, w = map(int, input().split())

    # Target string
    target = "snuke"

    # Iterate through the grid to find the target string
    for i in range(h):
        for j in range(w):
            # Read the current string from input
            current_string = input().strip()
            # Check if the current string matches the target string
            if current_string == target:
                # If found, calculate the position and print it
                column_char = chr(ord('A') + j)  # Convert column index to character
                print(f"{column_char}{i + 1}")  # Output the position in the required format
                return  # Exit the function after finding the target

# Execute the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
