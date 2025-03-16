import java.util.*;

// Class to solve the Matrix Chain Multiplication problem
class TMcmSolver
{
    // Structure to represent the size of a matrix
    static class TSize
    {
        int r; // Number of rows
        int c; // Number of columns
        TSize() { r = 0; c = 0; } // Default constructor initializing rows and columns to 0
        TSize(int Ar, int Ac) { r = Ar; c = Ac; } // Parameterized constructor to initialize with given values
    }

    // Function to calculate the cost of multiplying two matrices
    static int Count(TSize Left, TSize Right)
    {
        return Left.r * Right.c * Left.c; // Cost = rows of Left * columns of Right * columns of Left
    }

    // Recursive function to solve the matrix chain multiplication problem
    int Solve(int s, int l)
    {
        assert(s <= l); // Ensure the start index is less than or equal to the end index
        if(s == l) return 0; // Base case: no cost if there is only one matrix
        if(s + 1 == l){
            // If there are two matrices, calculate the cost directly
            return Count(Chain[s], Chain[l]);
        }else{
            int min = Integer.MAX_VALUE; // Initialize minimum cost to maximum possible value
            // Try every possible split point to find the minimum cost
            for(int i = s; i < l; ++i){
                // Calculate cost of multiplying the two parts and add the cost of multiplying the resulting matrices
                int c = Solve(s, i) + Count(new TSize(Chain[s].r, Chain[i].c), new TSize(Chain[i+1].r, Chain[l].c)) + Solve(i+1, l);
                min = Math.min(min, c); // Update minimum cost
            }
            return min; // Return the computed minimum cost
        }
    }

    // Constructor to initialize the solver with a chain of matrices
    TMcmSolver(TSize[] Chain)
    {
        this.Chain = Chain;
    }

    // Function to get the final answer (minimum multiplication cost)
    int Answer()
    {
        return Solve(0, Chain.length-1); // Solve for the entire chain
    }

    // Function to print the memoization table (for debugging purposes)
    void Print()
    {
        for(int s = 0; s < Chain.length; ++s){
            for(int l = 0; l < Chain.length; ++l){
                System.out.print(Memo[s][l] + "\t"); // Print each value in the table
            }
            System.out.println(); // New line after each row
        }
    }

    TSize[] Chain; // Reference to the chain of matrices
    int[][] Memo; // Memoization table to store intermediate results
}

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // Number of matrices
        if(n == 1){
            System.out.println(0); // If there is only one matrix, no multiplication is needed
            return; // Exit the program
        }
        
        TSize[] Chain = new TSize[n]; // Vector to hold the sizes of the matrices
        for(int i = 0; i < n; ++i){
            Chain[i] = new TSize(sc.nextInt(), sc.nextInt()); // Input the dimensions of each matrix
        }
        
        TMcmSolver Solver = new TMcmSolver(Chain); // Create an instance of the solver with the matrix chain
        
        System.out.println(Solver.Answer()); // Output the minimum multiplication cost
        // Solver.Print(); // Uncomment to print the memoization table
    }
}
