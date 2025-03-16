import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking two integer inputs, `a` and `b`.
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        int hole = 1;
        int i = 0;
        // Initializing `hole` to 1 and `i` to 0.
        boolean check = true;
        // Setting a boolean variable `check` to `true`.
        
        while (check) {
            // The `while` loop runs as long as `check` is `true`.
            if (hole >= b) {
                // Checking if `hole` is greater than or equal to `b`.
                check = false;
                // If so, set `check` to `false` to exit the loop.
            } else {
                hole = a * (i + 1) - i;
                // If `hole` is less than `b`, update `hole` to `a * (i + 1) - i`.
                i++;
                // Increment `i` by 1.
            }
        }
        
        System.out.println(i);
        // Finally, print the value of `i` after the loop exits.
        
        scanner.close();
    }
}
// <END-OF-CODE>
