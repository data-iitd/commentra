
public class Main {
    public static void main(String[] args) {
        // Declare two integer variables to hold the input values
        int a, b;

        // Read two integers from the user input
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate and print the product of a and b, and the perimeter of a rectangle with sides a and b
        System.out.println(a * b + " " + 2 * (a + b));
    }
}

