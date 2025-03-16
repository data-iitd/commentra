import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a new scanner to read input from standard input (stdin)
        Scanner scanner = new Scanner(System.in);

        // Initialize a 3x3 integer array to hold the input values
        int[][] c = new int[3][3];
        // Initialize arrays to hold differences for calculations
        int[] a = new int[3];
        int[] b = new int[3];

        // Read 3x3 integers from input and populate the array 'c'
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                c[i][j] = scanner.nextInt(); // Read the next integer from input
            }
        }

        // Calculate the first differences based on the first row of 'c'
        b[0] = c[0][0] - a[0];
        b[1] = c[0][1] - a[0];
        b[2] = c[0][2] - a[0];

        // Calculate the differences for the second and third rows based on the first row
        a[1] = c[1][0] - c[0][0];
        a[2] = c[2][0] - c[0][0];

        // Check if the calculated differences are consistent across the matrix
        if (a[1] == c[1][1] - c[0][1] && a[1] == c[1][2] - c[0][2] &&
            a[2] == c[2][1] - c[0][1] && a[2] == c[2][2] - c[0][2]) {
            // If the conditions are met, print "Yes"
            System.out.println("Yes");
        } else {
            // If the conditions are not met, print "No"
            System.out.println("No");
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
