import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables A and B
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();

        // Declare an integer variable C and assign the sum of A and B to it
        int C = A + B;

        // Check if both A and B are not divisible by 3
        if (A % 3 != 0 && B % 3 != 0) {
            // Check if their sum C is also not divisible by 3
            if (C % 3 != 0) {
                // If all conditions are met, print "Impossible" to the standard output
                System.out.println("Impossible");
            } else {
                // Otherwise, print "Possible" to the standard output
                System.out.println("Possible");
            }
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
