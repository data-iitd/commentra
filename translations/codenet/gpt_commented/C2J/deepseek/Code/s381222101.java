public class TrapezoidArea {
    public static void main(String[] args) {
        // Declare variables to hold the lengths of the two bases (a and b) and the height (h)
        int a, b, h;

        // Read the values of the two bases and the height from user input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        h = scanner.nextInt();

        // Calculate the area of the trapezoid using the formula: Area = ((base1 + base2) * height) / 2
        // and print the result
        System.out.println((a + b) * h / 2);

        // Return 0 to indicate successful completion of the program
    }
}
