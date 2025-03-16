import java.util.Scanner;

public class RectangleArea {
    public static void main(String[] args) {
        // Declare four integer variables: h, w, hh, and ww.
        int h, w, hh, ww;

        // Create a Scanner object to read input from the standard input.
        Scanner scanner = new Scanner(System.in);

        // Read four integers from the standard input and assign them to the variables h, w, hh, and ww respectively.
        h = scanner.nextInt();
        w = scanner.nextInt();
        hh = scanner.nextInt();
        ww = scanner.nextInt();

        // Calculate the difference between h and hh and the difference between w and ww.
        int difference_h = h - hh;
        int difference_w = w - ww;

        // Output the product of the differences to the standard output.
        System.out.println("The area of the rectangle is: " + (difference_h * difference_w));

        // Close the scanner to prevent resource leaks.
        scanner.close();
    }
}

// <END-OF-CODE>
