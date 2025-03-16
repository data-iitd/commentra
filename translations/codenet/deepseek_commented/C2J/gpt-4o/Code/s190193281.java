import java.util.Scanner;

// Define constants for the maximum sizes of arrays S and T
public class Main {
    private static final int N = 1000000;
    private static final int Q = 50000;

    // Declare variables
    private static int n;
    private static int[] S = new int[N];
    private static int[] T = new int[Q];

    // Function to perform binary search on array S
    private static int binarySearch(int key) {
        int left = 0, right = n, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (S[mid] == key) return 1;
            else if (key < S[mid]) right = mid;
            else left = mid + 1;
        }
        return 0;
    }

    // Main function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int c = 0;

        // Read the size of array S
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            S[i] = scanner.nextInt();
        }

        // Read the size of array T
        int q = scanner.nextInt();
        for (int i = 0; i < q; i++) {
            T[i] = scanner.nextInt();
            if (binarySearch(T[i]) == 1) c++;
        }

        // Print the count of elements in T that are also in S
        System.out.println(c);
        scanner.close();
    }
}

// <END-OF-CODE>
