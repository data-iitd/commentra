import java.util.*;
import java.lang.*;

class Main {
    public static void main(String args[]) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the number of test cases (or elements) from the input
        int t = sc.nextInt();
        
        // Initialize an array to count occurrences of each number, with size t+1
        int[] count = new int[t + 1];
        
        // Loop through the range from 2 to t (inclusive) to read the numbers
        for (int i = 2; i < t + 1; i++) {
            // Increment the count for the number read from input
            count[sc.nextInt()]++;
        }
        
        // Loop through the count array to print the occurrences of each number from 1 to t
        for (int i = 1; i < t + 1; i++) {
            // Print the count of occurrences for the current number
            System.out.println(count[i]);
        }
    }
}
