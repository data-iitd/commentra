import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        String S = scanner.nextLine();
        calculate(N, S);
    }

    public static void calculate(int n, String s) {
        char[] arr = s.toCharArray();
        int rNum = 0, gNum = 0, bNum = 0;

        // Count occurrences of R, G, B
        for (char c : arr) {
            if (c == 'R') rNum++;
            else if (c == 'G') gNum++;
            else if (c == 'B') bNum++;
        }

        int sum = 0;
        for (int step = 1; step <= Math.ceil(n / 2.0); step++) {
            for (int i = 0; i <= n - 2 * step; i++) {
                String substring = "" + arr[i] + arr[i + step] + arr[i + step * 2];
                if (substring.equals("RGB") || substring.equals("RBG") || 
                    substring.equals("BGR") || substring.equals("BRG") || 
                    substring.equals("GBR") || substring.equals("GRB")) {
                    sum++;
                }
            }
        }
        System.out.println(rNum * gNum * bNum - sum);
    }
}

// <END-OF-CODE>
