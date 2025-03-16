# Importing the necessary module for input
import sys

def main():
    x, y, k = 0, 0, 0  # Initializing variables for coordinates and loop counter
    flag = True  # Flag to check for "BUG" pattern
    s = input().strip()  # Reading the input string
    co = [[0] * 101 for _ in range(2)]  # 2D list to store the coordinates

    co[0][k] = x  # Storing the initial x-coordinate
    co[1][k] = y  # Storing the initial y-coordinate
    k += 1  # Incrementing the counter for storing coordinates

    # Updating the positions based on the direction commands
    for char in s:
        if char == 'L':
            x -= 1  # Moving left
        elif char == 'R':
            x += 1  # Moving right
        elif char == 'U':
            y += 1  # Moving up
        elif char == 'D':
            y -= 1  # Moving down
        
        co[0][k] = x  # Storing the updated x-coordinate
        co[1][k] = y  # Storing the updated y-coordinate
        k += 1  # Incrementing the counter for storing coordinates

    # Checking for "BUG" pattern
    for i in range(k - 3):
        for j in range(i + 3, k):
            dx = abs(co[0][i] - co[0][j])  # Calculating the absolute difference in x-coordinates
            dy = abs(co[1][i] - co[1][j])  # Calculating the absolute difference in y-coordinates
            if (dx <= 1 and dy == 0) or (dy <= 1 and dx == 0):  # Checking if the movement forms a "bug" pattern
                flag = False  # Setting the flag to false if a "bug" pattern is found
                break  # Breaking out of the inner loop
        if not flag:
            break  # Breaking out of the outer loop if a "bug" pattern is found

    # Outputting the result
    if flag:
        print("OK")  # Printing "OK" if no "bug" pattern is found
    else:
        print("BUG")  # Printing "BUG" if a "bug" pattern is found

if __name__ == "__main__":
    main()

# <END-OF-CODE>
