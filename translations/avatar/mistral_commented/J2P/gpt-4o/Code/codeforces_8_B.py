# Importing the necessary module for reading input
import sys

def main():  # Defining the main function
    x, y, k = 0, 0, 0  # Declaring and initializing variables
    flag = True  # Declaring and initializing a boolean variable
    s = input()  # Reading the input string from the console
    co = [[0] * 101 for _ in range(2)]  # Declaring and initializing a 2D list of size 2 x 101

    co[0][k] = x
    co[1][k] = y
    k += 1  # Incrementing the size of the array

    for char in s:  # Loop to iterate through each character in the string
        if char == 'L':  # Move x to the left
            x -= 1
        elif char == 'R':  # Move x to the right
            x += 1
        elif char == 'U':  # Move y up
            y += 1
        elif char == 'D':  # Move y down
            y -= 1
        
        co[0][k] = x  # Updating the current position in the array
        co[1][k] = y
        k += 1  # Incrementing the size of the array

    for i in range(k - 3):  # Outer loop to iterate through all elements except the last three
        for j in range(i + 3, k):  # Inner loop to compare the current element with the next three elements
            dx = abs(co[0][i] - co[0][j])  # Calculate the difference in x-coordinates
            dy = abs(co[1][i] - co[1][j])  # Calculate the difference in y-coordinates
            if (dx <= 1 and dy == 0) or (dy <= 1 and dx == 0):  # Checking if the difference is within 1 unit in either x or y direction
                flag = False  # Setting the flag to false if a difference of 1 unit is found
                break  # Exiting the inner loop if a difference of 1 unit is found
        if not flag:  # Exiting the outer loop if a difference of 1 unit is found in any of the inner loops
            break

    print("OK" if flag else "BUG")  # Printing "OK" if no difference of 1 unit is found, otherwise printing "BUG"

if __name__ == "__main__":
    main()  # Calling the main function

# <END-OF-CODE>
