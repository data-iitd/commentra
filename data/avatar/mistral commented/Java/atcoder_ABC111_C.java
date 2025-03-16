
import java.util.Arrays; // Importing Arrays utility class for sorting arrays
import java.util.Collections; // Importing Collections utility class for sorting collections in reverse order
import java.util.Scanner; // Importing Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the standard input stream
        int n; // Declaring an integer variable 'n' to store the number of elements in the input array

        // Reading the number of elements 'n' from the standard input stream
        n = Integer.parseInt(sc.next());

        int[] v; // Declaring an integer array 'v' of size 100010 to store the input elements

        // Allocating memory for the integer array 'v' of size 100010
        v = new int[100010];

        // Reading the elements of the array 'v' from the standard input stream
        for (int i = 0; i < n; i++) {
            v[i] = Integer.parseInt(sc.next());
        }

        Integer[] vo = new Integer[100010]; // Declaring an Integer array 'vo' of size 100010 to store the count of occurrences of each unique value in the odd indexed elements of the array 'v'
        Integer[] ve = new Integer[100010]; // Declaring an Integer array 've' of size 100010 to store the count of occurrences of each unique value in the even indexed elements of the array 'v'
        Integer[] vt = new Integer[100010]; // Declaring an Integer array 'vt' of size 100010 to store the total count of occurrences of each unique value in the array 'v'

        // Initializing all the elements of the arrays 'vo', 've', and 'vt' to zero
        Arrays.fill(vo, 0);
        Arrays.fill(ve, 0);
        Arrays.fill(vt, 0);

        // Counting the occurrences of each unique value in the odd indexed elements of the array 'v' and updating the 'vo' array accordingly
        for (int i = 0; i < n; i += 2) {
            int currentElement = v[i];
            vo[currentElement]++;
        }

        // Counting the occurrences of each unique value in the even indexed elements of the array 'v' and updating the 've' array accordingly
        for (int i = 1; i < n; i += 2) {
            int currentElement = v[i];
            ve[currentElement]++;
        }

        // Sorting the arrays 'vo', 've', and 'vt' in descending order
        Arrays.sort(vo, Collections.reverseOrder());
        Arrays.sort(ve, Collections.reverseOrder());
        Arrays.sort(vt, Collections.reverseOrder());

        int ans = 0; // Declaring an integer variable 'ans' to store the answer

        // Checking if the sum of the first elements of the arrays 'vo' and 've' is equal to the first element of the array 'vt'
        if (vo[0] + ve[0] == vt[0]) {
            // Calculating the answer as the minimum of the difference between the total number of elements and the sum of the counts of the first elements of the arrays 'vo' and 've'
            ans = Math.min(n - vo[0] - ve[1], n - vo[1] - ve[0]);
        } else {
            // Calculating the answer as the difference between the count of the first element of the array 'vo' and the count of the first element of the array 've'
            ans = n - vo[0] - ve[0];
        }

        // Printing the answer to the standard output stream
        System.out.println(ans);

        sc.close(); // Closing the Scanner object to free up the system resources
    }
}

