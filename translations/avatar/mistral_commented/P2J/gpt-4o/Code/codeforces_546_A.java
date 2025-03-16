import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking three integers as input from the user
        String[] input = scanner.nextLine().split(" ");
        int k = Integer.parseInt(input[0]);
        int n = Integer.parseInt(input[1]);
        int w = Integer.parseInt(input[2]);

        // Input validation
        if (1 <= k && w <= 1000) {
            int total = 0; // Initializing the variable 'total' to zero
            
            // Iterating from 1 to w (inclusive)
            for (int i = 1; i <= w; i++) {
                total += i * k; // Adding the product of k and the current index to the total variable
            }

            // Checking if the total is greater than n or not
            if (total > n) {
                System.out.println(total - n); // If yes, printing the difference between total and n
            } else {
                System.out.println(0); // If no, printing zero
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
