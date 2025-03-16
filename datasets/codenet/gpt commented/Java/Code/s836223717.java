import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read an integer input 'n' which represents the position in the sequence
        int n = sc.nextInt();
        
        // Initialize an array 'ryuka' to store the sequence values, with size n + 1
        long[] ryuka = new long[n + 1];
        
        // Set the base cases for the sequence
        ryuka[0] = 2; // The first value in the sequence
        ryuka[1] = 1; // The second value in the sequence
        
        // Calculate the sequence values from index 2 to n using the recurrence relation
        for (int i = 2; i < n + 1; i++) {
            ryuka[i] = ryuka[i - 1] + ryuka[i - 2]; // Each value is the sum of the two preceding values
        }
        
        // Output the nth value of the sequence
        System.out.println(ryuka[n]);
    }
}
