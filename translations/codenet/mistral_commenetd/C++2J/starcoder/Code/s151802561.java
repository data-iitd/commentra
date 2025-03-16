import java.util.*;

public class SelectionSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] A = new int[n];
        int i, j, t, sw = 0, mini;
        for (i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }
        for (i = 0; i < n; i++) {
            mini = i;
            for (j = i; j < n; j++) {
                if (A[j] < A[mini]) {
                    mini = j;
                }
            }
            t = A[i];
            A[i] = A[mini];
            A[mini] = t;
            if (i!= mini) sw++;
        }
        System.out.print("Sorted array: ");
        for (i = 0; i < n; i++) {
            if (i!= 0) System.out.print(" ");
            System.out.print(A[i]);
        }
        System.out.println();
        System.out.println("Number of swaps: " + sw);
    }
}
