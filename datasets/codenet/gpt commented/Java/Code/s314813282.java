import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Create a Scanner object to read input from the console
        Scanner scan = new Scanner(System.in);
        
        // Read the size of the first array (m) and the second array (n)
        int m = scan.nextInt();
        int n = scan.nextInt();
        
        // Read the initial values x and y
        int x = scan.nextInt();
        int y = scan.nextInt();
        
        // Initialize the first array of size m
        int[] a = new int[m];
        // Populate the first array with user input
        for(int i = 0; i < a.length; i++) {
            a[i] = scan.nextInt();
        }
        
        // Initialize the second array of size n
        int[] b = new int[n];
        // Populate the second array with user input
        for(int i = 0; i < b.length; i++) {
            b[i] = scan.nextInt();
        }
        
        // Calculate the maximum value from the first array and the initial value x
        int x_max = MaxInt(x, a);
        // Calculate the minimum value from the second array and the initial value y
        int y_min = MinInt(y, b);
        
        // Check if a "War" or "No War" situation occurs based on the max and min values
        CheckWar(x_max, y_min);
    }
    
    // Method to find the maximum integer between x and the elements of array a
    static int MaxInt(int x, int[] a) {
        int bignum = x; // Initialize bignum with x
        // Iterate through the array to find the maximum value
        for(int i = 0; i < a.length; i++) {
            bignum = Math.max(bignum, a[i]); // Update bignum if a[i] is greater
        }
        return bignum; // Return the maximum value found
    }
    
    // Method to find the minimum integer between y and the elements of array b
    static int MinInt(int y, int[] b) {
        int smallnum = y; // Initialize smallnum with y
        // Iterate through the array to find the minimum value
        for(int i = 0; i < b.length; i++) {
            smallnum = Math.min(smallnum, b[i]); // Update smallnum if b[i] is smaller
        }
        return smallnum; // Return the minimum value found
    }
    
    // Method to check if a "War" or "No War" situation occurs based on the values of a and b
    static void CheckWar(int a, int b) {
        // If the maximum value from array a is greater than or equal to the minimum value from array b
        if(a >= b) {
            System.out.println("War"); // Print "War"
        } else {
            System.out.println("No War"); // Print "No War"
        }
    }
}
