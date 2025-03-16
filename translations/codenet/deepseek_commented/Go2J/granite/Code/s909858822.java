
import java.util.Scanner;

public class s909858822{
    public static void main(String[] args) {
        // Declare two integer variables A and B
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        
        // Declare a variable to store the result
        int ans = 0;
        
        // Check if A is between 6 and 12 inclusive
        if (6 <= A && A <= 12) {
            // Calculate the half of B and assign it to ans
            ans = B / 2;
        } else if (12 < A) {
            // Assign B to ans if A is greater than 12
            ans = B;
        }
        
        // Print the value of ans
        System.out.println(ans);
    }
}
