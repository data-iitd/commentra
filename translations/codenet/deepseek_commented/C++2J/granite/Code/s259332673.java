
import java.util.Scanner;

public class s259332673{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Declare integer variables to store input values
        int h1 = scanner.nextInt();
        int m1 = scanner.nextInt();
        int h2 = scanner.nextInt();
        int m2 = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Calculate the difference in minutes between h2:m2 and h1:m1
        int ans = (h2 * 60 + m2) - (h1 * 60 + m1);
        
        // Print the result of subtracting k from the calculated difference
        System.out.println(ans - k);
        
        scanner.close();
    }
}
