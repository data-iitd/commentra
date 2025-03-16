public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] a = new int[200000];
        int[] tmpa = new int[200000];
        int[] light = new int[200010];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        for (int i = 0; i < n; i++) {
            int r, l;
            r = i - a[i];
            l = i + a[i];
            light[Math.max(0, r)]++;
            light[Math.min(n + 1, l + 1)]--;
        }

        for (int i = 0; i < k; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                tmpa[j] = a[j];
                sum += light[j];
                a[j] = sum;
            }
            for (int j = 0; j < n; j++) {
                int r = j - tmpa[j];
                int l = j + tmpa[j];
                light[Math.max(0, r)]--;
                light[Math.min(n + 1, l + 1)]++;
                r = j - a[j];
                l = j + a[j];
                light[Math.max(0, r)]++;
                light[Math.min(n + 1, l + 1)]--;
            }
            boolean isSame = true;
            for (int j = 0; j < n - 1; j++) {
                if (a[j] != a[j + 1]) {
                    isSame = false;
                    break;
                }
            }
            if (isSame && a[0] == n) {
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            System.out.print(a[j]);
            System.out.print(j == n - 1 ? "\n" : " ");
        }
    }
}
