public class Main {
    public static void main(String[] args) {
        // Code for B - Traveling AtCoDeer Problem
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();

        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        java.util.Arrays.sort(A);

        int ans = 0;
        for (int i = 1; i < N; i++) {
            ans += A[i] - A[i - 1];
        }

        System.out.println(ans);
    }
}
