
import sys

def main():
    # Create a list to store coordinates
    co = [[0, 0]]
    
    # Read the input string from the user
    s = input()
    
    # Process each character in the input string to update coordinates
    for ch in s:
        if ch == 'L': # Move left
            co[-1][0] -= 1
        elif ch == 'R': # Move right
            co[-1][0] += 1
        elif ch == 'U': # Move up
            co[-1][1] += 1
        elif ch == 'D': # Move down
            co[-1][1] -= 1
        # Store the updated coordinates in the list
        co.append([co[-1][0], co[-1][1]])
    
    # Check for any bugs in the movement path
    for i in range(len(co) - 3):
        for j in range(i + 3, len(co)):
            # Calculate the differences in x and y coordinates
            dx = abs(co[i][0] - co[j][0])
            dy = abs(co[i][1] - co[j][1])
            
            # Check if the two points are too close to each other
            if dx <= 1 and dy <= 1:
                print("BUG") # Output "BUG" if a bug is found
                sys.exit() # Exit the program
    
    print("OK") # Output "OK" if no bugs are found

if __name__ == "__main__":
    main()

