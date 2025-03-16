import java.util.Scanner;

public class LinearSearch {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, q, count = 0;

        // Read the number of elements
        n = scanner.nextInt();
        int[] s = new int[100000];

        // Read the elements into the array s
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextInt();
        }

        // Read the number of queries
        q = scanner.nextInt();

        // Perform a linear search for each query
        for (int i = 0; i < q; i++) {
            int t = scanner.nextInt();
            if (linearSearch(s, n, t)) count++;
        }

        // Print the total count of successful searches
        System.out.println(count);
        scanner.close();
    }

    public static boolean linearSearch(int[] a, int n, int key) {
        // Modify the array to facilitate the search
        a[n] = key;

        // Perform the linear search
        int i = 0;
        while (a[i] != key) {
            i++;
        }

        // Return true if the key is found, false otherwise
        return i != n;
    }
}

// <END-OF-CODE>
