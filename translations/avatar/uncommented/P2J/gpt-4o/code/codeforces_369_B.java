import java.util.Scanner;

public class Main {
    public static int[] getNums(int num, int t) {
        int[] result = new int[num];
        for (int i = 0; i < num; i++) {
            result[i] = (i < t % num) ? (t / num + 1) : (t / num);
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

        int[] ans = new int[k + (n - k)];
        int[] firstPart = getNums(k, sk);
        int[] secondPart = getNums(n - k, sa - sk);

        System.arraycopy(firstPart, 0, ans, 0, k);
        System.arraycopy(secondPart, 0, ans, k, n - k);

        for (int i = 0; i < ans.length; i++) {
            System.out.print(ans[i]);
            if (i < ans.length - 1) {
                System.out.print(" ");
            }
        }
        scanner.close();
    }
}
// <END-OF-CODE>
