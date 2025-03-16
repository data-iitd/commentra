import java.lang.Math.*; // Importing Math library for mathematical operations
import java.util.Scanner; // Importing Scanner class for user input
import java.util.Arrays; // Importing Arrays class for array operations

class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the user
        final Scanner sc = new Scanner(System.in);
        
        // Reading the number of test cases
        int n = sc.nextInt();
        
        // Initializing an array to hold three integers
        int[] a = new int[3]; 
        
        // Looping through each test case
        for (int i = 0; i < n; i++) {
            // Reading three integers from the user
            a[0] = sc.nextInt();
            a[1] = sc.nextInt();
            a[2] = sc.nextInt();
            
            // Sorting the array to ensure the largest number is last
            Arrays.sort(a);	    
            
            // Checking if the numbers form a Pythagorean triplet
            if (Math.pow(a[2], 2) == Math.pow(a[0], 2) + Math.pow(a[1], 2)) 
                System.out.println("YES"); // Output "YES" if they form a right triangle
            else 
                System.out.println("NO"); // Output "NO" if they do not form a right triangle
        }
    }
}
