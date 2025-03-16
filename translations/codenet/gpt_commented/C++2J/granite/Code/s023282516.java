
import java.util.Scanner;

public class s023282516{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();
        String[] divide = {"dream", "dreamer", "erase", "eraser"};
        boolean can = true;
        int i = 0;
        while (i < S.length()) {
            boolean can2 = false;
            for (String d : divide) {
                if (S.substring(i, i + d.length()).equals(d)) {
                    can2 = true;
                    i += d.length();
                }
            }
            if (!can2) {
                can = false;
                break;
            }
        }
        if (can) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
