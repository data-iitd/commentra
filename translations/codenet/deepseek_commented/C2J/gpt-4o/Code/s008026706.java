import java.util.Scanner;

public class Rectangle {
    public static void main(String[] args) {
        int a, b, x, y;

        // Step 4: Read two integers from the user.
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Step 5: Calculate the perimeter of a rectangle using the formula 2*a + 2*b and store it in x.
        x = 2 * a + 2 * b;

        // Step 6: Calculate the area of a rectangle using the formula a*b and store it in y.
        y = a * b;

        // Step 7: Print the area and perimeter.
        System.out.println(y + " " + x);

        // Step 8: Return 0 to indicate successful execution.
        scanner.close();
    }
}

// <END-OF-CODE>
