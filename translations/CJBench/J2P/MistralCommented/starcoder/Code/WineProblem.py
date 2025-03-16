import sys; # Importing the sys module for reading input from the console

def wpbu(arr): # Defining a function named wpbu to find the maximum profit using the WPP algorithm
    if arr == None or len(arr) == 0: # Checking if the input array is null or empty
        raise Exception("Input array cannot be null or empty.");

    n = len(arr); # Assigning the length of the array to a variable

    if n == 1: # Special case for arrays with only one element
        return arr[0] * (n + 1);

    strg = [[0 for i in range(n)] for j in range(n)]; # Creating a 2D array to store intermediate results

    for slide in range(0, n): # Iterating through all possible sliding windows
        for si in range(0, n - slide): # Iterating through all possible starting indices
            ei = si + slide; # Calculating the ending index of the current window
            year = n - (ei - si) + 1; # Calculating the number of years in the current window

            if si == ei: # Base case for a single element window
                strg[si][ei] = arr[si] * year;
            else: # Recursive case for a window with more than one element
                start = strg[si + 1][ei] + arr[si] * year; # Maximum profit for the subarray from si+1 to ei
                end = strg[si][ei - 1] + arr[ei] * year; # Maximum profit for the subarray from si to ei-1
                strg[si][ei] = max(start, end); # Choosing the maximum profit between the two subarrays
    return strg[0][n - 1]; # Returning the maximum profit for the entire array

if __name__ == "__main__": # Main method to start the program
    n = int(sys.stdin.readline()); # Reading the number of elements in the array from user input

    if n <= 0: # Checking if the input is valid
        print("Invalid input. Please enter a positive integer.");
        sys.exit();

    arr = [int(x) for x in sys.stdin.readline().split()]; # Reading elements of the array from user input

    result = wpbu(arr); # Calling the wpbu method to find the maximum profit

    print("Maximum profit: " + str(result)); # Printing the maximum profit to the console

