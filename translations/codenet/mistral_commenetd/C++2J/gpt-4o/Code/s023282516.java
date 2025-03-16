import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    // Initialize an array of strings called divide
    static String[] divide = {"dream", "dreamer", "erase", "eraser"};

    public static void main(String[] args) {
        // Declare a string variable called S and read a string from the standard input
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();

        // Reverse the string S and also reverse each string in the divide array
        S = new StringBuilder(S).reverse().toString();
        for (int i = 0; i < divide.length; i++) {
            divide[i] = new StringBuilder(divide[i]).reverse().toString();
        }

        // Initialize a boolean variable called can to true
        boolean can = true;

        // Iterate through each character in the string S
        for (int i = 0; i < S.length();) {
            // Initialize a boolean variable called can2 to false
            boolean can2 = false;

            // Iterate through each string in the divide array
            for (String d : divide) {
                // Check if the substring of S starting from the current index i and having the same size as d is equal to d
                if (S.startsWith(d, i)) {
                    // If the substring is equal to d, set can2 to true and move the index i to the end of the matched substring
                    can2 = true;
                    i += d.length();
                    break; // Break to avoid checking other strings once a match is found
                }
            }

            // If can2 is false, it means the current substring of S cannot be divided by any string in the divide array, so set can to false and break the loop
            if (!can2) {
                can = false;
                break;
            }
        }

        // Output "YES" if can is true, otherwise output "NO"
        if (can) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }

        scanner.close();
    }
}
// <END-OF-CODE>
