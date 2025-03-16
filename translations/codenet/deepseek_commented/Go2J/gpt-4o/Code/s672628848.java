import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare five integer variables to hold input values
        int a, b, c, d, e;

        // Create a Scanner object to read input from the standard input
        Scanner scanner = new Scanner(System.in);

        // Read five integers from the standard input and assign them to the variables
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();
        e = scanner.nextInt();

        // Create an array containing the five integers
        int[] al = {a, b, c, d, e};

        // Iterate over the array using a for loop
        for (int n = 0; n < al.length; n++) {
            // Check if the current element is equal to 0
            if (al[n] == 0) {
                // Print the position of the element (1-based index) and break out of the loop
                System.out.println(n + 1);
                break;
            }
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
