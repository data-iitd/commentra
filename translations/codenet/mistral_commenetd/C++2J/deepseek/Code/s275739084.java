import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the values of A and B from the standard input
        int A = scanner.nextInt();
        int B = scanner.nextInt();

        // Declare an integer variable C and assign the sum of A and B to it
        int C = A + B;

        // Check if both A and B are not divisible by 3
        if(A % 3 != 0 && B % 3 != 0) {
            // Check if their sum C is also not divisible by 3
            if(C % 3 != 0) {
                // If all conditions are met, print "Impossible" to the standard output
                System.out.println("Impossible");
            } else {
                // Otherwise, print "Possible" to the standard output
                System.out.println("Possible");
            }
        }

        // Return 0 to indicate successful execution of the program
    }
}
