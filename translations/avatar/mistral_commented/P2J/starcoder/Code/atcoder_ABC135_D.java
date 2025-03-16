########
# Code #
########

// Import necessary libraries
import java.util.*;

// Function to take input from standard input
public static String input() {
    return new Scanner(System.in).nextLine();
}

// Function to read an integer
public static int I() {
    return Integer.parseInt(input());
}

// Function to read a list of integers
public static List<Integer> III() {
    return Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
}

// Function to read a list of lists (2D array)
public static List<List<Integer>> Line(int N) {
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    for (int i = 0; i < N; i++) {
        ans.add(III());
    }
    return ans;
}

// Main function
public static void main(String[] args) {
    // Read the string S and its length n
    String S = input();
    int n = S.length();

    // Base case: if the length of the string is 1
    if (n == 1) {
        // Check if the string is '5' or '?' and print 1 if true, else print 0
        if (S.equals("5") || S.equals("?")) {
            System.out.println(1);
        } else {
            System.out.println(0);
            return;
        }
    }

    // Initialize a 2D array dp of size (n, 13) with all elements initialized to 0
    int[][] dp = new int[n][13];

    // Iterate through each index i from 0 to n-1
    for (int i = 0; i < n; i++) {
        // If i is the first index, process it differently
        if (i == 0) {
            // If the character at index i is not '?', update the dp array accordingly
            if (S.charAt(i)!= '?') {
                dp[i][(int) (S.charAt(i) - '0')] += 1;
            }
            // If the character at index i is '?', update all elements in the dp array accordingly
            else {
                for (int j = 0; j < 10; j++) {
                    dp[i][j] += 1;
                }
            }
        }
        // If i is not the first index, process it differently
        else {
            // If the character at index i is not '?', update the dp array accordingly
            if (S.charAt(i)!= '?') {
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + (int) (S.charAt(i) - '0')) % 13] += dp[i - 1][k];
                }
            }
            // If the character at index i is '?', update all elements in the dp array accordingly
            else {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                    }
                }
                // Update all elements in the dp array with the current value modulo mod
                for (int k = 0; k < 13; k++) {
                    dp[i][k] %= 1000000007;
                }
            }
        }
    }

    // Print the final answer, which is dp[n-1][5]
    System.out.println(dp[n - 1][5]);
}

