import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class MatrixDiagonalCheck {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = Integer.parseInt(scanner.nextLine());  // Take the size of the square matrix as input
        String[] s = new String[n];  // Initialize an array to store the matrix elements

        // Take n inputs, each representing a row of the matrix, and store these in the array s
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextLine();
        }

        Set<Character> rem = new HashSet<>();  // Initialize a set to store the non-diagonal elements
        StringBuilder d1 = new StringBuilder();  // Initialize a StringBuilder to store the diagonal elements from top-left to bottom-right
        StringBuilder d2 = new StringBuilder();  // Initialize a StringBuilder to store the diagonal elements from top-right to bottom-left

        // Iterate through the matrix to populate d1, d2, and rem with the appropriate elements
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {  // Check if the element is on the diagonal from top-left to bottom-right
                    d1.append(s[i].charAt(j));
                }
                if (i == n - j - 1) {  // Check if the element is on the diagonal from top-right to bottom-left
                    d2.append(s[i].charAt(j));
                }
                if (i != j && i != n - j - 1) {  // Check if the element is not on the diagonals
                    rem.add(s[i].charAt(j));
                }
            }
        }

        // Check the conditions and print 'NO' or 'YES' based on the conditions
        if (rem.size() != 1) {
            System.out.println("NO");  // Print 'NO' if the set of non-diagonal elements does not have a single unique element
        } else if (!d1.toString().equals(d2.toString())) {
            System.out.println("NO");  // Print 'NO' if the two diagonals are not equal
        } else if (d1.toString().chars().distinct().count() != 1) {
            System.out.println("NO");  // Print 'NO' if the diagonal elements do not all have the same value
        } else if (rem.contains(d1.charAt(0))) {
            System.out.println("NO");  // Print 'NO' if the set of diagonal elements is equal to the set of non-diagonal elements
        } else {
            System.out.println("YES");  // Print 'YES' if all conditions are met
        }

        scanner.close();
    }
}
// <END-OF-CODE>
