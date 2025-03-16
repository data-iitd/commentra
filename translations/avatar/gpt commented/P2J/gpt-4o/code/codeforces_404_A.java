import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class MatrixDiagonalCheck {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of rows/columns for the square matrix
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Initialize an array to store the input strings
        String[] s = new String[n];

        // Read n strings from input and store them in the array s
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextLine();
        }

        // Initialize lists to store diagonal elements
        StringBuilder d1 = new StringBuilder(); // Primary diagonal
        StringBuilder d2 = new StringBuilder(); // Secondary diagonal

        // Initialize a set to store non-diagonal elements
        Set<Character> rem = new HashSet<>();

        // Iterate through the matrix to populate the diagonals and non-diagonal elements
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If it's a primary diagonal element
                if (i == j) {
                    d1.append(s[i].charAt(j));
                }
                // If it's a secondary diagonal element
                if (i == n - j - 1) {
                    d2.append(s[i].charAt(j));
                }
                // If it's a non-diagonal element
                if (i != j && i != n - j - 1) {
                    rem.add(s[i].charAt(j));
                }
            }
        }

        // Check conditions to determine the output
        // If the number of unique non-diagonal elements is not 1
        if (rem.size() != 1) {
            System.out.println("NO");
        }
        // If the primary and secondary diagonals are not equal
        else if (!d1.toString().equals(d2.toString())) {
            System.out.println("NO");
        }
        // If the primary diagonal does not consist of the same element
        else if (d1.toString().chars().distinct().count() != 1) {
            System.out.println("NO");
        }
        // If the unique element in the primary diagonal is also in the non-diagonal set
        else if (rem.contains(d1.charAt(0))) {
            System.out.println("NO");
        }
        // If all conditions are satisfied, print 'YES'
        else {
            System.out.println("YES");
        }

        scanner.close();
    }
}
// <END-OF-CODE>
