import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Initialize a counter variable
        int i = 0;
        
        // Loop to read up to 5 integers from the user
        for (i = 1; i <= 5; i++) {
            // Read an integer input from the user
            int n = sc.nextInt();
            
            // Check if the input number is zero
            if (n == 0) {
                // Exit the loop if the input is zero
                break;
            }
        }
        
        // Print the number of inputs read before breaking the loop
        System.out.println(i);
    }
}
