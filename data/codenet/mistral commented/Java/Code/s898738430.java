import java.util.*; // Importing the utility class Scanner from the java.util package

public class Main {

    public static void main(String[] args) { // Main method is the entry point of the Java application
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the standard input

        int n; // Declaring an integer variable 'n' to store the number of elements in the array

        // Reading the number of elements 'n' from the standard input
        n = sc.nextInt();

        int[] a; // Declaring an integer array 'a' of size 'n'

        // Allocating memory for the integer array 'a' of size 'n'
        a = new int[n];

        // Reading the elements of the array 'a' from the standard input
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int ans = 0; // Declaring and initializing an integer variable 'ans' to 0

        // Iterating through the array 'a' from the second index to the second last index
        for (int i = 1; i < n-1; i++) {

            // Checking if the current element 'a[i]' is not the minimum of its neighboring elements
            if(a[i] != Math.min(a[i-1], Math.min(a[i], a[i+1]))){

                // If the condition is true, increment the variable 'ans'
                ans++;

            }

        }

        // Printing the value of the variable 'ans' to the standard output
        System.out.println(ans);

        // Closing the Scanner object to release the system resources
        sc.close();

    }

}
