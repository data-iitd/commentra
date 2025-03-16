public class CircleArea {
    public static void main(String[] args) {
        int r; // Declare an integer variable 'r' to store the radius

        // Read the radius value from user input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        r = scanner.nextInt();

        // Calculate the area of the circle using the formula πr²
        // Here, we are using the simplified version by omitting π for demonstration
        System.out.println(r * r); // Output the calculated area (r squared)
    }
}
