import java.util.Scanner;

public class Main {
    // Function to find minimum of two integers
    public static int min(int x, int y) {
        // If x is greater than y, return y
        if (x > y) {
            return y;
        } else {
            // Otherwise, return x
            return x;
        }
    }

    public static void main(String[] args) {
        // Initialize scanner
        Scanner sc = new Scanner(System.in);
        
        // Read input string S
        String S = sc.next();
        
        // Initialize variables l0 and l1 to store count of '0' and '1' respectively
        int l0 = 0, l1 = 0;

        // Iterate through each character in string S
        for (int i = 0; i < S.length(); i++) {
            // If current character is '0', increment l0
            if (S.charAt(i) == '0') {
                l0++;
            } else {
                // Otherwise, increment l1
                l1++;
            }
        }

        // Print result which is twice the minimum of l0 and l1
        System.out.println(2 * min(l0, l1));
        
        // Close the scanner
        sc.close();
    }
}

// <END-OF-CODE>
