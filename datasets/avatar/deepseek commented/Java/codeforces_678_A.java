import java.util.Scanner; // Step 1: Import the Scanner class from the java.util package.

public class Main { // Step 2: Define the Main class.
    public static void main(String[] args) { // Step 3: Define the main method inside the Main class.
        Scanner scan = new Scanner(System.in); // Step 4: Create a Scanner object to read input from the user.
        
        int n = scan.nextInt(); // Step 5: Read an integer value from the user and store it in the variable n.
        int k = scan.nextInt(); // Step 6: Read another integer value from the user and store it in the variable k.
        
        n++; // Step 7: Increment the value of n by 1.
        
        int z = 0; // Step 8: Initialize a variable z to 0.
        
        if (n % k != 0) { // Step 9: Check if n is not divisible by k.
            z = k - n % k; // If true, calculate the difference between k and the remainder of n divided by k, and store it in z.
        }
        
        System.out.println(n + z); // Step 10: Print the new value of n plus the value of z.
    }
}
