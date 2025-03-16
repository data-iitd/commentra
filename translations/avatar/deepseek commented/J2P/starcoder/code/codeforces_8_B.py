import sys; # Importing sys module for input

def main():
    s = sys.stdin.readline().strip(); # Reading the input string
    ch = list(s); # Converting the input string to a list of characters
    x = 0; # Initializing x-coordinate
    y = 0; # Initializing y-coordinate
    k = 0; # Initializing loop counter
    flag = True; # Flag to check for "BUG" pattern
    co = [[0 for i in range(101)] for j in range(2)]; # 2D array to store the coordinates

    co[0][k] = x; # Storing the initial x-coordinate
    co[1][k] = y; # Storing the initial y-coordinate
    k += 1; # Incrementing the counter for storing coordinates

    # Updating the positions based on the direction commands
    for i in range(len(ch)):
        if ch[i] == 'L': x -= 1; # Moving left
        elif ch[i] == 'R': x += 1; # Moving right
        elif ch[i] == 'U': y += 1; # Moving up
        elif ch[i] == 'D': y -= 1; # Moving down
        co[0][k] = x; # Storing the updated x-coordinate
        co[1][k] = y; # Storing the updated y-coordinate
        k += 1; # Incrementing the counter for storing coordinates

    # Checking for "BUG" pattern
    for i in range(k - 3):
        for j in range(i + 3, k):
            dx = co[0][i] - co[0][j]; # Calculating the difference in x-coordinates
            dy = co[1][i] - co[1][j]; # Calculating the difference in y-coordinates
            if dx < 0: dx *= -1; # Taking the absolute value of dx
            if dy < 0: dy *= -1; # Taking the absolute value of dy
            if (dx <= 1 and dy == 0) or (dy <= 1 and dx == 0): # Checking if the movement forms a "bug" pattern
                flag = False; # Setting the flag to false if a "bug" pattern is found
                break; # Breaking out of the inner loop
        if not flag: break; # Breaking out of the outer loop if a "bug" pattern is found

    # Outputting the result
    if flag: print("OK"); # Printing "OK" if no "bug" pattern is found
    else print("BUG"); # Printing "BUG" if a "bug" pattern is found

if __name__ == "__main__":
    main(); # Calling the main function

