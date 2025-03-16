import java.util.*; // Importing the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);

        // Reading the number of elements (n) from the user
        int n = Integer.parseInt(sc.nextLine());
        
        // Initializing a variable to store the result of matching elements
        int result = 0;

        // Creating two arrays to hold the input values
        int[] h = new int[n]; // Array to store the first set of integers
        int[] g = new int[n]; // Array to store the second set of integers

        // Reading n integers into the first array (h)
        for (int i = 0; i < n; i++) {
            h[i] = sc.nextInt(); // Storing input in array h
        }

        // Reading n integers into the second array (g)
        for (int i = 0; i < n; i++) {
            g[i] = sc.nextInt(); // Storing input in array g
        }

        // Comparing each element of array h with each element of array g
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If a match is found, increment the result counter
                if (h[i] == g[j]) {
                    result++; // Incrementing the count of matches
                }
            }
        }

        // Outputting the total number of matches found
        System.out.println(result);
    }
}
