import java.util.*; // Importing the necessary package for Scanner and ArrayList

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in); // Creating a Scanner object to read input
        int n = s.nextInt(); // Reading the size of the array
        int[] a = new int[n]; // Declaring and initializing the array 'a' of size 'n'
        Arrays.setAll(a, i -> s.nextInt()); // Filling the array 'a' with 'n' integers from input

        ArrayList<String> r = new ArrayList<>(); // Declaring an ArrayList to store the operations
        int m = 0; // Initializing the index of the maximum absolute value element

        // Finding the index of the element with the maximum absolute value in the array 'a'
        for (int i = 1; i < n; ++i) {
            if (Math.abs(a[m]) < Math.abs(a[i])) {
                m = i;
            }
        }

        // Finding pairs of indices where one element is non-negative and the other is negative
        for (int i = 0; i < n; ++i) {
            if (a[m] >= 0 ^ a[i] >= 0) { // Using XOR to check if one is non-negative and the other is negative
                r.add((m + 1) + " " + (i + 1)); // Adding the operation to the ArrayList 'r'
            }
        }

        // Generating operations based on whether the maximum absolute value element is non-negative or negative
        if (a[m] >= 0) {
            for (int i = 1; i < n; ++i) {
                r.add((i + 1) + " " + (i + 2)); // Adding the operation to the ArrayList 'r'
            }
        } else {
            for (int i = n; i > 1; --i) {
                r.add((i) + " " + (i - 1)); // Adding the operation to the ArrayList 'r'
            }
        }

        // Printing the number of operations and the operations themselves
        System.out.println(r.size());
        r.forEach(System.out::println);
    }
}
