import java.util.Scanner;

public class Main {
    // Main function is the entry point of the program
    public static void main(String[] args) {
        // Declare variables to store user input
        long a, b, x;
        
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read three long long integers from standard input
        a = scanner.nextLong();
        b = scanner.nextLong();
        x = scanner.nextLong();
        
        // Calculate the number of multiples of x between a and b inclusive
        long s = (b / x - a / x);
        
        // Check if a is a multiple of x and adjust the count accordingly
        if (a % x == 0) {
            s++;
        }
        
        // Print the result
        System.out.println(s);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
