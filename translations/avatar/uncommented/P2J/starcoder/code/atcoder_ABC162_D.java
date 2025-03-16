import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        int rNum = 0, gNum = 0, bNum = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'R') rNum++;
            if (s.charAt(i) == 'G') gNum++;
            if (s.charAt(i) == 'B') bNum++;
        }
        for (int step = 1; step <= Math.ceil(n / 2.0); step++) {
            for (int i = 0; i < n - 2 * step; i++) {
                String s1 = s.substring(i, i + step);
                String s2 = s.substring(i + step, i + 2 * step);
                if (s1.equals("RGB") || s1.equals("RBG") || s1.equals("BGR") || s1.equals("BRG") || s1.equals("GBR") || s1.equals("GRB")) {
                    sum++;
                }
                if (s2.equals("RGB") || s2.equals("RBG") || s2.equals("BGR") || s2.equals("BRG") || s2.equals("GBR") || s2.equals("GRB")) {
                    sum++;
                }
            }
        }
        System.out.println(rNum * gNum * bNum - sum);
    }
}
