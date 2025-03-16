import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        int sa = scanner.nextInt();
        int sk = scanner.nextInt();

        int[] ans = getNums(k, sk)
                .concat(getNums(n - k, sa - sk))
                .toArray();

        for (int i = 0; i < ans.length; i++) {
            if (i > 0) {
                System.out.print(" ");
            }
            System.out.print(ans[i]);
        }
        System.out.println();
    }

    public static List<Integer> getNums(int num, int t) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < num; i++) {
            int quotient = t / num;
            if (i < t % num) {
                quotient++;
            }
            result.add(quotient);
        }
        return result;
    }
}
