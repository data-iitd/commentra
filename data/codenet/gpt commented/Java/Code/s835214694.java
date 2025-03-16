import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read two integers from the user
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        // Check if 'b' is divisible by 'a'
        if (b % a == 0) {
            // If 'b' is divisible by 'a', print the sum of 'a' and 'b'
            System.out.println(a + b);
        } else {
            // If 'b' is not divisible by 'a', print the difference of 'b' and 'a'
            System.out.println(b - a);
        }
    }
}
