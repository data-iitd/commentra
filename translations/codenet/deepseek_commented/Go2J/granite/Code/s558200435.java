
import java.util.Scanner;

public class s558200435{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // 1. Reading the input number of elements (n)
        int[] a = new int[n]; // 2. Reading the elements into an array (a)
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        int[] b = new int[n]; // 3. Creating an array (b) to store the longest increasing subsequence
        int j = 0;
        for (int i = 0; i < n; i++) { // 4. Finding the longest increasing subsequence
            if (j == 0 || a[i] > b[j - 1]) {
                b[j++] = a[i];
            } else {
                int k = binarySearch(b, 0, j, a[i]);
                b[k] = a[i];
            }
        }

        System.out.println(j); // 5. Outputting the length of the longest increasing subsequence
        scanner.close();
    }

    private static int binarySearch(int[] arr, int left, int right, int target) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}

