
import java.util.*;

// Function to read input from standard input
public static String input() {
    Scanner sc = new Scanner(System.in);
    return sc.nextLine();
}

// Define the modulo constant
public static final int mod = 1000000007;

// Helper functions to read different types of input
public static int I() {
    return Integer.parseInt(input());
}

public static int[] II() {
    return Arrays.stream(input().split(" ")).mapToInt(Integer::parseInt).toArray();
}

public static int[] III() {
    return Arrays.stream(input().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// Function to read N lines of input and return them as a list of tuples
public static List<List<Integer>> Line(int N) {
    List<List<Integer>> read_all = new ArrayList<>();
    for (int i = 0; i < N; i++) {
        read_all.add(Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList()));
    }
    return read_all;
}

// Read the string input S
String S = input();
int n = S.length();

// Handle the case where the input string length is 1
if (n == 1) {
    if (S.equals("5") || S.equals("?")) {
        System.out.println(1);  // Output 1 if the single character is '5' or '?'
    } else {
        System.out.println(0);  // Output 0 for any other single character
    }
    System.exit(0);
}

// Initialize a 2D list for dynamic programming
int[][] dp = new int[n][13];

// Fill the dp table based on the characters in S
for (int i = 0; i < n; i++) {
    if (i == 0) {
        // Handle the first character
        if (!S.charAt(i) + "".equals("?")) {
            dp[i][Integer.parseInt(S.charAt(i) + "")] += 1;  // Increment the count for the specific digit
        } else {
            // If the character is '?', increment counts for all digits (0-9)
            for (int j = 0; j < 10; j++) {
                dp[i][j] += 1;
            }
        }
    } else {
        // Process subsequent characters
        if (!S.charAt(i) + "".equals("?")) {
            // If the character is a specific digit
            for (int k = 0; k < 13; k++) {
                dp[i][(k * 10 + Integer.parseInt(S.charAt(i) + "")) % 13] += dp[i - 1][k];
            }
        } else {
            // If the character is '?', consider all digits (0-9)
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                }
            }

            // Apply modulo to keep the values manageable
            for (int k = 0; k < 13; k++) {
                dp[i][k] %= mod;
            }
        }
    }
}

// Output the count of valid numbers that are divisible by 13 and end with digit 5
System.out.println(dp[n - 1][5]);

