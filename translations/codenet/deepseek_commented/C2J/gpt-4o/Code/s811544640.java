import java.util.Scanner;  // Step 1: Import necessary classes

public class Main {  // Step 2: Define the main class
    public static void main(String[] args) {  // Step 3: Define the main method
        Scanner scanner = new Scanner(System.in);  // Step 4: Create a Scanner object for input
        int a, b, c;  // Step 5: Declare variables

        a = scanner.nextInt();  // Read input values
        b = scanner.nextInt();
        c = scanner.nextInt();

        if (b > a * c) {  // Step 6: Implement the if-else condition
            System.out.println(c);  // If true, print c
        } else {
            System.out.println(b / a);  // Otherwise, print b divided by a
        }

        scanner.close();  // Close the scanner
    }  // End of main method
}  // End of class Main
// <END-OF-CODE>
