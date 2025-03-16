import java.util.*; // Importing the utility package for using Scanner

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the user
        Scanner scn = new Scanner(System.in);
        
        // Reading two integer inputs: n and k
        int n = scn.nextInt(); // n represents the maximum value for req
        int k = scn.nextInt(); // k is the initial value to be decremented
        
        int i = 1; // Initializing i to 1, which will be used to calculate req
        int req = 1; // Initializing req to 1, which represents the current decrement value
        
        // Loop to decrement k until it is no longer possible
        while (k - req >= 0) {
            // Check if k can be decremented by req
            if (k - req >= 0) {
                k = k - req; // Decrement k by req
            } else {
                break; // Exit the loop if k cannot be decremented by req
            }
            
            i++; // Increment i to determine the next req value
            
            // Determine the next req value based on the current value of i
            if (i % n != 0) {
                req = i % n; // If i is not a multiple of n, set req to i % n
            } else {
                req = n; // If i is a multiple of n, set req to n
            }
        }
        
        // Output the final value of k after all possible decrements
        System.out.println(k);
    }
}
