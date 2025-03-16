import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Declare and initialize three integer variables "a", "b", and "c"
        int a, b, c;
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        // Check if the value of "c" is within the range of "a" and "b"
        if (c >= a && c <= b) {
            // If the condition is true, print the string "Yes" to the standard output
            System.out.println("Yes");
        } else {
            // If the condition is false, print the string "No" to the standard output
            System.out.println("No");
        }
    }
}
