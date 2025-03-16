import java.util.*;

public class Main {
    // Global variables
    static final int MOD = (int) (1e9 + 7);
    
    // Function to parse input line by line
    static class Parser {
        private final Scanner scanner;

        public Parser() {
            this.scanner = new Scanner(System.in);
        }

        public String nextToken() {
            return scanner.next();
        }
    }

    public static void main(String[] args) {
        // Create a parser object
        Parser inputParser = new Parser();

        // Get the number of segments in the string
        int N = Integer.parseInt(inputParser.nextToken());

        // Get the number of queries
        int K = Integer.parseInt(inputParser.nextToken());

        // Get the string S
        String S = inputParser.nextToken();

        // Initialize segment count
        Deque<Integer> segCnt = new ArrayDeque<>();

        // Iterate through the string and count the number of segments
        for (int i = 0; i < N - 1; i++) {
            // Check if the current character is different from the next character
            if (S.charAt(i) != S.charAt(i + 1)) {
                // Add 1 to the segment count
                segCnt.add(1);
            }
        }

        // Calculate the current happiness
        int curHappy = N - 1 - segCnt.size();

        // Check if the number of queries is greater than or equal to the number of segments
        int ans;
        if (2 * K >= segCnt.size()) {
            // If yes, then the answer is the total number of segments
            ans = N - 1;
        } else {
            // Otherwise, the answer is the current happiness plus twice the number of queries
            ans = curHappy + 2 * K;
        }

        // Print the answer
        System.out.println(ans);
    }
}

// <END-OF-CODE>
