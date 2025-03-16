public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int k = scanner.nextInt();
        long[] a = new long[100100];
        for (int i = 0; i < k; i++) {
            a[i] = scanner.nextLong();
        }

        long min = 2, max = 3;

        if (a[k - 1] != 2) {
            System.out.println(-1);
            return;
        }

        for (int i = k - 2; i >= 0; i--) {
            if (a[i] > max) {
                System.out.println(-1);
                return;
            } else {
                max = ((max / a[i]) + 1) * a[i] - 1;
                if (min % a[i] != 0) {
                    min = ((min / a[i]) + 1) * a[i];
                }
            }

            if (max <= min) {
                System.out.println(-1);
                return;
            }
        }

        System.out.println(min + " " + max);
    }
}
