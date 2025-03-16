import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize variables a, b, and c with user input
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();

        // Check if a is greater than b and swap if necessary
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        // Check if b is greater than c and swap if necessary
        if (b > c) {
            int temp = b;
            b = c;
            c = temp;
        }

        // Check if a is greater than b again and swap if necessary
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        // Print the sorted values of a, b, and c
        System.out.println(a + " " + b + " " + c);
    }
}

// <END-OF-CODE>
