
import sys

def main():
    x, y, k = 0, 0, 0 # Initializing variables for coordinates and loop counters
    flag = True # Flag to check for "BUG" pattern
    s = input() # Reading the input string
    co = [[x, y]] # 2D list to store the coordinates
    k += 1 # Incrementing the counter for storing coordinates

    # Updating the positions based on the direction commands
    for i in range(len(s)):
        if s[i] == 'L': x -= 1 # Moving left
        elif s[i] == 'R': x += 1 # Moving right
        elif s[i] == 'U': y += 1 # Moving up
        elif s[i] == 'D': y -= 1 # Moving down
        co.append([x, y]) # Storing the updated coordinates
        k += 1 # Incrementing the counter for storing coordinates

    # Checking for "BUG" pattern
    for i in range(k - 3):
        for j in range(i + 3, k):
            dx = abs(co[i][0] - co[j][0]) # Calculating the absolute difference in x-coordinates
            dy = abs(co[i][1] - co[j][1]) # Calculating the absolute difference in y-coordinates
            if (dx <= 1 and dy == 0) or (dy <= 1 and dx == 0): # Checking if the movement forms a "bug" pattern
                flag = False # Setting the flag to false if a "bug" pattern is found
                break # Breaking out of the inner loop
        if not flag: break # Breaking out of the outer loop if a "bug" pattern is found

    # Outputting the result
    if flag: print("OK") # Printing "OK" if no "bug" pattern is found
    else: print("BUG") # Printing "BUG" if a "bug" pattern is found

if __name__ == "__main__":
    main()

