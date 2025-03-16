import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, ans = 0; // Declare integer n and initialize ans to 0
        String a, b, c; // Declare three strings a, b, and c
        n = scanner.nextInt(); // Read the integer n from standard input
        a = scanner.next(); // Read the string a from standard input
        b = scanner.next(); // Read the string b from standard input
        c = scanner.next(); // Read the string c from standard input
        
        // Loop through each character position up to n
        for (int i = 0; i < n; i++) {
            // Check if all three characters at position i are the same
            if (a.charAt(i) == b.charAt(i) && b.charAt(i) == c.charAt(i)) {
                // Do nothing
            }
            // Check if any two characters at position i are the same
            else if (a.charAt(i) == b.charAt(i) || b.charAt(i) == c.charAt(i) || a.charAt(i) == c.charAt(i)) {
                ans++; // Increment ans by 1
            }
            // If all three characters at position i are different
            else {
                ans += 2; // Increment ans by 2
            }
        }
        System.out.println(ans); // Print the final value of ans
    }
}

// <END-OF-CODE>
