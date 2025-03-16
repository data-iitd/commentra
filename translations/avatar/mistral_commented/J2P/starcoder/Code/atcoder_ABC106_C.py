
# Importing the Python's built-in input() function to read input from the console
# Importing the Python's built-in print() function to print output to the console

str = input() # Reading the first line of input as a String
c = str.split() # Converting the String to a character array
k = int(input()) # Reading the second line of input as a long integer
n = len(str) # Finding the length of the String

for i in range(k): # Starting a for loop to iterate through the character array up to the given limit 'k'
    if c[i] == '1': # Checking if the current character is '1'
        if i == k - 1: # Checking if the current index is the last index of the array
            print(1) # If yes, print '1' and exit the method
            break
    else:
        print(c[i]) # If the current character is not '1', print it to the console
        break # Exit the method as soon as a non-'1' character is found

# 