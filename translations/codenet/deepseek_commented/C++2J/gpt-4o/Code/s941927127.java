import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Step 1: Include necessary imports
        // The code starts by importing necessary classes for input/output operations.

        Scanner scanner = new Scanner(System.in);
        String W = scanner.nextLine();
        
        // Step 2: Read input
        // The program reads a string `W` from the standard input.
        
        // Step 3: Sort the string
        // The string `W` is sorted in ascending order.
        char[] charArray = W.toCharArray();
        Arrays.sort(charArray);
        W = new String(charArray);

        // Step 4: Check for character pairs
        // The program iterates through the sorted string, checking if each character
        // is followed by its identical pair.
        for (int i = 0; i < W.length(); i += 2) {
            if (i + 1 >= W.length() || W.charAt(i) != W.charAt(i + 1)) {
                // If a character is not followed by its pair, output "No" and exit.
                System.out.println("No");
                return;
            }
        }
        
        // Step 5: Output result
        // If all characters are in pairs, the program outputs "Yes"; otherwise,
        // it outputs "No".
        System.out.println("Yes");
    }
}

// <END-OF-CODE>
