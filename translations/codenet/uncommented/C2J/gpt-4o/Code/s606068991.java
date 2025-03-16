import java.util.Scanner;

public class InsertionSort {
    
    public static void white(int n, int[] A) {
        for (int i = 0; i < n - 1; i++) {
            System.out.print(A[i] + " ");
        }
        System.out.println(A[n - 1]);
    }

    public static void insertionsort(int n, int[] A) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (A[i] < A[j]) {
                    int a = A[i];
                    A[i] = A[j];
                    A[j] = a;
                }
            }
            white(n, A);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] A = new int[100];
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        insertionsort(n, A);
        scanner.close();
    }
}

// <END-OF-CODE>
