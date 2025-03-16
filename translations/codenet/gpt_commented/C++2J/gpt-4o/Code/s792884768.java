import java.util.Scanner; // For input operations
import java.util.Arrays; // For using Arrays.fill

// Class to represent the size of a matrix
class TSize {
    int r; // Number of rows
    int c; // Number of columns

    // Default constructor initializing rows and columns to 0
    TSize() {
        this.r = 0;
        this.c = 0;
    }

    // Parameterized constructor to initialize with given values
    TSize(int Ar, int Ac) {
        this.r = Ar;
        this.c = Ac;
    }
}

// Class to solve the Matrix Chain Multiplication problem
class TMcmSolver {
    private int[][] FMemo; // Memoization table to store intermediate results
    private final TSize[] FChain; // Reference to the chain of matrices

    // Function to calculate the cost of multiplying two matrices
    private static int Count(TSize Left, TSize Right) {
        return Left.r * Right.c * Left.c; // Cost = rows of Left * columns of Right * columns of Left
    }

    // Recursive function to solve the matrix chain multiplication problem
    private int Solve(int s, int l) {
        assert s <= l; // Ensure the start index is less than or equal to the end index
        if (s == l) return 0; // Base case: no cost if there is only one matrix
        if (FMemo[s][l] != 0) return FMemo[s][l]; // Return cached result if already computed
        if (s + 1 == l) {
            // If there are two matrices, calculate the cost directly
            FMemo[s][l] = Count(FChain[s], FChain[l]);
        } else {
            int min = Integer.MAX_VALUE; // Initialize minimum cost to maximum possible value
            // Try every possible split point to find the minimum cost
            for (int i = s; i < l; ++i) {
                // Calculate cost of multiplying the two parts and add the cost of multiplying the resulting matrices
                int c = Solve(s, i) + Count(new TSize(FChain[s].r, FChain[i].c), new TSize(FChain[i + 1].r, FChain[l].c)) + Solve(i + 1, l);
                min = Math.min(min, c); // Update minimum cost
            }
            FMemo[s][l] = min; // Store the minimum cost in the memoization table
        }
        return FMemo[s][l]; // Return the computed minimum cost
    }

    // Constructor to initialize the solver with a chain of matrices
    TMcmSolver(TSize[] Chain) {
        this.FChain = Chain;
        // Resize the memoization table based on the size of the chain
        FMemo = new int[Chain.length][Chain.length];
        for (int i = 0; i < FMemo.length; ++i) {
            Arrays.fill(FMemo[i], 0); // Initialize all values to 0
        }
    }

    // Function to get the final answer (minimum multiplication cost)
    int Answer() {
        return Solve(0, FMemo.length - 1); // Solve for the entire chain
    }

    // Function to print the memoization table (for debugging purposes)
    void Print() {
        for (int s = 0; s < FMemo.length; ++s) {
            for (int l = 0; l < FMemo[0].length; ++l) {
                System.out.print(FMemo[s][l] + "\t"); // Print each value in the table
            }
            System.out.println(); // New line after each row
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int n = scanner.nextInt(); // Input the number of matrices
        if (n == 1) {
            System.out.println(0); // If there is only one matrix, no multiplication is needed
            return; // Exit the program
        }

        TSize[] Chain = new TSize[n]; // Array to hold the sizes of the matrices
        for (int i = 0; i < n; ++i) {
            Chain[i] = new TSize(scanner.nextInt(), scanner.nextInt()); // Input the dimensions of each matrix
        }

        TMcmSolver Solver = new TMcmSolver(Chain); // Create an instance of the solver with the matrix chain

        System.out.println(Solver.Answer()); // Output the minimum multiplication cost
        // Solver.Print(); // Uncomment to print the memoization table
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
