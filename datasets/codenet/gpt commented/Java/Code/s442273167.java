import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the number of pairs of integers
        int n = sc.nextInt();
        
        // Initialize two arrays to store the left and right bounds of the ranges
        int[] l = new int[n];		
        int[] r = new int[n];
        
        // Loop to read the left and right bounds for each range
        for (int i = 0; i < n; i++) {
            l[i] = sc.nextInt(); // Read the left bound
            r[i] = sc.nextInt(); // Read the right bound
        }
        
        // Initialize a variable to hold the total sum of the lengths of the ranges
        int sum = 0;
        
        // Loop to calculate the total length of all ranges
        for (int i = 0; i < n; i++) {
            sum += r[i] - l[i] + 1; // Calculate the length of the current range and add it to the sum
        }
        
        // Output the total sum of the lengths of the ranges
        System.out.println(sum);
    }
}
