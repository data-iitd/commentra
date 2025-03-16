public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the number of characters and the answer
        int n, ans = 0;
        String a, b, c;

        // Read the number of characters and the three strings from input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        a = scanner.next();
        b = scanner.next();
        c = scanner.next();

        // Iterate through each character index from 0 to n-1
        for (int i = 0; i < n; i++) {
            // Check if all three characters at index i are the same
            if (a.charAt(i) == b.charAt(i) && b.charAt(i) == c.charAt(i)) {
                // Do nothing, as no points are awarded for identical characters
            }
            // Check if any two characters are the same
            else if (a.charAt(i) == b.charAt(i) || b.charAt(i) == c.charAt(i) || a.charAt(i) == c.charAt(i)) {
                // Increment the answer by 1 for matching pairs
                ans++;
            }
            // If all characters are different
            else {
                // Increment the answer by 2 for all different characters
                ans += 2;
            }
        }

        // Output the final answer
        System.out.println(ans);
    }
}
