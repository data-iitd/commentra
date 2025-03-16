import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking input for k, n, and w
        String[] input = scanner.nextLine().split(" ");
        int k = Integer.parseInt(input[0]);
        int n = Integer.parseInt(input[1]);
        int w = Integer.parseInt(input[2]);
        
        // Checking if k and w are within the specified range
        if (1 <= k && w <= 1000) {
            // Initializing total to 0
            int total = 0;
            
            // Looping from 1 to w (inclusive)
            for (int i = 1; i <= w; i++) {
                // Multiplying the current iteration number by k and adding to total
                total += i * k;
            }
            
            // Checking if total is greater than n
            if (total > n) {
                // Printing the difference between total and n if total is greater
                System.out.println(total - n);
            } else {
                // Printing 0 if total is not greater than n
                System.out.println(0);
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
