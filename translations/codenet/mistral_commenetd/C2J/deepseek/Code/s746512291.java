public class CubeCalculator {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        // Create a Scanner object to read input from the standard input stream

        int x = scanner.nextInt();
        // Read an integer value from the standard input and store it in variable x

        System.out.println(x * x * x);
        // Print the result of x cubed to the standard output
    }
}
