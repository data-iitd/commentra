import java.util.Scanner;

public class CookieCounter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking three inputs from the user: a, b, and t
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int t = scanner.nextInt();
        
        // Initializing the cookie count to 0
        int cookie = 0;
        
        // Setting the initial time to the value of a
        double time = a;
        
        // The loop continues as long as time is less than or equal to t + 0.5
        while (time <= t + 0.5) {
            // Incrementing the cookie count by b
            cookie += b;
            // Incrementing the time by a
            time += a;
        }
        
        // Printing the final cookie count after the loop finishes
        System.out.println(cookie);
        
        scanner.close();
    }
}
// <END-OF-CODE>
