import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input for the number of elements
        int n = scanner.nextInt();
        
        // Read the line of input, split it into individual integers, and store them in an array
        int[] l1 = new int[n];
        for (int i = 0; i < n; i++) {
            l1[i] = scanner.nextInt();
        }
        
        // Sort the array of integers in ascending order
        Arrays.sort(l1);
        
        // Assign the maximum value in the array to variable 'a'
        int a = l1[n - 1];
        
        // Assign the minimum value in the array to variable 'b'
        int b = l1[0];
        
        // Check if the maximum and minimum values are the same
        if (a == b) {
            // If they are the same, the difference is zero and the number of pairs is n choose 2
            System.out.println(a - b + " " + (n * (n - 1) / 2));
        } else {
            // Count occurrences of the maximum value 'a' in the array
            int ac = 0;
            for (int value : l1) {
                if (value == a) {
                    ac++;
                }
            }
            
            // Count occurrences of the minimum value 'b' in the array
            int bc = 0;
            for (int value : l1) {
                if (value == b) {
                    bc++;
                }
            }
            
            // Calculate the difference between the maximum and minimum values, and the product of their counts
            System.out.println(a - b + " " + (ac * bc));
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
