import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class FrequencyCounter {
    static final int SIZE = (int) (1e5 * 2) + 13; // Define the size of the array

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(); // Read the number of elements 'n'
        int k = scanner.nextInt(); // Read the number of frequencies to consider 'k'

        int[] cnt = new int[SIZE]; // Initialize an array 'cnt' to store the frequency count of each element

        for (int i = 0; i < n; ++i) { // Loop through the input elements
            int x = scanner.nextInt(); // Read an element 'x' from the standard input
            cnt[x]++; // Increment the frequency count of the element 'x' in the array 'cnt'
        }

        ArrayList<Integer> a = new ArrayList<>(); // Initialize an ArrayList 'a' to store the frequency counts

        for (int i = 0; i < cnt.length; ++i) { // Loop through all elements in the array 'cnt'
            if (cnt[i] > 0) // If the frequency count of an element is greater than zero
                a.add(cnt[i]); // Add the frequency count to the ArrayList 'a'
        }

        int ans = 0; // Initialize an integer 'ans' to store the sum of the first 'k' frequency counts

        Collections.sort(a); // Sort the ArrayList 'a' in ascending order

        int m = a.size() - k; // Calculate the index of the last frequency count to be considered

        for (int i = 0; i < m; ++i) { // Loop through the first 'm' frequency counts and add them to the variable 'ans'
            ans += a.get(i);
        }

        System.out.println(ans); // Print the result 'ans' to the standard output
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
