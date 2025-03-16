public class Main {
    public static final int MOD = 1000000007;

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();

        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }

        java.util.Arrays.sort(A);

        int ans = 0;
        int i = 0, j = 0;
        while (j < A.length) {
            if (x >= A[i]) {
                ans++;
                x -= A[i];
                i++;
            } else {
                j++;
            }
        }

        if (x > 0 && n == ans) {
            ans--;
        }

        System.out.println(ans);
    }
}
