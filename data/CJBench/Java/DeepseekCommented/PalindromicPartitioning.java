
import java.util.Scanner;
public final class Main {
    private Main() {
    }
    /**
     * Calculates the minimal number of partitions required to partition a given string into palindromes.
     * @param word the input string
     * @return the minimal number of partitions required
     */
    public static int minimalPartitions(String word) {
        int len = word.length();
        int[] minCuts = new int[len];
        boolean[][] isPalindrome = new boolean[len][len];
        // Initialize single character palindromes
        for (int i = 0; i < len; i++) {
            isPalindrome[i][i] = true;
        }
        // Calculate all palindromes of length 2 to len
        for (int subLen = 2; subLen <= len; subLen++) {
            for (int i = 0; i < len - subLen + 1; i++) {
                int j = i + subLen - 1; 
                if (subLen == 2) {
                    isPalindrome[i][j] = (word.charAt(i) == word.charAt(j));
                } else {
                    isPalindrome[i][j] = (word.charAt(i) == word.charAt(j)) && isPalindrome[i + 1][j - 1];
                }
            }
        }
        // Calculate the minimal cuts required
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
        return minCuts[len - 1];
    }
    /**
     * Main method to read input string and print the minimal number of partitions required.
     * @param args command line arguments
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String inputString = scanner.nextLine();
        int result = minimalPartitions(inputString);
        System.out.println("Minimum number of partitions required: " + result);
    }
}