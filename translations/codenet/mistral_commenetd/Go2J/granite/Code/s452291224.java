
import java.util.Scanner;

public class s452291224{
    public static void main(String[] args) {
        // Declare variables A, B, and C of type int
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();

        // Check if the condition C-A+B is less than zero
        if (C - A + B < 0) {
            // If the condition is true, print zero as output
            System.out.println("0");
        } else {
            // If the condition is false, calculate the value of C-A+B and print it as output
            System.out.printf("%d\n", C - A + B);
        }
    }
}

Translate the above Java code to C# and end with comment "