import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare four integer variables to hold input values
        int a, b, c, d;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read four integer values from user input
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();

        // Check if the product of a and b is odd and the sum of c and d is odd
        if (a * b % 2 == 1 && (c + d) % 2 == 1) {
            // If both conditions are true, output "No"
            System.out.println("No");
        } else {
            // If either condition is false, output "Yes"
            System.out.println("Yes");
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
