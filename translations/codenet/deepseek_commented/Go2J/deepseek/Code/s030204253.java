import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the value of n from the standard input
        ArrayList<Double> a = new ArrayList<>(); // Create an ArrayList to store the floating-point numbers
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextDouble()); // Read n floating-point numbers from the standard input to populate the ArrayList a
        }
        while (a.size() > 1) { // Enter a loop that continues until only one element remains in the ArrayList a
            Collections.sort(a); // Sort the ArrayList a in ascending order
            ArrayList<Double> na = new ArrayList<>(); // Create a new ArrayList na to store the updated elements
            for (int j = 2; j < a.size(); j++) { // Iterate over the ArrayList a starting from the third element
                na.add(a.get(j)); // Append the elements from a to na, excluding the first two
            }
            double average = (a.get(0) + a.get(1)) / 2; // Calculate the average of the first two elements
            na.add(average); // Append the average to na
            a = na; // Update the ArrayList a with the new ArrayList na
        }
        System.out.println(a.get(0)); // Print the single remaining element in the ArrayList a
    }
}
