import java.util.Scanner;

public class Main {
    static final int M = 1010; // Step 2: Define constant for string length
    static char[] a = new char[M]; // Step 2: Define array to store input string a
    static char[] b = new char[M]; // Step 2: Define array to store input string b
    static int n, m, ans = M + 10; // Step 2: Define variables for string lengths and minimum differences

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Step 3: Read input strings
        String inputA = scanner.next(); // Read string a
        String inputB = scanner.next(); // Read string b
        n = inputA.length(); // Store the length of string a
        m = inputB.length(); // Store the length of string b
        
        // Convert strings to character arrays
        for (int i = 0; i < n; i++) {
            a[i + 1] = inputA.charAt(i);
        }
        for (int i = 0; i < m; i++) {
            b[i + 1] = inputB.charAt(i);
        }
        
        // Step 4: Calculate the minimum number of differences
        for (int i = 1; i + m - 1 <= n; i++) { // Iterate over possible starting positions
            int sum = 0; // Initialize sum of differences for current starting position
            for (int j = 1; j <= m; j++) { // Compare each character of b with corresponding character in a
                if (a[i + j - 1] != b[j]) { // Check if characters are different
                    sum++; // Increment sum if characters are different
                }
            }
            ans = Math.min(ans, sum); // Update minimum differences
        }
        
        // Step 5: Output the result
        System.out.println(ans); // Print the minimum number of differences
        
        scanner.close();
    }
}

// <END-OF-CODE>
