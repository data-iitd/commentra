import java.util.Scanner;

public class Main {
    public static boolean search(int[] A, int n, int key) {
        int i = 0;
        A[n] = key; // This is a trick to avoid using a sentinel value
        while (A[i] != key) {
            i++;
        }
        return i != n;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] A = new int[10000 + 1];
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        int q = scanner.nextInt();
        int sum = 0;
        for (int i = 0; i < q; i++) {
            int key = scanner.nextInt();
            if (search(A, n, key)) {
                sum++;
            }
        }
        System.out.println(sum);
        scanner.close();
    }
}

// <END-OF-CODE>
