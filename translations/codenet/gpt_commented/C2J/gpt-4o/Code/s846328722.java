import java.util.Scanner;

public class LinearSearch {
    
    // Function prototype for linear search
    public static boolean linearSearch(int[] a, int n, int key) {
        int i = 0;

        // Sentinel value: place the key at the end of the array
        int[] extendedArray = new int[n + 1];
        System.arraycopy(a, 0, extendedArray, 0, n);
        extendedArray[n] = key;

        // Search for the key in the array
        while (extendedArray[i] != key) {
            i++; // Increment index until the key is found
        }

        // Return true if the key was found within the original array bounds
        return i != n;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(); // Read the number of elements in the array
        int[] s = new int[n];

        // Read n elements into the array s
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextInt();
        }

        int q = scanner.nextInt(); // Read the number of queries
        int count = 0;

        // Process each query to check if the element exists in the array
        for (int i = 0; i < q; i++) {
            int t = scanner.nextInt(); // Read the query element
            // Use linear search to check if the element t is in the array s
            if (linearSearch(s, n, t)) count++; // Increment count if found
        }

        // Output the total count of found elements
        System.out.println(count);
        
        scanner.close();
    }
}

// <END-OF-CODE>
