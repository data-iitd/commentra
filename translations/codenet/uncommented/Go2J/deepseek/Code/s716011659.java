public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();

        int[] arrA = new int[n];
        for (int i = 0; i < n; i++) {
            arrA[i] = scanner.nextInt();
        }

        int[] cumSumA = new int[n + 1];
        cumSumA[0] = 0;
        for (int i = 0; i < n; i++) {
            cumSumA[i + 1] = cumSumA[i] + arrA[i];
        }

        double ans = Double.MAX_VALUE;
        for (int i = 1; i < n; i++) {
            double diff = Math.abs((double) (cumSumA[n] - 2 * cumSumA[i]));
            if (diff < ans) {
                ans = diff;
            }
        }

        System.out.println((int) ans);
    }
}
