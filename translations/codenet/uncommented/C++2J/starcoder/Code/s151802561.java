
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; i++) A[i] = sc.nextInt();
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int min = i;
            for (int j = i; j < n; j++) {
                if (A[j] < A[min]) min = j;
            }
            if (i!= min) {
                int t = A[i]; A[i] = A[min]; A[min] = t;
                swaps++;
            }
        }
        System.out.println(swaps);
        for (int i = 0; i < n; i++) {
            if (i!= 0) System.out.print(" ");
            System.out.print(A[i]);
        }
        System.out.println();
    }
}

