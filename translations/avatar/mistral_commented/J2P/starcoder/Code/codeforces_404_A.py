
# Importing the Scanner class from the Java Util library
from java.util import Scanner

# Main method is the entry point of the Python application
if __name__ == '__main__':
    # Creating a new Scanner object to read input from the standard input stream
    sc = Scanner(System.in)

    # Reading the number of rows and columns of the 2D char array from the standard input stream
    n = sc.nextInt()

    # Allocating memory for the 2D char array and the String array
    arr = [[0 for i in range(n)] for j in range(n)]
    str = [0 for i in range(n)]

    # Reading the strings from the standard input stream and storing them in the String array
    for i in range(n):
        str[i] = sc.next()

    # Converting each String to a 2D char array and storing it in the corresponding position of the 2D char array
    for i in range(n):
        for j in range(n):
            arr[i][j] = str[i][j]

    # Initializing two variables 'a' and 'b' with the characters at the first position of the first row of the 2D char array
    a = arr[0][0]
    b = arr[0][1]

    # Checking if the first characters of the first row are equal or not
    if a == b:
        print("NO") # Printing "NO" if they are equal
    else:
        res = True # Initializing a boolean variable'res' to true

        # Checking if there exists any pair of distinct characters in the 2D char array such that they form a diagonal line
        for i in range(n):
            for j in range(n):
                # Checking if the current pair (i, j) and (j, i) form a diagonal line
                if (i == j or i + j == n - 1):
                    # Checking if the characters at the current position of the 2D char array are equal to 'a' or 'b'
                    if (arr[i][j]!= a):
                        res = False # Setting'res' to false if any pair of distinct characters is found on a diagonal line
                        break # Exiting the inner loop as soon as a pair of distinct characters is found
                else:
                    # Checking if the characters at the current position of the 2D char array are equal to 'b'
                    if (arr[i][j]!= b):
                        res = False # Setting'res' to false if any character other than 'a' or 'b' is found at a position not on a diagonal line
                        break # Exiting the inner loop as soon as a character other than 'a' or 'b' is found

        # Printing "YES" if all the characters in the 2D char array form either a single diagonal line of 'a's and 'b's or two separate diagonal lines of 'a's and 'b's
        if (res):
            print("YES")
        else:
            print("NO") # Printing "NO" if any character other than 'a' or 'b' is found at a position not on a diagonal line

# 