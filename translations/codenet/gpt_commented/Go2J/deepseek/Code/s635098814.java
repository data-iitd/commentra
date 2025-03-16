import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static void read() throws IOException {
        String str;
        while ((str = br.readLine()) != null) {
            char[] S = str.toCharArray();
            for (char c : S) {
                if ('a' <= c && c <= 'z') {
                    // Increment count for lowercase letters.
                    memo[c - 'a']++;
                } else if ('A' <= c && c <= 'Z') {
                    // Increment count for uppercase letters.
                    memo[c - 'A']++;
                }
            }
        }
    }

    static int[] memo = new int[26];

    public static void main(String[] args) throws IOException {
        read();
        for (int i = 0; i < 26; i++) {
            out.println((char) (i + 'a') + " : " + memo[i]);
        }
        out.flush();
    }
}
