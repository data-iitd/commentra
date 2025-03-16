def main():
    # Create a Scanner object to read input from the user (Python uses input() instead of Scanner)
    s = input()
    
    # Initialize variables for coordinates and control flags
    x, y = 0, 0
    k = 0
    flag = True
    
    # Declare variables for input string and character array
    ch = list(s)
    
    # Create a 2D array to store coordinates
    co = [[0 for _ in range(101)] for _ in range(2)]
    
    # Store the initial coordinates (0, 0) in the coordinates array
    co[0][k] = x
    co[1][k] = y
    k += 1  # Increment the index for the next coordinate
    
    # Process each character in the input string to update coordinates
    for i in range(len(s)):
        if ch[i] == 'L':  # Move left
            x -= 1
        elif ch[i] == 'R':  # Move right
            x += 1
        elif ch[i] == 'U':  # Move up
            y += 1
        elif ch[i] == 'D':  # Move down
            y -= 1
        
        # Store the updated coordinates in the array
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
