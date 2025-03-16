import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking three integer inputs and assigning them to variables t, s, and q
        int t = scanner.nextInt();
        int s = scanner.nextInt();
        int q = scanner.nextInt();
        
        // Initializing the variable ans to 0
        int ans = 0;
        
        // Starting a while loop that continues as long as s is less than t
        while (s < t) {
            // Multiplying s by q
            s *= q;
            // Incrementing ans by 1
            ans += 1;
        }
        
        // Printing the final value of ans after the loop completes
        System.out.println(ans);
        
        scanner.close();
    }
}
// <END-OF-CODE>
