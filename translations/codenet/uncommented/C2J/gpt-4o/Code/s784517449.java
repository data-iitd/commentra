import java.util.Scanner;

public class BinarySearchExample {
    static int[] A = new int[1000000];
    static int n;

    /* Binary Search */
    static int binarySearch(int key) {
        int left = 0;
        int right = n;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (key == A[mid]) return 1; /* Found the key */
            if (key > A[mid]) left = mid + 1; /* Search in the right half */
            else right = mid; /* Search in the left half */
        }
        return 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int sum = 0;

        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }

        int q = scanner.nextInt();
        for (int i = 0; i < q; i++) {
            int k = scanner.nextInt();
            if (binarySearch(k) == 1) {
                sum++;
            }
        }

        System.out.println(sum);
        scanner.close();
    }
}

/* <END-OF-CODE> */
