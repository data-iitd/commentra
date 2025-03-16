public class Main {
    static final int M = 1010; // Step 2: Define constant for string length
    static char[] a = new char[M]; // Step 2: Define arrays to store input strings
    static char[] b = new char[M]; // Step 2: Define arrays to store input strings
    static int n, m, ans = M + 10; // Step 2: Define variables for string lengths and minimum differences

    public static void main(String[] args) {
        // Step 3: Read input strings
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String inputA = scanner.next();
        n = inputA.length();
        for (int i = 1; i <= n; i++) {
            a[i] = inputA.charAt(i - 1);
        }
        String inputB = scanner.next();
        m = inputB.length();
        for (int i = 1; i <= m; i++) {
            b[i] = inputB.charAt(i - 1);
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
    }
}
