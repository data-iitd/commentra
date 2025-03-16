import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        String S = scanner.next();

        calculate(N, S);
    }

    public static void calculate(int n, String s) {
        char[] arr = s.toCharArray();

        int rNum = 0, gNum = 0, bNum = 0;
        for (char c : arr) {
            if (c == 'R') rNum++;
            else if (c == 'G') gNum++;
            else if (c == 'B') bNum++;
        }

        int sum = 0;
        for (int step = 1; step <= Math.ceil(n / 2.0); step++) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 3; i++) {
                sb.append(arr[i]);
            }
            String colorCombination = sb.toString();

            if (colorCombination.equals("RGB") || colorCombination.equals("RBG") ||
                colorCombination.equals("BGR") || colorCombination.equals("BRG") ||
                colorCombination.equals("GBR") || colorCombination.equals("GRB")) {
                sum++;
            }
        }

        System.out.println(rNum * gNum * bNum - sum);
    }
}
