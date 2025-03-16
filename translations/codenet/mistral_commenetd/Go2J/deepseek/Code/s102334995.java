public class Main {
    public static void main(String[] args) {
        // Declaring two integer variables 'a' and 'b'
        int a, b;

        // Importing Scanner class for input operations
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Reading input values for variables 'a' and 'b' from the standard input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Multiplying the variables 'a' and 'b' and printing the result
        System.out.println(a * b);

        // Multiplying the sum of 'a' and 'b' with 2 and printing the result
        System.out.println((a + b) * 2);
    }
}

