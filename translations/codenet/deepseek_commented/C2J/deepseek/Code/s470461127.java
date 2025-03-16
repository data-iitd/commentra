public class RectanglePerimeter {
    public static void main(String[] args) {
        int x, y;
        x = 0; y = 0;

        // Read two integers from the standard input and store them in x and y
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        x = scanner.nextInt();
        y = scanner.nextInt();

        // Calculate the product of x and y
        // Also, calculate the perimeter of a rectangle with sides x and y
        System.out.println(x * y + " " + (2 * x) + (2 * y));
    }
}
