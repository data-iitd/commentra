import java.util.Scanner;

public class Main {
    // Function to compute the greatest common divisor (GCD) of two integers
    public static int gcd(int a, int b) {
        // Base case: if 'a' is 0, return 'b' as the GCD
        if (a == 0) return b;
        // Recursive case: call gcd with 'b' modulo 'a' and 'a'
        return gcd(b % a, a);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int R; // Variable to store the input rating
        R = scanner.nextInt(); // Read the rating from standard input

        // Determine the category based on the rating value
        if (R < 1200) 
            System.out.println("ABC"); // Output "ABC" for ratings less than 1200
        else if (R >= 2800) 
            System.out.println("AGC"); // Output "AGC" for ratings 2800 and above
        else 
            System.out.println("ARC"); // Output "ARC" for ratings between 1200 and 2800

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
