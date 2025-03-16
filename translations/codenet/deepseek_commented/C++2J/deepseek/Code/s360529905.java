public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        int[] a = new int[N];
        int[] b = new int[N];
        int frontHalf, backHalf;

        for (int i = 0; i < N; i++) {
            a[i] = scanner.nextInt();
            b[i] = a[i];
        }

        java.util.Arrays.sort(b);

        frontHalf = b[N / 2 - 1];
        backHalf = b[N / 2];

        for (int i = 0; i < N; i++) {
            if (a[i] < backHalf) {
                System.out.println(backHalf);
            } else {
                System.out.println(frontHalf);
            }
        }
    }
}
