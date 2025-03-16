import java.util.Scanner;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        String input = scanner.nextLine();

        String[] sentences = input.split("[.?!]");
        int ans = 1;
        int sumL = 0;

        for (String s : sentences) {
            s = s.trim();
            s += ".";

            int L = s.length();

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

        System.out.println(ans);
    }
}
