import sys
from typing import List

# Class to represent the size of a matrix
class TSize:
    def __init__(self, r=0, c=0):
        self.r = r  # Number of rows
        self.c = c  # Number of columns

# Class to solve the Matrix Chain Multiplication problem
class TMcmSolver:
    def __init__(self, chain: List[TSize]):
        self.FChain = chain  # Reference to the chain of matrices
        self.FMemo = [[0] * len(chain) for _ in range(len(chain))]  # Memoization table

    # Function to calculate the cost of multiplying two matrices
    @staticmethod
    def Count(left: TSize, right: TSize) -> int:
        return left.r * right.c * left.c  # Cost = rows of Left * columns of Right * columns of Left

    # Recursive function to solve the matrix chain multiplication problem
    def Solve(self, s: int, l: int) -> int:
        assert s <= l  # Ensure the start index is less than or equal to the end index
        if s == l:
            return 0  # Base case: no cost if there is only one matrix
        if self.FMemo[s][l] != 0:
            return self.FMemo[s][l]  # Return cached result if already computed
        if s + 1 == l:
            # If there are two matrices, calculate the cost directly
            self.FMemo[s][l] = self.Count(self.FChain[s], self.FChain[l])
        else:
            min_cost = sys.maxsize  # Initialize minimum cost to maximum possible value
            # Try every possible split point to find the minimum cost
            for i in range(s, l):
                # Calculate cost of multiplying the two parts and add the cost of multiplying the resulting matrices
                c = (self.Solve(s, i) + 
                     self.Count(TSize(self.FChain[s].r, self.FChain[i].c), 
                                TSize(self.FChain[i + 1].r, self.FChain[l].c)) + 
                     self.Solve(i + 1, l))
                min_cost = min(min_cost, c)  # Update minimum cost
            self.FMemo[s][l] = min_cost  # Store the minimum cost in the memoization table
        return self.FMemo[s][l]  # Return the computed minimum cost

    # Function to get the final answer (minimum multiplication cost)
    def Answer(self) -> int:
        return self.Solve(0, len(self.FMemo) - 1)  # Solve for the entire chain

    # Function to print the memoization table (for debugging purposes)
    def Print(self):
        for s in range(len(self.FMemo)):
            for l in range(len(self.FMemo[0])):
                print(self.FMemo[s][l], end='\t')  # Print each value in the table
            print()  # New line after each row

def main():
    n = int(input())  # Input the number of matrices
    if n == 1:
        print(0)  # If there is only one matrix, no multiplication is needed
        return  # Exit the program
    
    chain = [TSize() for _ in range(n)]  # List to hold the sizes of the matrices
    for i in range(n):
        r, c = map(int, input().split())  # Input the dimensions of each matrix
        chain[i] = TSize(r, c)
    
    solver = TMcmSolver(chain)  # Create an instance of the solver with the matrix chain
    
    print(solver.Answer())  # Output the minimum multiplication cost
    # solver.Print()  # Uncomment to print the memoization table

if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
