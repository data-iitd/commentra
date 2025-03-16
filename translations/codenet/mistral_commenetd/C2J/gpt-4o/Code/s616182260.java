import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare the required arrays and their sizes
        int[] a = new int[3]; // Declare array 'a' of size 3
        int[] b = new int[3]; // Declare array 'b' of size 3
        int[][] c = new int[3][3]; // Declare a 3x3 matrix 'c'
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for user input

        // Initialize the matrix 'c' with user input
        for (int i = 0; i < 3; i++) {
            System.out.print("Enter the elements of row " + (i + 1) + ": ");
            c[i][0] = scanner.nextInt();
            c[i][1] = scanner.nextInt();
            c[i][2] = scanner.nextInt();
            // Scan the three elements of each row and store them in the matrix 'c'
        }

        // Initialize array 'b' with the first row of matrix 'c'
        for (int i = 0; i < 3; i++) {
            b[i] = c[0][i]; // Store the elements of the first row of matrix 'c' in array 'b'
        }

        // Initialize array 'a' with the difference between the corresponding elements of matrix 'c' and array 'b'
        for (int i = 1; i < 3; i++) {
            a[i] = c[i][0] - b[0]; // Subtract the first element of each row of matrix 'c' from the corresponding element of array 'b' and store the result in array 'a'
        }

        // Compare each element of matrix 'c' with the corresponding elements of array 'a' and 'b'
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (c[i][j] != a[i] + b[j]) { // Check if the element at position (i,j) in matrix 'c' is equal to the sum of the elements at position i in array 'a' and j in array 'b'
                    System.out.println("No"); // If not, print "No" and exit the program
                    return;
                }
            }
        }

        // If all the elements in matrix 'c' match the condition, print "Yes"
        System.out.println("Yes");
    }
}
// <END-OF-CODE>
