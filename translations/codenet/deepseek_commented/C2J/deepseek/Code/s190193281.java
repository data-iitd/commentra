public class Main {
    // Define constants for the maximum sizes of arrays S and T
    static final int N = 1000000;
    static final int Q = 50000;

    // Declare variables
    static int n, S[], T[];

    // Function to perform binary search on array S
    static boolean binarySearch(int key) {
        int left = 0, right = n, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (S[mid] == key) return true;
            else if (key < S[mid]) right = mid;
            else left = mid + 1;
        }
        return false;
    }

    // Main function
    public static void main(String[] args) {
        int i, q, c = 0;

        // Read the size of array S
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        S = new int[n];
        for (i = 0; i < n; i++) {
            S[i] = scanner.nextInt();
        }

        // Read the size of array T
        q = scanner.nextInt();
        T = new int[q];
        for (i = 0; i < q; i++) {
            T[i] = scanner.nextInt();
            if (binarySearch(T[i])) c++;
        }

        // Print the count of elements in T that are also in S
        System.out.println(c);
    }
}
