import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take the size of the square matrix as input
        ArrayList<String> s = new ArrayList<>();  // Initialize an empty list to store the matrix elements

        // Take n inputs, each representing a row of the matrix, and append these to the list s
        for (int i = 0; i < n; i++) {
            String k = scanner.next();
            s.add(k);
        }

        boolean flag = false;  // Initialize flag to false
        ArrayList<Character> d1 = new ArrayList<>();  // Initialize an empty list to store the diagonal elements from top-left to bottom-right
        ArrayList<Character> d2 = new ArrayList<>();  // Initialize an empty list to store the diagonal elements from top-right to bottom-left
        HashSet<Character> rem = new HashSet<>();  // Initialize a set to store the non-diagonal elements

        // Iterate through the matrix to populate d1, d2, and rem with the appropriate elements
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {  // Check if the element is on the diagonal from top-left to bottom-right
                    d1.add(s.get(i).charAt(j));
                }
                if (i == n - j - 1) {  // Check if the element is on the diagonal from top-right to bottom-left
                    d2.add(s.get(i).charAt(j));
                }
                if (i != j && i != n - j - 1) {  // Check if the element is not on the diagonals
                    rem.add(s.get(i).charAt(j));
                }
            }
        }

        // Check the conditions and print 'NO' or 'YES' based on the conditions
        if (rem.size() != 1) {
            System.out.println("NO");  // Print 'NO' if the set of non-diagonal elements does not have a single unique element
        } else if (!d1.equals(d2)) {
            System.out.println("NO");  // Print 'NO' if the two diagonals are not equal
        } else if (d1.stream().distinct().count() != 1) {
            System.out.println("NO");  // Print 'NO' if the diagonal elements do not all have the same value
        } else if (rem.equals(new HashSet<>(d1))) {
            System.out.println("NO");  // Print 'NO' if the set of diagonal elements is equal to the set of non-diagonal elements
        } else {
            System.out.println("YES");  // Print 'YES' if all conditions are met
        }
