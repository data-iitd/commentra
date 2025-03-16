
import sys; # Importing the'sys' module for reading the input

def solve(x, u):
    return sum(x[i] * (1 if u[i] == "JPY" else 380000) for i in range(len(x))) # Using list comprehension to find the sum of products of double values and their respective currency conversion factors

if __name__ == "__main__":
    N = int(sys.stdin.readline()) # Reading the number of elements from the user input
    x = [float(sys.stdin.readline()) for _ in range(N)] # Declaring and initializing a list 'x' of size 'N' to store the double values
    u = [sys.stdin.readline().strip() for _ in range(N)] # Declaring and initializing a list 'u' of size 'N' to store the currency strings

    print(solve(x, u)) # Calling the'solve' method to find the sum of products of double values and their respective currency conversion factors

