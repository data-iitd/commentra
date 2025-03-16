
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        // Read input until EOF.
        while (sc.hasNext()) {
            String str = sc.nextLine();
            char[] S = str.toCharArray();
            if (S.length == 0) {
                break;
            }
            // Count occurrences of each letter.
            for (int i = 0; i < S.length; i++) {
                char c = S[i];

                if ('a' <= c && c <= 'z') {
                    // Increment count for lowercase letters.
                    memo[c - 'a']++;
                } else if ('A' <= c && c <= 'Z') {
                    // Increment count for uppercase letters.
                    memo[c - 'A']++;
                } else {
                    // Ignore non-alphabet characters.
                    continue;
                }
            }
        }

        // Print the count of each letter.
        for (int i = 0; i < ALPHABET_NUM; i++) {
            System.out.printf("%c : %d\n", (char) (i + 'a'), memo[i]);
        }
    }

    // Define constants for the program.
    private static final int MOD = 1000000000 + 7;
    private static final int ALPHABET_NUM = 26;
    private static final long INF_INT64 = (long) Math.pow(2, 63) - 1;
    private static final long INF_BIT60 = (long) Math.pow(2, 60);

    // Declare memoization array and string variable.
    private static int[] memo = new int[ALPHABET_NUM];
    private static String str;

    // MODはとったか？
    // 遷移だけじゃなくて最後の最後でちゃんと取れよ？

    // 