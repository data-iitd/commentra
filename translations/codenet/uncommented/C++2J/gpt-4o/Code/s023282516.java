import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    static String[] divide = {"dream", "dreamer", "erase", "eraser"};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();

        // Reverse the string S
        S = new StringBuilder(S).reverse().toString();
        
        // Reverse each string in the divide array
        for (int i = 0; i < divide.length; i++) {
            divide[i] = new StringBuilder(divide[i]).reverse().toString();
        }

        // Check if we can divide the string
        boolean can = true;
        int i = 0;
        while (i < S.length()) {
            boolean can2 = false; // Check if we can divide with any of the strings
            for (String d : divide) {
                if (S.startsWith(d, i)) { // Check if we can divide with d
                    can2 = true;
                    i += d.length(); // Move i forward
                    break; // Break to avoid checking other strings after a successful match
                }
            }
            if (!can2) { // If we couldn't divide
                can = false;
                break;
            }
        }

        if (can) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
