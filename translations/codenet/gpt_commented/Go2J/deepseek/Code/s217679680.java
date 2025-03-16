import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read an array of integers from standard input
        List<Integer> arr = scanArrayInt(scanner);
        // Assign the first two elements of the array to variables a and b
        int a = arr.get(0);
        int b = arr.get(1);
        // Initialize the number of taps needed to 0
        int tap = 0;
        // Initialize the consent variable to 1 (the starting point)
        int consent = 1;
        
        // Loop until the consent value is less than b
        while (consent < b) {
            // Update consent by adding (a - 1) to it
            consent = consent + a - 1;
            // Increment the tap count
            tap++;
        }
        
        // Print the total number of taps needed
        System.out.println(tap);
    }

    // Function to scan an array of integers from standard input
    public static List<Integer> scanArrayInt(Scanner scanner) {
        // Initialize an empty list to hold the integers
        List<Integer> ret = new ArrayList<>();
        // Read a line from standard input
        String[] input = scanner.nextLine().split(" ");
        // Convert each string to an integer and add to the list
        for (String s : input) {
            int i = Integer.parseInt(s); // Convert string to integer
            ret.add(i); // Add the integer to the list
        }
        // Return the list of integers
        return ret;
    }
}
