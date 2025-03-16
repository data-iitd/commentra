import java.util.Scanner;
import java.util.regex.Pattern;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();
        int ans = 1, sumL = 0;
        String s = in.nextLine();
        String[] sentences = s.split(Pattern.quote(".") + "|" + Pattern.quote("?") + "|" + Pattern.quote("!"));
        for (String sentence : sentences) {
            sentence = sentence.trim() + ".";
            int L = sentence.length();
            if (L > 1) {
                if (L > n) {
                    System.out.println("Impossible");
                    return;
                }
                if (sumL + L + (sumL > 0) > n) {
                    ans++;
                    sumL = L;
                } else {
                    sumL = sumL + L + (sumL > 0);
                }
            }
        }
        System.out.println(ans);
    }
}

