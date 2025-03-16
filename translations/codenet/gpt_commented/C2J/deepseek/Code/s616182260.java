public class MatrixSum {
    public static void main(String[] args) {
        // Declare arrays to hold input values and intermediate calculations
        int[] a = new int[3];
        int[] b = new int[3];
        int[][] c = new int[3][3]; // 2D array to store the input matrix
        int i, j;

        // Read a 3x3 matrix from user input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        for(i = 0; i < 3; i++) {
            c[i][0] = scanner.nextInt();
            c[i][1] = scanner.nextInt();
            c[i][2] = scanner.nextInt();
        }

        // Initialize the first element of array 'a' to 0
        a[0] = 0;

        // Copy the first row of the matrix 'c' into array 'b'
        for(i = 0; i < 3; i++) {
            b[i] = c[0][i];
        }

        // Calculate the remaining elements of array 'a' based on the first column of matrix 'c'
        for(i = 1; i < 3; i++) {
            a[i] = c[i][0] - b[0];
        }

        // Verify if the matrix 'c' can be represented as the sum of arrays 'a' and 'b'
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                // Check if the current element of 'c' equals the sum of corresponding elements from 'a' and 'b'
                if(c[i][j] != a[i] + b[j]) {
                    System.out.println("No"); // Output "No" if the condition fails
                    return;   // Exit the program
                }
            }
        }

        // If all checks pass, output "Yes"
        System.out.println("Yes");
    }
}
