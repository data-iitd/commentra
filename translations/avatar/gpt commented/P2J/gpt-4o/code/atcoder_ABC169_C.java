import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a scanner for input
        Scanner scanner = new Scanner(System.in);

        // Read two values from input: one as an integer and the other as a float in string format
        String sa = scanner.next();
        String sb = scanner.next();

        // Convert the first value to an integer
        int a = Integer.parseInt(sa);

        // Convert the second value to an integer representing cents (by multiplying by 100)
        int b = (int) (Double.parseDouble(sb) * 100 + 0.1);

        // Calculate and print the product of a and b, divided by 100 to get the final result
        System.out.println(a * b / 100);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
