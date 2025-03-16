import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        while (t-- > 0) {
            String x = scanner.nextLine();
            int[] s = new int[x.length()];
            for (int i = 0; i < x.length(); i++) {
                if (x.charAt(i) == 'O') {
                    s[i] = 0;
                } else {
                    s[i] = 1;
                }
            }

            List<int[]> tot = new ArrayList<>();
            for (int i = 1; i <= 12; i++) {
                if (12 % i == 0) {
                    if (help(i, 12 / i, s)) {
                        tot.add(new int[]{12 / i, i});
                    }
                }
            }

            System.out.print(tot.size() + " ");
            Collections.sort(tot, (a, b) -> a[1] - b[1]);
            for (int[] arr : tot) {
                System.out.print(arr[1] + "x" + arr[0] + " ");
            }
            System.out.println();
        }
    }

    public static boolean help(int a, int b, int[] l) {
        int n = l.length;
        for (int i = 0; i <= n - a; i++) {
            int sum = 0;
            for (int j = i; j < i + a; j++) {
                sum += l[j];
            }
            if (sum == b) {
                return true;
            }
        }
        return false;
    }
}
