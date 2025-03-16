import java.util.Scanner; // Importing the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables to hold user input
        int a, b;
        
        // Create a Scanner object to read input from standard input
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from standard input
        a = scanner.nextInt();
        b = scanner.nextInt();
        
        // Calculate and print the product of a and b, 
        // and also print the perimeter of a rectangle with sides a and b
        System.out.println(a * b + " " + (a + b) * 2);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
