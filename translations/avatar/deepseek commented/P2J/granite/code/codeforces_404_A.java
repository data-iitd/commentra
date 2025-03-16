

import java.util.*;

public class codeforces_404_A{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();  // Take the size of the square matrix as input
        String[] s = new String[n];  // Initialize an array of strings to store the matrix elements

        // Take n inputs, each representing a row of the matrix, and store these in the array s
        for (int i = 0; i < n; i++) {
            s[i] = sc.next();
        }

        int flag = 0;  // Initialize flag to 0
        List<String> d1 = new ArrayList<>();  // Initialize an empty list to store the diagonal elements from top-left to bottom-right
        List<String> d2 = new ArrayList<>();  // Initialize an empty list to store the diagonal elements from top-right to bottom-left
        Set<String> rem = new HashSet<>();  // Initialize a set to store the non-diagonal elements

        // Iterate through the matrix to populate d1, d2, and rem with the appropriate elements
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {  // Check if the element is on the diagonal from top-left to bottom-right
                    d1.add(s[i].charAt(j) + "");
                }
                if (i == n - j - 1) {  // Check if the element is on the diagonal from top-right to bottom-left
                    d2.add(s[i].charAt(j) + "");
                }
                if (i!= j && i!= n - j - 1) {  // Check if the element is not on the diagonals
                    rem.add(s[i].charAt(j) + "");
                }
            }
        }

        // Check the conditions and print 'NO' or 'YES' based on the conditions
        if (rem.size()!= 1) {
            System.out.println("NO");  // Print 'NO' if the set of non-diagonal elements does not have a single unique element
        } else if (!d1.equals(d2)) {
            System.out.println("NO");  // Print 'NO' if the two diagonals are not equal
        } else if (d1.size()!= 1) {
            System.out.println("NO");  // Print 'NO' if the diagonal elements do not all have the same value
        } else if (new HashSet<>(d1).equals(rem)) {
            System.out.println("NO");  // Print 'NO' if the set of diagonal elements is equal to the set of non-diagonal elements
        } else {
            System.out.println("YES");  // Print 'YES' if all conditions are met
        }
    }
}

Translate the above Java code to C++ and end with comment "