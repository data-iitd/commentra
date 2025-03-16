public class Main {
    public static void main(String[] args) {
        // Step 1: Read input values
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();

        // Step 2: Perform calculations
        int area = (a - c) * (b - d); // Calculate the area of the rectangle using the given coordinates

        // Step 3: Output the result
        System.out.println(area); // Print the calculated area to the console
    }
}
