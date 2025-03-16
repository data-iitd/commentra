
import java.util.Scanner;

public class s846328722{
    // Function prototype for linear search
    public static boolean linersearch(int[] a, int n, int key) {
        int i = 0;

        // Search for the key in the array
        while(a[i]!= key) {
            i++; // Increment index until the key is found
        }
        
        // Return true if the key was found within the original array bounds
        return i!= n;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i, n, s[] = new int[100000], q, t, count = 0;

        // Read the number of elements in the array
        n = scanner.nextInt();

        // Read n elements into the array s
        for(i = 0; i < n; i++) {
            s[i] = scanner.nextInt();
        }

        // Read the number of queries
        q = scanner.nextInt();

        // Process each query to check if the element exists in the array
        for(i = 0; i < q; i++) {
            t = scanner.nextInt(); // Read the query element
            // Use linear search to check if the element t is in the array s
            if(linersearch(s, n, t)) count++; // Increment count if found
        }

        // Output the total count of found elements
        System.out.println(count);

        scanner.close();
    }
}

