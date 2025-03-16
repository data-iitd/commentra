import java.util.Scanner;

public class Main {
    // Function to find the greatest common divisor (GCD) of two numbers
    public static int gcd(int a, int b) {
        // Base case: if 'a' is 0, return 'b' as the GCD
        if (a == 0) {
            return b;
        }
        // Recursive case: call the function with the remainder of 'a' and 'b' as arguments
        return gcd(b % a, a);
    }

    public static void main(String[] args) {
        // Declare and read the value of 'R' from the standard input
        Scanner scanner = new Scanner(System.in);
        int R = scanner.nextInt();

        // Check the value of 'R' and print the corresponding output
        if (R < 1200) {
            System.out.println("ABC"); // Output: "ABC" if 'R' is less than 1200
        } else if (R >= 2800) {
            System.out.println("AGC"); // Output: "AGC" if 'R' is greater than or equal to 2800
        } else {
            System.out.println("ARC"); // Output: "ARC" if 'R' is between 1200 and 2800 (inclusive)
        }

        scanner.close();
    }
}

// <END-OF-CODE>
