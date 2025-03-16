import java.util.Scanner;

// Include the Scanner class for input

public class Main {
    public static void main(String[] args) {
        // Declare three integer variables: a, b, and c
        int a, b, c;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Use the Scanner to read three integers from the standard input and store them in variables a, b, and c
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        // Check if the condition a < b and b < c is true. If it is, print "Yes". Otherwise, print "No"
        if (a < b && b < c) {
            System.out.println("Yes"); // If the condition is true, print "Yes"
        } else {
            System.out.println("No"); // If the condition is false, print "No"
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
