import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements 'n'
        int n = scanner.nextInt();
        
        // Declare an ArrayList 'a' to store the elements
        ArrayList<Long> a = new ArrayList<>(n);
        
        // Read the elements of the ArrayList 'a'
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextLong()); // Read the 'i'-th element of the ArrayList 'a'
        }
        
        // Create a copy of the ArrayList 'a' named 'abs_a' to store the absolute values of its elements
        ArrayList<Long> abs_a = new ArrayList<>(a);
        
        // Iterate through each element of the ArrayList 'abs_a' and make it positive if it's negative
        for (int i = 0; i < n; i++) {
            if (abs_a.get(i) < 0) { // Check if the current element is negative
                abs_a.set(i, -abs_a.get(i)); // Make it positive by negating it
            }
        }
        
        // Initialize the variables 'ans' and 'min' with zero and the first element of 'abs_a' respectively
        long ans = 0, min = abs_a.get(0);
        
        // Iterate through each element of the ArrayList 'abs_a' and update the variables 'ans' and 'min' accordingly
        for (long e : abs_a) {
            ans += e; // Add the current element to the variable 'ans'
            if (min > e) { // Check if the current element is smaller than the current minimum
                min = e; // Update the minimum if it is
            }
        }
        
        // Initialize the variable 'num_negative' with zero and count the number of negative elements in the ArrayList 'a'
        int num_negative = 0;
        for (long e : a) {
            if (e < 0) { // Check if the current element is negative
                num_negative++; // Increment the counter if it is
            }
        }
        
        // Check if the number of negative elements is odd or even and update the variable 'ans' accordingly
        if (num_negative % 2 != 0) {
            ans -= min * 2; // Subtract twice the minimum if the number of negative elements is odd
        }
        
        // Print the final answer 'ans' to the standard output
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
