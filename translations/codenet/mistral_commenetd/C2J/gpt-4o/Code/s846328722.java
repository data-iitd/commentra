import java.util.Scanner; // Importing the Scanner class for user input

public class LinearSearch {
    // Function declaration for linear search
    public static boolean linearSearch(int[] a, int n, int key) {
        int i = 0; // Initializing index i to zero

        // Adding the key to the end of the array for the case when the key is already present at the beginning
        a[n] = key;

        // Linear search algorithm to find the index of the key in the array
        while (a[i] != key) {
            i++; // Incrementing index i until the key is found
        }

        // Returning true if the key is found, and false otherwise
        return i != n;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for user input
        int n; // Declaring variable n for array size
        int[] s = new int[100001]; // Declaring an array s of size 100001
        int q; // Declaring variable q for number of queries
        int t; // Declaring variable t for query elements
        int count = 0; // Initializing count to zero

        // Reading the size of the array from user input
        n = scanner.nextInt();

        // Reading array elements into the array s
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextInt();
        }

        // Reading the number of queries from user input
        q = scanner.nextInt();

        // Looping through each query
        for (int i = 0; i < q; i++) {
            t = scanner.nextInt(); // Reading a query element from user input

            // Calling the linear search function to check if the query element is present in the array
            if (linearSearch(s, n, t)) count++; // If the query element is present, increment the count
        }

        // Printing the final count of query elements present in the array
        System.out.println(count);

        scanner.close(); // Closing the scanner
    }
}

// <END-OF-CODE>
