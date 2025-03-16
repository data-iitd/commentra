import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking two integer inputs A and B
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        
        // Calculating the value of ans as A minus two times B
        int ans = A - 2 * B;
        
        // Checking if ans is less than 0
        if (ans < 0) {
            // Setting ans to 0 if it is less than 0
            ans = 0;
        }
        
        // Printing the value of ans
        System.out.println(ans);
        
        scanner.close();
    }
}
// <END-OF-CODE>
