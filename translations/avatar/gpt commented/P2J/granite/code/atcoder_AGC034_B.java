
import java.util.*;
import java.io.*;

public class atcoder_AGC034_B{
    public static void main(String[] args) throws IOException {
        // Read input string
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String t = "";  // Initialize an empty string to build the result
        int i = 0;   // Initialize index for traversing the input string

        // Process the input string character by character
        while (i < s.length()) {
            if (s.charAt(i) == 'A') {
                // If the character is 'A', add it to the result
                t += "A";
                i++;  // Move to the next character
            } else if (s.charAt(i) == 'B') {
                // If the character is 'B', check the next character
                if (i < s.length() - 1) {
                    if (s.charAt(i + 1) == 'C') {
                        // If the next character is 'C', add 'D' to the result
                        t += "D";
                        i += 2;  // Skip the next character as well
                    } else {
                        // If the next character is not 'C', add 'X' to the result
                        t += "X";
                        i++;  // Move to the next character
                    }
                } else {
                    // If 'B' is the last character, add 'X' to the result
                    t += "X";
                    i++;
                }
            } else {
                // For any other character, add 'X' to the result
                t += "X";
                i++;
            }
        }

        int total = 0;  // Initialize total count
        int numA = 0;   // Initialize count of 'A's encountered

        // Calculate the total based on the processed string
        for (int i = 0; i < t.length(); i++) {
            if (t.charAt(i) == 'X') {
                // Reset count of 'A's when 'X' is encountered
                numA = 0;
            } else {
                if (t.charAt(i) == 'A') {
                    // Increment count of 'A's
                    numA++;
                } else {
                    // If the character is not 'A', add the count of 'A's to total
                    total += numA;
                }
            }
        }

        // Print the final total
        System.out.println(total);
    }
}

Translate the above Java code to C++ and end with comment "