// Import necessary classes
import java.math.BigInteger;
import java.nio.charset.IllegalCharsetNameException;
import java.util.ArrayList;
import java.util.Scanner;

// Create the Main class and define the main method
public class Main {
    public static void main(String[] args) {
        // Initialize a Scanner object to read input
        Scanner sc = new Scanner(System.in);

        // Declare and initialize variables
        int n, a, b;
        n = sc.nextInt(); // Read the number of test cases
        a = sc.nextInt(); // Read the number of elements in the first list
        b = sc.nextInt(); // Read the number of elements in the second list

        // Create ArrayList objects to store the lists
        ArrayList<Integer> list1 = new ArrayList<>();
        ArrayList<Integer> list2 = new ArrayList<>();

        // Read and store the elements of the first and second lists
        for (int i = 0; i < a; i++) {
            list1.add(sc.nextInt()); // Read and add an element to list1
        }
        for (int i = 0; i < b; i++) {
            list2.add(sc.nextInt()); // Read and add an element to list2
        }

        // Iterate through the input array and print the corresponding number based on the presence of the element in list1
        for (int i = 0; i < n; i++) {
            if (list1.contains(i + 1)) { // Check if the current input element is present in list1
                System.out.print(1 + " "); // If present, print 1
            } else {
                System.out.print(2 + " "); // If not present, print 2
            }
        }

        // Close the Scanner object
        sc.close();
    }
}