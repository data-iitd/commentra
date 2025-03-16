import java.util.Scanner;

public class Main {
    // Function to calculate the greatest common divisor (GCD) using recursion
    public static int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }

    public static void main(String[] args) {
        // Create a Scanner object to take input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Take an integer input from the user
        int R = scanner.nextInt();

        // Check the value of R and print the corresponding output
        if (R < 1200)
            System.out.println("ABC"); // If R is less than 1200, print "ABC"
        else if (R >= 2800)
            System.out.println("AGC"); // If R is 2800 or more, print "AGC"
        else
            System.out.println("ARC"); // Otherwise, print "ARC"
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
