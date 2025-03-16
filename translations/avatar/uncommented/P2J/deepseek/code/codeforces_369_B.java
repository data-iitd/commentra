import java.util.Scanner;

public class Main {
    public static int[] getNums(int num, int t) {
        int[] result = new int[num];
        for (int i = 0; i < num; i++) {
            result[i] = t / num + (i < t % num ? 1 : 0);
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        int sa = scanner.nextInt();
        int sk = scanner.nextInt();

        int[] ans1 = getNums(k, sk);
        int[] ans2 = getNums(n - k, sa - sk);

        int[] ans = new int[n];
        for (int i = 0; i < k; i++) {
            ans[i] = ans1[i];
        }
        for (int i = k; i < n; i++) {
            ans[i] = ans2[i - k];
        }

        for (int i = 0; i < n; i++) {
            System.out.print(ans[i]);
            if (i < n - 1) {
                System.out.print(" ");
            }
        }
    }
}
