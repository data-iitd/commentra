import sys; # Importing the sys module for input

def printIsland(n, count):
    a = (n + 1) / 2; # Calculating the number of 'L' characters in the first diagonal
    b = n / 2; # Calculating the number of 'L' characters in the second diagonal
    max = a * a + b * b; # Calculating the maximum possible number of 'L' characters

    # Checking if the requested count exceeds the maximum possible 'L' characters
    if (count > max):
        print("NO"); # Printing "NO" if count is too high
        return; # Returning from the method as further execution is unnecessary

    print("YES"); # Printing "YES" as the count is within the allowed range

    # Building the island grid
    for i in range(0, n):
        sb = ""; # Creating a StringBuilder to build the row
        for j in range(0, n):
            if ((i + j) % 2 == 0 and count > 0): # Checking if the position should be 'L'
                sb += 'L'; # Appending 'L' to the StringBuilder
                count -= 1; # Decrementing the count of 'L' characters
            else:
                sb += 'S'; # Appending 'S' to the StringBuilder
        print(sb); # Printing the constructed row

if __name__ == "__main__":
    n = int(sys.stdin.readline()); # Reading the first integer input (size of the grid)
    count = int(sys.stdin.readline()); # Reading the second integer input (number of 'L' characters)
    printIsland(n, count); # Calling the printIsland method with the inputs

# 