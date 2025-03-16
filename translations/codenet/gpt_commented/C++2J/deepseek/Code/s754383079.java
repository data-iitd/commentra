import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the first string into array 'a' starting from index 1
        String a = scanner.nextLine();
        a = " " + a; // Add a space at the beginning to use 1-based indexing
        
        // Read the second string into array 'b' starting from index 1
        String b = scanner.nextLine();
        b = " " + b; // Add a space at the beginning to use 1-based indexing
        
        // Calculate the lengths of the strings
        int n = a.length() - 1;
        int m = b.length() - 1;
        
        // Initialize the minimum answer to a large value
        int ans = m + 10;
        
        // Iterate over all possible starting positions in 'a' where 'b' can fit
        for (int i = 1; i + m - 1 <= n; i++) {
            // Initialize a variable to count the number of mismatches
            int sum = 0;
            
            // Compare the substring of 'a' with 'b' character by character
            for (int j = 1; j <= m; j++) {
                // Increment the mismatch count if characters do not match
                if (a.charAt(i + j - 1) != b.charAt(j)) {
                    sum++;
                }
            }
            
            // Update the minimum number of mismatches found
            ans = Math.min(ans, sum);
        }
        
        // Output the minimum number of mismatches
        System.out.println(ans);
    }
}
