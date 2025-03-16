
import sys # Importing the necessary module for input/output operations

def main(): # Main function to execute the program
    n, m = map(int, sys.stdin.readline().split()) # Reading the first line and splitting it into two integers n and m
    ans = [""] * n # Initializing a list to store the resulting strings

    for i in range(n): # Looping through each row
        str = sys.stdin.readline().strip() # Reading the current row as a string
        temp = "" # Initializing an empty string to build the resulting string for the current row

        for j in range(m): # Looping through each character in the row
            if str[j] == '-': # Checking if the character is a '-'
                temp += "-" # Appending '-' to the resulting string
            else:
                if (i + j) % 2 == 1: # Checking if the sum of indices is odd
                    temp += "W" # Appending 'W' if the sum is odd
                else:
                    temp += "B" # Appending 'B' if the sum is even
        ans[i] = temp # Storing the resulting string in the ans list

    for i in range(n): # Looping through each row again to print the results
        print(ans[i]) # Printing the resulting string for the current row

if __name__ == "__main__": # Executing the main function if the script is run directly
    main() # Calling the main function

