public class Main {
    public static void main(String[] args) {
        int a, b, c, d; // Declare four integer variables to hold input values

        // Read four integer values from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();

        // Calculate the product of the differences between the first two and the last two integers
        // This represents the area of a rectangle defined by the points (a, b) and (c, d)
        System.out.println((a - c) * (b - d));
    }
}
