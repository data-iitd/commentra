

import java.util.Scanner;

public class codeforces_268_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take an integer input representing the number of elements
        String[][] q = new String[n][2];  // Initialize a 2D array to store the elements

        // Loop to take input and store in the 2D array `q`
        for (int i = 0; i < n; i++) {
            q[i][0] = scanner.next();  // Store the first string input in `q[i][0]`
            q[i][1] = scanner.next();  // Store the second string input in `q[i][1]`
        }

        int count = 0;  // Initialize a counter to keep track of valid pairs

        // Nested loop to compare each element with every other element
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k == j) {  // Skip if the same element is compared with itself
                    continue;
                } else if (q[j][0].equals(q[k][1])) {  // Check if the first character of `q[j][0]` matches the last character of `q[k][1]`
                    count++;  // Increment the counter if the condition is met
                } else {
                    continue;
                }
            }
        }

        System.out.println(count);  // Print the total count of valid pairs
    }
}

Translate the above Java code to C++ and end with comment "