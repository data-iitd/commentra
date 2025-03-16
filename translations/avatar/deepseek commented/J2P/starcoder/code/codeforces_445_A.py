
# Importing the necessary classes for input/output operations
import sys

# Main method to execute the program
def main():
    inp = sys.stdin.readline().split() # Reading the first line and splitting it into an array of characters
    n = int(inp[0]) # Extracting the integer n from the input array
    m = int(inp[1]) # Extracting the integer m from the input array

    ans = [] # Initializing an array to store the resulting strings

    for i in range(n): # Looping through each row
        str = sys.stdin.readline() # Reading the current row as a string
        temp = "" # Creating a string to build the resulting string for the current row

        for j in range(m): # Looping through each character in the row
            if str[j] == '-': # Checking if the character is a '-'
                temp += "-" # Appending '-' to the string
            else:
                if ((i + j) % 2 == 1): # Checking if the sum of indices is odd
                    temp += "W" # Appending 'W' if the sum is odd
                else:
                    temp += "B" # Appending 'B' if the sum is even
        ans.append(temp) # Appending the string to the ans array

    for i in range(n): # Looping through each row again to print the results
        print(ans[i]) # Printing the resulting string for the current row

# Calling the main method
if __name__ == "__main__":
    main()

