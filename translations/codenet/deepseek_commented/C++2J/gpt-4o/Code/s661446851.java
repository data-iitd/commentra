/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
import java.util.*; // Import the Java utility library for various data structures

public class Main {
    // Define a method to solve the problem
    private static void solve() {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        long n = scanner.nextLong(); // Read the input number as long
        System.out.println(n == 0 ? 1 : 0); // Output the boolean negation of n (1 if n is 0, else 0)
    }

    public static void main(String[] args) {
        long n = 1; // Initialize n with 1
        while (n-- > 0) solve(); // Run the solve function in a loop with n=1
    }
}

/*<END-OF-CODE>*/
