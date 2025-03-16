import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static String s() {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read an input line (not used in the logic)
        scanner.nextLine();
        
        // Read a line of integers, split by spaces, and convert them to an array of integers
        String[] input = scanner.nextLine().split(" ");
        int[] a = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            a[i] = Integer.parseInt(input[i]);
        }
        
        // Sort the array of integers in ascending order
        Arrays.sort(a);
        
        // Iterate through the sorted array starting from the second element
        for (int i = 1; i < a.length; i++) {
            // Check if the current element is different from the previous one
            // and if it is less than double the previous element
            if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
                // If the condition is met, return "YES"
                return "YES";
            }
        }
        
        // If no such pair is found, return "NO"
        return "NO";
    }

    public static void main(String[] args) {
        // Call the function and print the result
        System.out.println(s());
    }
}

// <END-OF-CODE>
