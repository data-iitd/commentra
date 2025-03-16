
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        String t = scanner.next();
        int max = 0;
        for (int i = 0; i <= s.length() - t.length(); i++) {
            int c = 0;
            for (int j = 0; j < t.length(); j++) {
                if (s.charAt(i + j) == t.charAt(j)) {
                    c++;
                }
            }
            if (max < c) {
                max = c;
            }
        }
        System.out.println(t.length() - max);
    }
}

