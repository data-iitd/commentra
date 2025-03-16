import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] out = new int[n];
        int[] comp = new int[n];
        for (int i = 0; i < n; i++) {
            comp[i] = i + 2;
        }

        for (int i = 0; i < m; i++) {
            int l = scanner.nextInt();
            int r = scanner.nextInt();
            int x = scanner.nextInt();
            int t = l - 1;
            while (t < r) {
                int nextVal = comp[t];
                if (out[t] == 0 && t + 1 != x) {
                    out[t] = x;
                }
                comp[t] = r + 1 > x ? x : r + 1;
                t = nextVal - 1;
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.print(out[i] + " ");
        }
    }
}

