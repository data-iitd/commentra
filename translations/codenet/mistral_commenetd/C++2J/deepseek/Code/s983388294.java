import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        // Initialize variables
        int n;

        // Create a Scanner object to read input from the standard input stream
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array from the standard input
        System.out.print("Enter the number of elements in the array: ");
        n = scanner.nextInt();

        // Allocate memory for the array and read its elements
        Vector<Integer> a = new Vector<>(n);
        for(int i=0; i<n; i++) {
            System.out.print("Enter element " + (i+1) + ": ");
            a.add(scanner.nextInt());
        }

        // Initialize a counter to keep track of the current element in the array
        int curr = 0;

        // Iterate through the array and increment the counter whenever the current element is one more than the previous one
        for(int i=0; i<n; i++) {
            if(a.get(i) == curr + 1) curr++;
        }

        // Check if the counter is greater than zero, and if so, print the number of elements that are not consecutive
        if(curr > 0) {
            System.out.println("The array has " + (n - curr) + " non-consecutive elements.");
        }

        // If the counter is zero, print -1 to indicate that all elements are not consecutive
        else {
            System.out.println("-1");
        }
    }
}
