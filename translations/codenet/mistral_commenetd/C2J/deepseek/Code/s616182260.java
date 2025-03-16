import java.util.Scanner;

public class MatrixArrayComparison {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] a = new int[3];
        int[] b = new int[3];
        int[][] c = new int[3][3];

        // Initialize the matrix 'c' with user input
        for (int i = 0; i < 3; i++) {
            System.out.print("Enter the elements of row " + (i + 1) + ": ");
            c[i][0] = scanner.nextInt();
            c[i][1] = scanner.nextInt();
            c[i][2] = scanner.nextInt();
        }

        // Initialize array 'a' with the first row of matrix 'c'
        a[0] = 0;
        for (int i = 0; i < 3; i++) {
            b[i] = c[0][i];
        }

        // Initialize array 'a' with the difference between the corresponding elements of matrix 'c' and array 'b'
        for (int i = 1; i < 3; i++) {
            a[i] = c[i][0] - b[0];
        }

        // Compare each element of matrix 'c' with the corresponding elements of array 'a' and 'b'
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (c[i][j] != a[i] + b[j]) {
                    System.out.println("No");
                    return;
                }
            }
        }

        // If all the elements in matrix 'c' match the condition, print "Yes"
        System.out.println("Yes");
    }
}
