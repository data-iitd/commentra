import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of rows/columns for the square matrix
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        
        // Initialize an empty list to store the input strings
        ArrayList<String> s = new ArrayList<>();
        
        // Read n strings from input and append them to the list s
        for (int i = 0; i < n; i++) {
            String k = scanner.nextLine();
            s.add(k);
        }
        
        // Initialize a flag variable (not used in this code)
        boolean flag = false;
        
        // Initialize lists to store diagonal elements
        ArrayList<Character> d1 = new ArrayList<>();  // Primary diagonal
        ArrayList<Character> d2 = new ArrayList<>();  // Secondary diagonal
        
        // Initialize a set to store non-diagonal elements
        Set<Character> rem = new HashSet<>();
        
        // Iterate through the matrix to populate the diagonals and non-diagonal elements
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If it's a primary diagonal element
                if (i == j) {
                    d1.add(s.get(i).charAt(j));
                }
                // If it's a secondary diagonal element
                if (i == n - j - 1) {
                    d2.add(s.get(i).charAt(j));
                }
                // If it's a non-diagonal element
                if (i != j && i != n - j - 1) {
                    rem.add(s.get(i).charAt(j));
                }
            }
        }
        
        // Check conditions to determine the output
        // If the number of unique non-diagonal elements is not 1
        if (rem.size() != 1) {
            System.out.println("NO");
        // If the primary and secondary diagonals are not equal
        } else if (!d1.equals(d2)) {
            System.out.println("NO");
        // If the primary diagonal does not consist of the same element
        } else if (new HashSet<>(d1).size() != 1) {
            System.out.println("NO");
        // If the unique element in the primary diagonal is also in the non-diagonal set
        } else if (new HashSet<>(d1).equals(rem)) {
            System.out.println("NO");
        // If all conditions are satisfied, print 'YES'
        } else {
            System.out.println("YES");
        }
    }
}
