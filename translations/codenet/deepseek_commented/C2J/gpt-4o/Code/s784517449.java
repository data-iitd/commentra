import java.util.Scanner;

public class BinarySearchExample {
    static int[] A = new int[1000000];
    static int n;

    /* 
     * binarySearch method performs a binary search on the array A to find a given key.
     * It returns true if the key is found, otherwise it returns false.
     */
    static boolean binarySearch(int key) {
        int left = 0;
        int right = n;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (key == A[mid]) return true; // key found
            if (key > A[mid]) left = mid + 1; // search in the right half
            else right = mid; // search in the left half
        }
        return false;
    }

    /* 
     * main method is the entry point of the program.
     * It reads the size of the array and the elements of the array from the user.
     * It then reads the number of queries and performs binary search for each query.
     * Finally, it prints the number of elements found.
     */
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
            if (binarySearch(k))
                sum++;
        }
        System.out.println(sum);
        scanner.close();
    }
}

// <END-OF-CODE>
