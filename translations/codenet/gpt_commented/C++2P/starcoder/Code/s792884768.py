#include <cassert> # For assert function to validate assumptions
#include <algorithm> # Not used in this code
#include <iostream> # For input and output operations
#include <vector> # For using the vector container
#include <climits> # For INT_MAX constant

# Structure to represent the size of a matrix
class TSize:
    def __init__(self):
        self.r = 0 # Number of rows
        self.c = 0 # Number of columns
    def __init__(self, Ar, Ac): # Parameterized constructor to initialize with given values
        self.r = Ar
        self.c = Ac

# Class to solve the Matrix Chain Multiplication problem
class TMcmSolver:
    def __init__(self, Chain):
        self.FMemo = [] # Memoization table to store intermediate results
        self.FChain = Chain # Reference to the chain of matrices

        # Function to calculate the cost of multiplying two matrices
        def Count(Left, Right):
            return Left.r * Right.c * Left.c # Cost = rows of Left * columns of Right * columns of Left

        # Recursive function to solve the matrix chain multiplication problem
        def Solve(s, l):
            assert(s <= l) # Ensure the start index is less than or equal to the end index
            if(s == l): return 0 # Base case: no cost if there is only one matrix
            if(self.FMemo[s][l]!= 0): return self.FMemo[s][l] # Return cached result if already computed
            if(s + 1 == l):
                # If there are two matrices, calculate the cost directly
                self.FMemo[s][l] = Count(self.FChain[s], self.FChain[l])
            else:
                min = INT_MAX # Initialize minimum cost to maximum possible value
                # Try every possible split point to find the minimum cost
                for i in range(s, l):
                    # Calculate cost of multiplying the two parts and add the cost of multiplying the resulting matrices
                    c = Solve(s, i) + Count(TSize(self.FChain[s].r, self.FChain[i].c), TSize(self.FChain[i+1].r, self.FChain[l].c)) + Solve(i+1, l)
                    min = min if min < c else c # Update minimum cost
                self.FMemo[s][l] = min # Store the minimum cost in the memoization table
            return self.FMemo[s][l] # Return the computed minimum cost

        # Constructor to initialize the solver with a chain of matrices
        self.FMemo = [[0 for i in range(len(Chain))] for j in range(len(Chain))]
        self.Solve = Solve

    # Function to get the final answer (minimum multiplication cost)
    def Answer(self):
        return self.Solve(0, len(self.FMemo)-1) # Solve for the entire chain

    # Function to print the memoization table (for debugging purposes)
    def Print(self):
        for s in range(len(self.FMemo)):
            for l in range(len(self.FMemo[0])):
                print(self.FMemo[s][l], end='\t') # Print each value in the table
            print() # New line after each row

if __name__ == "__main__":
    n = int(input()) # Number of matrices
    if(n == 1):
        print(0) # If there is only one matrix, no multiplication is needed
        exit(0) # Exit the program
    
    Chain = [] # Vector to hold the sizes of the matrices
    for i in range(n):
        r, c = map(int, input().split()) # Input the dimensions of each matrix
        Chain.append(TSize(r, c))

    Solver = TMcmSolver(Chain) # Create an instance of the solver with the matrix chain
    
    print(Solver.Answer()) # Output the minimum multiplication cost
    # Solver.Print() # Uncomment to print the memoization table

