import java.util.*;

public class InsertionSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }
        insertionsort(n, A);
    }

    public static void insertionsort(int n, int[] A) {
        int i, j, a;
        for (i = 0; i < n; i++) {
            for (j = 0; j < i; j++) {
                if (A[i] < A[j]) {
                    // Swap A[i] and A[j]
                    a = A[i];
                    A[i] = A[j];
                    A[j] = a;
                }
            }
            // Print the array after each insertion
            white(n, A);
        }
    }

    public static void white(int n, int[] A) {
        int i;
        for (i = 0; i < n - 1; i++) {
            System.out.print(A[i] + " ");
        }
        System.out.println(A[i]);
    }
}
