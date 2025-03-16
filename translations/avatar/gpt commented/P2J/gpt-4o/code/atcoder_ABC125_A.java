import java.util.Scanner;

public class CookieCollector {
    public static void main(String[] args) {
        // Read input values for 'a', 'b', and 't' from the user
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int t = scanner.nextInt();
        
        // Initialize the cookie count to zero
        int cookie = 0;

        // Set the initial time to 'a'
        double time = a;

        // Loop until the time exceeds 't + 0.5'
        while (time <= t + 0.5) {
            // Add 'b' cookies for each time interval
            cookie += b;
            // Increment the time by 'a' for the next iteration
            time += a;
        }

        // Print the total number of cookies collected
        System.out.println(cookie);
        
        scanner.close();
    }
}
// <END-OF-CODE>
