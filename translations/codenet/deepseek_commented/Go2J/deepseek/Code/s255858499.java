public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Reading the first integer input
        int a = scanner.nextInt();
        // Reading the second integer input
        int b = scanner.nextInt();

        // Checking if the product of a and b is odd or even and printing the result
        if (a * b % 2 != 0) {
            System.out.println("Odd");
        } else {
            System.out.println("Even");
        }
    }
}
