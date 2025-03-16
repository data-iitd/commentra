#######
# Code
#######

// Import necessary libraries
import java.util.Deque;
import java.util.ArrayDeque;

// Function to parse input line by line
public static String[] parser() {
// Continuously parse input lines
    while (true) {
        String[] data = input.nextLine().split(" ");
// Process each token in the input line
        for (String number : data) {
// Check if the token is empty or not
            if (number.length() > 0) {
// Yield the token as a result of the function
                yield number;
            }
        }
    }
}

// Create a parser object
public static String gw() {
// Get the next token from the parser
    return input_parser.next();
}

// Function to get the next integer from the parser
public static int gi() {
// Get the next token as a string
    String data = gw();
// Convert the token to an integer
    return Integer.parseInt(data);
}

// Global variables
public static final int MOD = (int) (1e9 + 7);

// Import additional libraries for scientific computing
import java.util.Arrays;
import java.util.stream.IntStream;

// Define a deque for segment count
public static Deque<Integer> seg_cnt = new ArrayDeque<Integer>();

// Get the number of segments in the string
public static int N = gi();

// Get the number of queries
public static int K = gi();

// Get the string S
public static String S = gw();

// Initialize segment count
seg_cnt.clear();

// Iterate through the string and count the number of segments
for (int i = 0; i < N - 1; i++) {
// Check if the current character is different from the next character
    if (S.charAt(i)!= S.charAt(i + 1)) {
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

