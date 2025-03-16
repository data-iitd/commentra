
import java.util.*;
import java.io.*;

public class atcoder_AGC034_B{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();  // Read input string
        String t = "";  // Initialize an empty string to store processed characters
        int i = 0;  // Initialize index
        
        // Process the input string character by character
        while (i < s.length()) {
            if (s.charAt(i) == 'A') {
                t += 'A';
                i++;
            } else if (s.charAt(i) == 'B') {
                if (i < s.length() - 1) {
                    if (s.charAt(i + 1) == 'C') {
                        t += 'D';
                        i += 2;
                    } else {
                        t += 'X';
                        i++;
                    }
                } else {
                    t += 'X';
                    i++;
                }
            } else {
                t += 'X';
                i++;
            }
        }
        
        int total = 0;  // Initialize total count
        int numA = 0;  // Initialize count of 'A' characters
        
        // Count the number of 'A' characters before each 'X' in the processed string
        for (int j = 0; j < t.length(); j++) {
            if (t.charAt(j) == 'X') {
                numA = 0;
            } else {
                if (t.charAt(j) == 'A') {
                    numA++;
                } else {
                    total += numA;
                }
            }
        }
        
        System.out.println(total);  // Print the total count
        
        // Define constants for infinity and modulo
        final int INF = 100000000;
        final int mod = 7 + 100000000;
        
        return;
    }
}

Translate the above Java code to C++ and end with comment "