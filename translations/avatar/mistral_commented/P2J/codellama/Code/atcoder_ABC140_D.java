#######
# Code
#######

// Import necessary libraries
import java.util.Scanner;
import java.util.Deque;
import java.util.ArrayDeque;

// Function to parse input line by line
class Parser {
    // Continuously parse input lines
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            String data = scanner.nextLine();
            // Process each token in the input line
            for (String number : data.split(" ")) {
                // Check if the token is empty or not
                if (number.length() > 0) {
                    // Yield the token as a result of the function
                    System.out.println(number);
                }
            }
        }
    }
}

// Create a parser object
Parser input_parser = new Parser();

// Function to get the next token from the parser
class GetWord {
    // Get the next token from the parser
    public static String gw() {
        // Get the next token from the parser
        return input_parser.next();
    }
}

// Function to get the next integer from the parser
class GetInteger {
    // Get the next token as a string
    public static int gi() {
        // Get the next token as a string
        String data = GetWord.gw();
        // Convert the token to an integer
        return Integer.parseInt(data);
    }
}

// Global variables
int MOD = (int) 1e9 + 7;

// Import additional libraries for scientific computing
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;

// Define a deque for segment count
Deque<Integer> seg_cnt = new ArrayDeque<>();

// Get the number of segments in the string
int N = GetInteger.gi();

// Get the number of queries
int K = GetInteger.gi();

// Get the string S
String S = GetWord.gw();

// Initialize segment count
seg_cnt.clear();

// Iterate through the string and count the number of segments
for (int i = 0; i < N - 1; i++) {
    // Check if the current character is different from the next character
    if (S.charAt(i) != S.charAt(i + 1)) {
        // Add 1 to the segment count
        seg_cnt.add(1);
    }
}

// Calculate the current happiness
int cur_happy = N - 1 - seg_cnt.size();

// Check if the number of queries is greater than or equal to the number of segments
if (2 * K >= seg_cnt.size()) {
    // If yes, then the answer is the total number of segments
    int ans = N - 1;
    // Otherwise, the answer is the current happiness plus twice the number of queries
} else {
    int ans = cur_happy + 2 * K;
}

// Print the answer
System.out.println(ans);


Translate the above Java code to C++ and end with comment "