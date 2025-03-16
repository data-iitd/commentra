import java.util.*;

public class Main {
    private static final int MOD = (int) (1e9 + 7);  // Define a constant for modulo operation
    private static Scanner scanner = new Scanner(System.in);  // Scanner for input

    public static void main(String[] args) {
        int N = gi();  // Read the number of elements N from the input
        int K = gi();  // Read the parameter K from the input
        String S = gw();  // Read the string S from the input

        int segCnt = 0;  // Initialize a counter for the number of segments
        for (int i = 0; i < N - 1; i++) {  // Loop through the string to count segments
            if (S.charAt(i) != S.charAt(i + 1)) {  // Check if the current character is different from the next
                segCnt++;  // Increment the segment counter if a change is found
            }
        }

        int curHappy = N - 1 - segCnt;  // Calculate the initial happiness based on the number of segments

        int ans;  // Variable to hold the final answer
        if (2 * K >= segCnt) {  // Check if the number of operations allows for maximum happiness
            ans = N - 1;  // If yes, set the answer to the maximum possible happiness
        } else {
            ans = curHappy + 2 * K;  // Otherwise, adjust the happiness based on the number of operations
        }

        System.out.println(ans);  // Print the final happiness value
    }

    private static int gi() {  // Define a function to get the next integer from the input
        return Integer.parseInt(scanner.next());  // Read the next token and convert it to an integer
    }

    private static String gw() {  // Define a function to get the next string from the input
        return scanner.next();  // Read the next token as a string
    }
}
// <END-OF-CODE>
