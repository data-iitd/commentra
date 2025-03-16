import java.util.Scanner;
import java.util.regex.Pattern;

public class SentenceSplitter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        int ans = 1, sumL = 0;

        String input = scanner.nextLine();
        String[] sentences = input.split("[.?!]");
        
        for (String s : sentences) {
            s = s.trim() + ".";
            int L = s.length();
            if (L > 1) {
                if (L > n) {
                    System.out.println("Impossible");
                    return;
                }
                if (sumL + L + (sumL > 0 ? 1 : 0) > n) {
                    ans++;
                    sumL = L;
                } else {
                    sumL = sumL + L + (sumL > 0 ? 1 : 0);
                }
            }
        }
        System.out.println(ans);
    }
}
// <END-OF-CODE>
