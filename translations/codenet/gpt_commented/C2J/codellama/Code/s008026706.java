
public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the dimensions and results
        int a, b, x, y;

        // Read two integer inputs from the user (representing dimensions)
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();

        // Calculate the perimeter of the rectangle (2 * (length + width))
        x = 2 * (a + b);

        // Calculate the area of the rectangle (length * width)
        y = a * b;

        // Output the area and perimeter
        System.out.println(y + " " + x);
    }
}

