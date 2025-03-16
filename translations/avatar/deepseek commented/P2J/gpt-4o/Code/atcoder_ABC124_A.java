import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking two integer inputs, `a` and `b`, separated by spaces
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Initializing a variable `c` to 0
        int c = 0;
        
        // The loop runs twice
        for (int i = 0; i < 2; i++) {
            // Adding the maximum of `a` and `b` to `c`
            c += Math.max(a, b);
            // Checking if `a` is greater than or equal to `b`
            if (a >= b) {
                // Decrementing `a` by 1 if the condition is true
                a -= 1;
            } else {
                // Decrementing `b` by 1 if the condition is false
                b -= 1;
            }
        }
        
        // Printing the value of `c` after the loop completes
        System.out.println(c);
        
        scanner.close();
    }
}
// <END-OF-CODE>
