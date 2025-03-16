
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the number of pairs
        int n = sc.nextInt();
        
        // Initialize arrays to store the pairs (l[i], r[i])
        int[] l = new int[n];        
        int[] r = new int[n];
        
        // Read the pairs from the user and store them in the arrays
        for (int i = 0; i < n; i++) {
            l[i] = sc.nextInt();
            r[i] = sc.nextInt();
        }
        
        // Initialize sum to store the total length of intervals
        int sum = 0;
        
        // Calculate the sum of the lengths of the intervals defined by the pairs
        for (int i = 0; i < n; i++) {
            sum += r[i] - l[i] + 1;
        }
        
        // Print the calculated sum
        System.out.println(sum);
    }
}

