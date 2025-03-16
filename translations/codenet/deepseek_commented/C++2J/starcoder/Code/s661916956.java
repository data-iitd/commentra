import java.util.*;
public class Main {
    public static void main(String[] args) {
        // Read three integers from the standard input
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        // Sort the integers in ascending order
        if (a > b) {
            int temp = a;
            a = b;
            b = temp; // Swap a and b if a is greater than b
        }
        if (b > c) {
            int temp = b;
            b = c;
            c = temp; // Swap b and c if b is greater than c
        }
        if (a > b) {
            int temp = a;
            a = b;
            b = temp; // Swap a and b again to ensure a is not greater than b after the second swap
        }

        // Print the sorted integers
        System.out.println(a + " " + b + " " + c);
    }
}
