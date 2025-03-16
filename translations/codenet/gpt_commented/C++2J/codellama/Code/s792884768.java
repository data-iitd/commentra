// <START-OF-CODE>
import java.util.Scanner;

// Structure to represent the size of a matrix
class Size
{
    int r; // Number of rows
    int c; // Number of columns
    Size() // Default constructor initializing rows and columns to 0
    {
        r = 0;
        c = 0;
    }
    Size(int Ar, int Ac) // Parameterized constructor to initialize with given values
    {
        r = Ar;
        c = Ac;
    }
}

// Class to solve the Matrix Chain Multiplication problem
class McmSolver
{
    int[][] memo; // Memoization table to store intermediate results
    Size[] chain; // Array to hold the sizes of the matrices

    // Function to calculate the cost of multiplying two matrices
    static int count(Size left, Size right)
    {
        return left.r * right.c * left.c; // Cost = rows of Left * columns of Right * columns of Left
    }

    // Recursive function to solve the matrix chain multiplication problem
    int solve(int s, int l)
    {
        assert s <= l; // Ensure the start index is less than or equal to the end index
        if(s == l) return 0; // Base case: no cost if there is only one matrix
        if(memo[s][l] != 0) return memo[s][l]; // Return cached result if already computed
        if(s + 1 == l){
            // If there are two matrices, calculate the cost directly
            memo[s][l] = count(chain[s], chain[l]);
        }else{
            int min = Integer.MAX_VALUE; // Initialize minimum cost to maximum possible value
            // Try every possible split point to find the minimum cost
            for(int i = s; i < l; ++i){
                // Calculate cost of multiplying the two parts and add the cost of multiplying the resulting matrices
                int c = solve(s, i) + count(new Size(chain[s].r, chain[i].c), new Size(chain[i+1].r, chain[l].c)) + solve(i+1, l);
                min = Math.min(min, c); // Update minimum cost
            }
            memo[s][l] = min; // Store the minimum cost in the memoization table
        }
        // System.out.println("Solve! [" + s + "], [" + l + "]"); 
        return memo[s][l]; // Return the computed minimum cost
    }

    // Constructor to initialize the solver with a chain of matrices
    McmSolver(Size[] Chain)
    {
        // Resize the memoization table based on the size of the chain
        memo = new int[Chain.length][Chain.length];
        for(int i = 0; i < memo.length; ++i){
            for(int j = 0; j < memo[0].length; ++j){
                memo[i][j] = 0; // Initialize all values to 0
            }
        }
        chain = Chain;
    }

    // Function to get the final answer (minimum multiplication cost)
    int answer()
    {
        return solve(0, memo.length-1); // Solve for the entire chain
    }

    // Function to print the memoization table (for debugging purposes)
    void print()
    {
        for(int s = 0; s < memo.length; ++s){
            for(int l = 0; l < memo[0].length; ++l){
                System.out.print(memo[s][l] + "\t"); // Print each value in the table
            }
            System.out.println(); // New line after each row
        }
    }
}

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // Input the number of matrices
        if(n == 1){
            System.out.println(0); // If there is only one matrix, no multiplication is needed
            return; // Exit the program
        }
        
        Size[] Chain = new Size[n]; // Vector to hold the sizes of the matrices
        for(int i = 0; i < n; ++i){
            Chain[i] = new Size(); // Initialize each element of the array
            Chain[i].r = sc.nextInt(); // Input the dimensions of each matrix
            Chain[i].c = sc.nextInt();
        }
        
        McmSolver Solver = new McmSolver(Chain); // Create an instance of the solver with the matrix chain
        
        System.out.println(Solver.answer()); // Output the minimum multiplication cost
        // Solver.print(); // Uncomment to print the memoization table
    }
}
// 