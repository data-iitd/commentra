import java.util.ArrayList; // Importing ArrayList for dynamic arrays
import java.util.Scanner; // Importing Scanner for input
import java.lang.Math; // Importing Math for mathematical operations

public class Main {
    // Defining a constant INF for a very large number
    static final int INF = (int) 1e9 + 5;

    public static void main(String[] args) {
        // Creating a Scanner object to read input
        Scanner sc = new Scanner(System.in);
        int n; // Declaring variable n to store the number of elements
        n = sc.nextInt(); // Reading the integer value of n

        // Initializing two ArrayList objects to store the elements
        ArrayList<Integer> a = new ArrayList<>();
        ArrayList<Integer> b = new ArrayList<>();

        // Initializing variables to track the minimum and maximum values
        int left = INF, right = 0;

        // Looping through n elements to read and update the lists and variables
        for (int i = 0; i < n; i++) {
            a.add(sc.nextInt()); // Reading element into list a
            b.add(sc.nextInt()); // Reading element into list b
            left = Math.min(left, a.get(i)); // Updating left with the minimum value
            right = Math.max(right, b.get(i)); // Updating right with the maximum value
        }

        // Looping through the lists to find the target element
        for (int i = 0; i < n; i++) {
            if (left == a.get(i) && right == b.get(i)) {
                System.out.println(i + 1); // Printing the 1-based index of the target element
                return; // Returning from the method after finding the target
            }
        }

        // If no such element is found, print -1
        System.out.println(-1);
    }
}
