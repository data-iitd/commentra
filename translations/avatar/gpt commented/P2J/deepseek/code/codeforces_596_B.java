import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input which represents the number of elements
        int n = scanner.nextInt();
        
        // Read a line of input, split it into individual strings, convert them to integers, and store them in a list
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            r[i] = scanner.nextInt();
        }
        
        // Initialize the answer with the absolute value of the first element in the list
        int ans = Math.abs(r[0]);
        
        // Iterate through the list starting from the second element
        for (int i = 1; i < n; i++) {
            // Add the absolute difference between the current element and the previous element to the answer
            ans += Math.abs(r[i] - r[i - 1]);
        }
        
        // Print the final computed answer
        System.out.println(ans);
    }
}
