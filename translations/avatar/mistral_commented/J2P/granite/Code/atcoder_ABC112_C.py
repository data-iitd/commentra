
import sys ;  # Importing the sys module for handling input and output

def main():  # Main function to start the program
    n = int(input()) ;  # Reading the number of elements n from the standard input
    x = [] ;  y = [] ;  h = [] ;  # Creating empty lists x, y, and h to store the input values

    for i in range(n):  # Loop to read and initialize the arrays x, y, and h
        x.append(int(input())) ;
        y.append(int(input())) ;
        h.append(int(input())) ;

    for i in range(MAX + 1):  # Outer loop to iterate through all possible positions (i, j)
        for j in range(MAX + 1):  # Inner loop to check all possible positions (i, j)
            ch = check(n, x, y, h, i, j) ;  # Calling the check function to calculate the height of the water at position (i, j)
            if ch > 0:  # If the height is greater than 0, print the position and height
                print(i, j, ch) ;

def check(n, x, y, h, cx, cy):  # Function to check the height of water at position (cx, cy)
    ch = -1 ;  # Initializing the height to -1

    for i in range(n):  # Loop to iterate through all elements in the arrays x, y, and h
        if h[i] > 0:  # If the height of the current element is greater than 0
            ch = abs(x[i] - cx) + abs(y[i] - cy) + h[i] ;  # Calculate the distance and height of the current element and update the height if it's closer
            break ;  # Exit the loop once the closest element is found

    for i in range(n):  # Loop to check if all elements have the same height as the closest one
        if h[i]!= max(ch - abs(x[i] - cx) - abs(y[i] - cy), 0):  # If the height is different, return -1 to indicate an error
            return -1 ;

    return ch ;  # Return the height of the water at position (cx, cy)

if __name__ == "__main__":  # Main block to execute the main function
    main() ;  # Call the main function to start the program

