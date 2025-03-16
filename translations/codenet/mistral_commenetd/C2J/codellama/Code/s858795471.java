
import java.util.Scanner;

public class Search {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }
        int q = sc.nextInt();
        int key = 0;
        int sum = 0;
        for (int i = 0; i < q; i++) {
            key = sc.nextInt();
            if (search(A, n, key)) {
                sum++;
            }
        }
        System.out.println(sum);
    }

    public static boolean search(int[] A, int n, int key) {
        int i = 0;
        A[n] = key;
        while (A[i] != key) {
            i++;
        }
        return i != n;
    }
}

