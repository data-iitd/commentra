

import sys # Importing sys module for handling command line arguments

def solve(x, u):
    return sum(x[i] * (1 if u[i] == "JPY" else 380000) for i in range(len(x))) # Using a list comprehension to calculate the sum of products of double values and their respective currency conversion factors

if __name__ == "__main__":
    N = int(sys.argv[1]) # Reading the number of elements from the command line argument
    x = [float(x) for x in sys.argv[2:N+2]] # Converting the command line arguments for double values to a list
    u = sys.argv[N+2:] # Extracting the currency strings from the command line arguments

    print(solve(x, u)) # Calling the'solve' function and printing the result

