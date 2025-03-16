import java.util.Scanner;

public class Main {
    public static void main(final String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from the input: 'a' and 'b'
        int a = scanner.nextInt(), b = scanner.nextInt();
        
        // Initialize a flag to track if a valid value of 'i' is found
        boolean flag = false;
        
        // Loop through possible values of 'i' from 1 to 100000
        for(int i = 1; i <= 100000; i++) {
            // Check if the calculated values match the input values 'a' and 'b'
            if (Math.floor(1. * i * .08) == a && b == Math.floor(.1 * i)) {
                // If a match is found, print the value of 'i'
                System.out.println(i);
                
                // Set the flag to true indicating a valid 'i' was found
                flag = true;
                
                // Exit the loop as we only need the first valid 'i'
                break;
            }
        }
        
        // If no valid 'i' was found, print -1
        if (!flag) {
            System.out.println(-1);
        }
    }
}
