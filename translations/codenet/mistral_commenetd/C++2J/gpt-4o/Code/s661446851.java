/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
import java.util.Scanner; // Import Scanner for input

// Define a class for the solution
public class Main {
    // Function to solve the problem
    private static void solve() {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        long n = scanner.nextLong(); // Read input for n
        System.out.println(n == 0 ? 1 : 0); // Print output if n is not positive
    }

    public static void main(String[] args) {
        long testCases = 1; // Initialize a variable for number of test cases
        while (testCases-- > 0) {
            solve(); // Call the solve function for each test case
        }
    }
}
// <END-OF-CODE>
