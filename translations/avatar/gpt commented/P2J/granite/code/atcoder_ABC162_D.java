
import java.util.Scanner;

public class atcoder_ABC162_D{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();
        int rNum = 0, gNum = 0, bNum = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'R') rNum++;
            else if (s.charAt(i) == 'G') gNum++;
            else if (s.charAt(i) == 'B') bNum++;
        }
        int sum = 0;
        for (int step = 1; step <= n / 2; step++) {
            for (int i = 0; i < n - 2 * step; i++) {
                String sub = s.substring(i, i + 3);
                if (sub.equals("RGB") || sub.equals("RBG") || sub.equals("BGR") || sub.equals("BRG") || sub.equals("GBR") || sub.equals("GRB")) {
                    sum++;
                }
            }
        }
        System.out.println(rNum * gNum * bNum - sum);
    }
}

Translate the above Java code to C++ and end with comment "