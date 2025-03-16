public class Main {
    public static void main(String[] args) {
        int x; // Declaring an integer variable x

        java.util.Scanner scanner = new java.util.Scanner(System.in); // Creating a Scanner object to read input
        x = scanner.nextInt(); // Reading an integer value from the user and storing it in variable x

        // The following block of code calculates x raised to the power of 3
        x = x * x * x;

        // Printing the result to the console
        System.out.println(x);
    }
}
