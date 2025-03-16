import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();

        // Reverse the string and the dictionary words
        String[] divide = {"dream", "dreamer", "erase", "eraser"};
        ArrayList<String> reversedDivide = new ArrayList<>();
        for (String word : divide) {
            StringBuilder sb = new StringBuilder(word);
            reversedDivide.add(sb.reverse().toString());
        }
        StringBuilder sbS = new StringBuilder(S);
        S = sbS.reverse().toString();

        // Check from the start
        boolean can = true;
        for (int i = 0; i < S.length();) {
            boolean can2 = false; // Check if any of the dictionary words can divide the current string
            for (String d : reversedDivide) {
                if (S.startsWith(d, i)) { // Check if the current string starts with the dictionary word
                    can2 = true;
                    i += d.length(); // Move the index forward if a match is found
                }
            }
            if (!can2) { // If no word can divide the current string
                can = false;
                break;
            }
        }

        // Output the result
        if (can) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
