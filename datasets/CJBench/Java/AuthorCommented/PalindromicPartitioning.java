
import java.util.Scanner;

/**
 * Provides functionality to solve the Palindrome Partitioning II problem, which involves finding
 * the minimum number of partitions needed to divide a given string into palindromic substrings.
 *
 * <p>
 * The problem is solved using dynamic programming. The approach involves checking all possible
 * substrings and determining whether they are palindromes. The minimum number of cuts required
 * for palindrome partitioning is computed in a bottom-up manner.
 * </p>
 *
 * <p>
 * Example:
 * <ul>
 *     <li>Input: "nitik" => Output: 2 (Partitioning: "n | iti | k")</li>
 *     <li>Input: "ababbbabbababa" => Output: 3 (Partitioning: "aba | b | bbabb | ababa")</li>
 * </ul>
 * </p>
 *
 * @see <a href="https://leetcode.com/problems/palindrome-partitioning-ii/">Palindrome Partitioning II</a>
 * @see <a href="https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/">Palindrome Partitioning (GeeksforGeeks)</a>
 */
public final class PalindromicPartitioning {
    private PalindromicPartitioning() {
    }

    public static int minimalPartitions(String word) {
        int len = word.length();
        /* We Make two arrays to create a bottom-up solution.
           minCuts[i] = Minimum number of cuts needed for palindrome partitioning of substring
           word[0..i] isPalindrome[i][j] = true if substring str[i..j] is palindrome Base Condition:
           C[i] is 0 if P[0][i]= true
         */
        int[] minCuts = new int[len];
        boolean[][] isPalindrome = new boolean[len][len];

        // Every substring of length 1 is a palindrome
        for (int i = 0; i < len; i++) {
            isPalindrome[i][i] = true;
        }

        /* subLen is substring length. Build the solution in bottom up manner by considering all
         * substrings of length starting from 2 to n. */
        for (int subLen = 2; subLen <= len; subLen++) {
            // For substring of length subLen, set different possible starting indexes
            for (int i = 0; i < len - subLen + 1; i++) {
                int j = i + subLen - 1; // Ending index
                // If subLen is 2, then we just need to
                // compare two characters. Else need to
                // check two corner characters and value
                // of P[i+1][j-1]
                if (subLen == 2) {
                    isPalindrome[i][j] = (word.charAt(i) == word.charAt(j));
                } else {
                    isPalindrome[i][j] = (word.charAt(i) == word.charAt(j)) && isPalindrome[i + 1][j - 1];
                }
            }
        }

        // We find the minimum for each index
        for (int i = 0; i < len; i++) {
            if (isPalindrome[0][i]) {
                minCuts[i] = 0;
            } else {
                minCuts[i] = Integer.MAX_VALUE;
                for (int j = 0; j < i; j++) {
                    if (isPalindrome[j + 1][i] && 1 + minCuts[j] < minCuts[i]) {
                        minCuts[i] = 1 + minCuts[j];
                    }
                }
            }
        }

        // Return the min cut value for complete
        // string. i.e., str[0..n-1]
        return minCuts[len - 1];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String inputString = scanner.nextLine();

        int result = minimalPartitions(inputString);
        System.out.println("Minimum number of partitions required: " + result);
    }
}
