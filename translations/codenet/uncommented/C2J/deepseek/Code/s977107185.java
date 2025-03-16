public class BubbleSort {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        int[] A = new int[100];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        int tmp, count = 0;
        for (int i = 0; i < N - 1; i++) {
            for (int j = N - 1; j > i; j--) {
                if (A[j] < A[j - 1]) {
                    tmp = A[j];
                    A[j] = A[j - 1];
                    A[j - 1] = tmp;
                    count++;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            System.out.print(A[i]);
            if (i < N - 1) System.out.print(" ");
        }
        System.out.println();
        System.out.println(count);
    }
}
