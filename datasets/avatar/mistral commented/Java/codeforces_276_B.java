
import java.io.BufferedReader;  // BufferedReader to read input lines
import java.io.IOException;        // Exception for I/O errors
import java.io.InputStreamReader;  // InputStreamReader to read from standard input
import java.math.BigInteger;       // For large integer arithmetic
import java.util.*;                // Standard utility library

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
         // Initialize input and output streams
        InputStreamReader inputStreamReader = new InputStreamReader(System.in);
        BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
        PrintWriter writer = new PrintWriter(System.out);

        String str;                 // String to read from input
        Map<Character, Integer> map; // Map to store character counts
        int oddCount;              // Count of odd-valued character counts

        try {
            // Read the first line of input
            str = bufferedReader.readLine();

            // Initialize the map to store character counts
            map = new HashMap<>();

            // Iterate through each character in the input string
            for (int i = 0; i < str.length(); i++) {
                char ch = str.charAt(i); // Get the current character

                // If the character is already in the map, increment its count
                if (map.containsKey(ch)) {
                    map.put(ch, map.get(ch) + 1);
                } else {
                    // Otherwise, add the character to the map with a count of 1
                    map.put(ch, 1);
                }
            }

            // Iterate through each entry in the map and count odd-valued entries
            for (Map.Entry<Character, Integer> entry : map.entrySet()) {
                if (entry.getValue() % 2 != 0) {
                    oddCount++; // Increment the odd count
                }
            }

            // Determine the output based on the odd count
            if (oddCount <= 1 || oddCount % 2 != 0) {
                writer.println("First"); // Output "First" if the odd count is 1 or odd
            } else {
                writer.println("Second"); // Output "Second" if the odd count is even
            }

            // Flush the output buffer to write the output to the console
            writer.flush();

        } finally {
            // Close the input and output streams
            bufferedReader.close();
            inputStreamReader.close();
            writer.close();
        }
    }
}