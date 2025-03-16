# Import the necessary module for input
import sys

def main():
    # Initialize variables for coordinates and control flags
    x, y, k = 0, 0, 0
    flag = True
    
    # Create a list to store coordinates
    co = [[0] * 101 for _ in range(2)]
    
    # Read the input string from the user
    s = input().strip()
    
    # Store the initial coordinates (0, 0) in the coordinates list
    co[0][k] = x
    co[1][k] = y
    k += 1  # Increment the index for the next coordinate
    
    # Process each character in the input string to update coordinates
    for char in s:
        if char == 'L':  # Move left
            x -= 1
        elif char == 'R':  # Move right
            x += 1
        elif char == 'U':  # Move up
            y += 1
        elif char == 'D':  # Move down
            y -= 1
        
        # Store the updated coordinates in the list
        co[0][k] = x
        co[1][k] = y
        k += 1  # Increment the index for the next coordinate
    
    # Check for any bugs in the movement path
    for i in range(k - 3):
        for j in range(i + 3, k):
            # Calculate the differences in x and y coordinates
            dx = abs(co[0][i] - co[0][j])
            dy = abs(co[1][i] - co[1][j])
            
            # Check if the two points are too close to each other
            if (dx <= 1 and dy == 0) or (dy <= 1 and dx == 0):
                flag = False  # Set flag to false if a bug is found
                break  # Exit the inner loop
        if not flag:
            break  # Exit the outer loop if a bug is found
    
    # Output the result based on the flag status
    if flag:
        print("OK")  # No bugs found
    else:
        print("BUG")  # Bugs found in the movement path

if __name__ == "__main__":
    main()

# <END-OF-CODE>
