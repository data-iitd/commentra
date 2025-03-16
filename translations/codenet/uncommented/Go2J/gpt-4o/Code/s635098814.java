import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    private static final int ALPHABET_NUM = 26;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Map<Character, Integer> memo = new HashMap<>();
        String str;

        while ((str = br.readLine()) != null && !str.isEmpty()) {
            for (char c : str.toCharArray()) {
                if ('a' <= c && c <= 'z') {
                    memo.put(c, memo.getOrDefault(c, 0) + 1);
                } else if ('A' <= c && c <= 'Z') {
                    char lowerC = Character.toLowerCase(c);
                    memo.put(lowerC, memo.getOrDefault(lowerC, 0) + 1);
                }
            }
        }

        for (char i = 'a'; i <= 'z'; i++) {
            System.out.printf("%c : %d\n", i, memo.getOrDefault(i, 0));
        }
    }
}

// <END-OF-CODE>
