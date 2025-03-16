public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        long[] T = new long[N];
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            T[i] = scanner.nextLong();
            A[i] = scanner.nextLong();
        }
        long t = T[0];
        long a = A[0];
        for (int i = 1; i < N; i++) {
            long r = Math.max((t + T[i] - 1) / T[i], (a + A[i] - 1) / A[i]);
            t = T[i] * r;
            a = A[i] * r;
        }
        System.out.println(t + a);
    }
}
