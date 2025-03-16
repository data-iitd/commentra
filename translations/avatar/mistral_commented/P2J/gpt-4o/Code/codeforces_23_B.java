import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take an integer input from the user and assign it to the variable n
        int n = scanner.nextInt();
        
        // Iterate n times
        for (int i = 0; i < n; i++) {
            // Take an integer input from the user and assign it to the variable a
            int a = scanner.nextInt();
            
            // Check if a is less than 2
            if (a < 2) {
                // If a is less than 2, print 0
                System.out.println(0);
                
                // Move to the next iteration of the loop
                continue;
            }
            
            // If a is not less than 2, check if it is greater than or equal to 2
            if (a >= 2) {
                // If a is greater than or equal to 2, print a - 2
                System.out.println(a - 2);
            }
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
