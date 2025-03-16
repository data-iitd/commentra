
// Function prototype for linear search
int linersearch(int [], int, int);

public class Main {
    public static void main(String[] args) {
        int i, n, s[], q, t, count = 0;

        // Read the number of elements in the array
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // Read n elements into the array s
        s = new int[n];
        for(i = 0; i < n; i++) {
            s[i] = sc.nextInt();
        }

        // Read the number of queries
        q = sc.nextInt();

        // Process each query to check if the element exists in the array
        for(i = 0; i < q; i++) {
            t = sc.nextInt(); // Read the query element
            // Use linear search to check if the element t is in the array s
            if(linersearch(s, n, t)) count++; // Increment count if found
        }

        // Output the total count of found elements
        System.out.println(count);
    }

    // Function to perform linear search
    public static int linersearch(int a[], int n, int key) {
        int i = 0;

        // Sentinel value: place the key at the end of the array
        a[n] = key;
  
        // Search for the key in the array
        while(a[i] != key) {
            i++; // Increment index until the key is found
        }
    
        // Return true if the key was found within the original array bounds
        return i != n;
    }
}

