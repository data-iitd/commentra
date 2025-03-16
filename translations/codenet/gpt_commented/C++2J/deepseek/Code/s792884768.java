import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Class to represent the size of a matrix
class Size {
    int r; // Number of rows
    int c; // Number of columns

    Size(int r, int c) {
        this.r = r;
        this.c = c;
    }
}

// Class to solve the Matrix Chain Multiplication problem
class McmSolver {
    private List<List<Integer>> FMemo; // Memoization table to store intermediate results
    private final List<Size> FChain; // List of matrix sizes

    // Function to calculate the cost of multiplying two matrices
    private static int count(Size left, Size right) {
        return left.r * right.c * left.c; // Cost = rows of left * columns of right * columns of left
    }

    // Recursive function to solve the matrix chain multiplication problem
    private int solve(int s, int l) {
        if (s == l) return 0; // Base case: no cost if there is only one matrix
        if (FMemo.get(s).get(l) != null) return FMemo.get(s).get(l); // Return cached result if already computed
        if (s + 1 == l) {
            // If there are two matrices, calculate the cost directly
            FMemo.get(s).set(l, count(FChain.get(s), FChain.get(l)));
        } else {
            int min = Integer.MAX_VALUE; // Initialize minimum cost to maximum possible value
            // Try every possible split point to find the minimum cost
            for (int i = s; i < l; i++) {
                // Calculate cost of multiplying the two parts and add the cost of multiplying the resulting matrices
                int c = solve(s, i) + count(new Size(FChain.get(s).r, FChain.get(i).c), new Size(FChain.get(i + 1).r, FChain.get(l).c)) + solve(i + 1, l);
                min = Math.min(min, c); // Update minimum cost
            }
            FMemo.get(s).set(l, min); // Store the minimum cost in the memoization table
        }
        return FMemo.get(s).get(l); // Return the computed minimum cost
    }

    public McmSolver(List<Size> chain) {
        FChain = chain;
        // Initialize the memoization table
        FMemo = new ArrayList<>(chain.size());
        for (int i = 0; i < chain.size(); i++) {
            FMemo.add(new ArrayList<>(Collections.nCopies(chain.size(), null)));
        }
    }

    // Function to get the final answer (minimum multiplication cost)
    public int answer() {
        return solve(0, FMemo.size() - 1); // Solve for the entire chain
    }

    // Function to print the memoization table (for debugging purposes)
    public void print() {
        for (int s = 0; s < FMemo.size(); s++) {
            for (int l = 0; l < FMemo.get(s).size(); l++) {
                System.out.print(FMemo.get(s).get(l) + "\t"); // Print each value in the table
            }
            System.out.println(); // New line after each row
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Number of matrices
        if (n == 1) {
            System.out.println(0); // If there is only one matrix, no multiplication is needed
            return; // Exit the program
        }

        List<Size> chain = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            chain.add(new Size(scanner.nextInt(), scanner.nextInt())); // Input the dimensions of each matrix
        }

        McmSolver solver = new McmSolver(chain); // Create an instance of the solver with the matrix chain

        System.out.println(solver.answer()); // Output the minimum multiplication cost
        // solver.print(); // Uncomment to print the memoization table
    }
}
