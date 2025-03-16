import java.util.Scanner;  // Import the Scanner class for user input

public class Main {  // Define the Main class
    public static void main(String[] args) {  // Define the main method
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Declare integer variables to store input values and intermediate results
        int a, b, c, d, i, j;

        // Read four integers from the user
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();

        // Perform multiplication operations and store the results in i and j
        i = a * b;
        j = c * d;

        // Use an if-else statement to compare the results and print the larger one
        if (i > j) {
            System.out.println(i);
        } else {
            System.out.println(j);
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
